#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class AlphaChecker {
public:
    int getResult(string input1, string input2) {
        //CHECK VALIDITY
        if(false == CheckValidString(input1)) return 0;
        if(false == CheckValidString(input2)) return 0;

        
        string min_str, max_str;

        if (input1.length() < input2.length()) {
            min_str = input1;
            max_str = input2;
        }
        else
        {
            min_str = input2;
            max_str = input1;
        }

        int gap = max_str.length() - min_str.length();

        int total_length = min_str.length() + gap;

        int total_cnt = 0;
        int same_cnt = 0;

        for(int i=0; i< max_str.length(); i++)
        {
            int position = max_str[i] - 'A';
            alphabet[position] = true;
            total_cnt++;
        }

        for (int i = 0; i < min_str.length(); i++)
        {
            int position = min_str[i] - 'A';

            if (alphabet[position] == true) {
                same_cnt++;
            }
            else {
                total_cnt++;
            }            
        }
       
        double score = (double)same_cnt / (double)total_cnt;
        
        score *= MAX_SCORE;
        return (int)score;
    }

private:
    const int MAX_SCORE = 40;
    bool alphabet[26] = {};
    bool CheckValidString(std::string& str)
    {

        for (char ch : str)
        {
            if ((ch < 'A') || (ch > 'Z')) {
                return false;
            }

        }

        return true;
    }
};

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