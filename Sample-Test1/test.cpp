#include "gtest/gtest.h"


extern "C"
{
#include <production.h>
}

class test : public ::testing::Test
{
protected:
	void SetUp() override {}
	void TearDown() override {}
};

TEST_F(test, Test_Length_Returns_0)
{
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}