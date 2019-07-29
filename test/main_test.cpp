/*
 * main_test.cpp
 *
 *  Created on: 29-Jul-2019
 *      Author: rajesh
 */


#include <gtest/gtest.h>

TEST(maintest, assert)
{
    ASSERT_EQ(1,1);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

