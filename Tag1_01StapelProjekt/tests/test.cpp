//
// Created by JoachimWagner on 30.12.2023.
//
#include "gtest/gtest.h"
#include "gmock/gmock.h"

TEST(TestCaseName, TestName) {
    EXPECT_EQ(2, 1);
    //ASSERT_EQ(2, 1);
    EXPECT_THAT(false, testing::IsFalse());
}
