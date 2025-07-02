#include "gmock/gmock.h"
#include "similaritychecker.cpp"

TEST(TS, LengthCheck_Same) {
	string input1 = "ABCD";
	string input2 = "DCBA";

	int score = 0;

	SimChecker checker;

	score = checker.getLengthSocre(input1, input2);

    EXPECT_EQ(60, score);
}

TEST(TS, LengthCheck_Diff1) {
	string input1 = "ABCDE";
	string input2 = "DCBA";

	int score = 0;

	SimChecker checker;

	score = checker.getLengthSocre(input1, input2);

	EXPECT_EQ(45, score);
}

TEST(TS, LengthCheck_Diff2) {
	string input1 = "ABCD";
	string input2 = "DCBADD";

	int score = 0;

	SimChecker checker;

	score = checker.getLengthSocre(input1, input2);

	EXPECT_EQ(30, score);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}