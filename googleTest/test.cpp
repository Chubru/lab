#include "pch.h"
#include "Lab.cpp"


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(checkLetterTest, negativeInput) {
	for (int i = -128 ; i < 0; i++) {
		ASSERT_EQ(checkLetter(i), 0);
	}
}
TEST(checkLetterTest, from_0_to_A_Input) {
	for (int i = 0; i < 'A'; i++) {
		ASSERT_EQ(checkLetter(i), 0);
	}
	checkLetter(' ');
}
TEST(checkLetterTest, from_A_to_Z_Input) {
	for (int i = 'A'; i <= 'Z'; i++) {
		ASSERT_EQ(checkLetter(i), 2);
	}
}
TEST(checkLetterTest, from_Z_to_a_Input) {
	for (int i = 'Z'+1; i < 'a'; i++) {
		ASSERT_EQ(checkLetter(i), 0);
	}
}
TEST(checkLetterTest, from_a_to_z_Input) {
	for (int i = 'a'; i <= 'z'; i++) {
		ASSERT_EQ(checkLetter(i), 1);
	}
}
TEST(checkLetterTest, positivInput) {
	for (int i = 'z'+1; i <= 127; i++) {
		ASSERT_EQ(checkLetter(i), 0);
	}
}