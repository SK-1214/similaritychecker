#include "gmock/gmock.h"
#include "similaritychecker.cpp"

using namespace testing;

class LengthFixture : public Test {
public:
	void diag(int expected, string input1, string input2) {
		int ret = app.getResult(input1, input2);
		EXPECT_EQ(expected, ret);
	}

	LengthChecker app;
};

TEST_F(LengthFixture, LengthCheck_Same) {
	diag(60, "ABC", "UEI");
}

TEST_F(LengthFixture, LengthCheck_Diff1) {
	diag(45, "ABCDE", "ADBD");
}

TEST_F(LengthFixture, LengthCheck_Diff2) {
	diag(30, "ABCE", "ADBDDD");
}

TEST_F(LengthFixture, LengthCheck_Diff3) {
	diag(0, "ABCE", "ABCEABCE");
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}