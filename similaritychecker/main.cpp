#include "gmock/gmock.h"
#include "similaritychecker.cpp"

TEST(TS, LengthCheck) {
	string input1 = "ABCD";
	string input2 = "DCBA";

	int score = 0;

	SimChecker checker;

	score = checker.getLengthSocre(input1, input2);

    EXPECT_EQ(60, score);
}
int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}