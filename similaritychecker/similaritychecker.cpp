#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class LengthChecker {
public:
    int getResult(string input1, string input2) {

        int A = std::max(input1.length(), input2.length());
        int B = std::min(input1.length(), input2.length());

        if (isSameLength(A, B)) return MAX_LENGTH_POINT;
        if (isDoubleLength(A, B)) return MIN_LENGTH_POINT;
        return getPartialLengthPoint(A, B);
    }

private:
    int getPartialLengthPoint(int A, int B) {
        int Gap = A - B;
        return MAX_LENGTH_POINT - MAX_LENGTH_POINT * Gap / B;
    }

    bool isSameLength(int A, int B) {
        return A == B;
    }

    bool isDoubleLength(int A, int B) {
        return A >= B * 2;
    }

    static const int MAX_LENGTH_POINT = 60;
    static const int MIN_LENGTH_POINT = 0;

};