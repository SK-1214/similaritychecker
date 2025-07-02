#include <string>
#include <vector>

using std::string;
using std::vector;

class SimChecker {
public:
	int getLengthSocre(string input1, string input2) {
		int len1 = input1.length();
		int len2 = input2.length();
		int gap=0;
		int shortest=0;
	

		if (len1 > len2) {
			gap = len1 - len2;
			shortest = len2;
		}
		else if(len1 < len2){
			gap = len2 - len1;
			shortest = len1;
		}
		else// len1 == len2
		{
			return 60;
		}

		double score = (double) gap/(double)shortest;
		score = 1 * (1- score)*60;
		return (int)score;
		
	}
};