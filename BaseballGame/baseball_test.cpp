#include "gmock/gmock.h"
#include "baseball.cpp"
#include "baseball_test.h"

TEST(Baseball, ThrowExceptionWhenInputLengthIsUnmatched)
{
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}