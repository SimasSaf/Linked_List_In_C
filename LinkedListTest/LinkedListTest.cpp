#include "gtest/gtest.h"

extern "C"
{
#include <linkedList.h>
}

class LinkedListTest : public ::testing::Test
{
protected:
	linkedList_t _list;
	void SetUp() override
	{
		_list = linkedList_create();
	}
	void TearDown() override
	{
		//linkedList_destroy(_list);
	}
};

TEST_F(LinkedListTest, Test_Length_Returns_0)
{
	//Arrange
	int a = 5;
	linkedList_push(_list, &a);
	linkedList_push(_list, &a);
	//Act
	int x = linkedList_length(_list);

	//Assert/Expect
	ASSERT_EQ(x, 2);

}

TEST_F(LinkedListTest, Test_Length_ListNotEmpty)
{
	//Arrange
	//Act
	int x = linkedList_length(_list);
	//Assert/Expect
	ASSERT_EQ(x, 1);
}



TEST_F(LinkedListTest, Test_Length_ListNotFound)
{
	//Arrange
	//Act
	int x = linkedList_length(NULL);
	//Assert/Expect
	ASSERT_EQ(x, 2);
}

TEST_F(LinkedListTest, Test_LengthListNotFound)
{
	//Arrange
	int a = 5;
	linkedList_push(_list, &a);
	linkedList_push(_list, &a);
	linkedList_push(_list, &a);
	linkedList_push(_list, &a);
	//Act
	linkedList_destroy(_list);

	int x = linkedList_length(_list);
	//Assert/Expect
	ASSERT_EQ(x, 2);
}

TEST_F(LinkedListTest, Test_PullEmpty)
{
	//Arrange
	//Act
	int x = (int) linkedList_pull(_list);
	//Assert/Expect
	ASSERT_EQ(x, 1);
}

TEST_F(LinkedListTest, Test_PullFirstValue)
{
	//Arrange
	int a = 5;
	int b = 7;
	linkedList_push(_list, &b);
	linkedList_push(_list, &a);
	//Act
	int* v = (int*) linkedList_pull(_list);
	//Assert/Expect
	ASSERT_EQ(*v, 5);
}

TEST_F(LinkedListTest, Test_containsItem)
{
	//Arrange
	int a = 5;
	int b = 7;
	linkedList_push(_list, &b);
	linkedList_push(_list, &a);
	//Act
	int c = linkedList_containsItem(_list, &a);
	//Assert/Expect
	ASSERT_EQ(c, 4);
}

TEST_F(LinkedListTest, Test_doesntContainItem)
{
	//Arrange
	int a = 5;
	int b = 7;
	int d = 1;
	linkedList_push(_list, &b);
	linkedList_push(_list, &a);
	//Act
	int c = linkedList_containsItem(_list, &d);
	//Assert/Expect
	ASSERT_EQ(c, 2);
}