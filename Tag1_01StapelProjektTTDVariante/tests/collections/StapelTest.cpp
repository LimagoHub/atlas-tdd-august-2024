//
// Created by JoachimWagner on 19.08.2024.
//

#include "StapelTest.h"
TEST_F(StapelTest, BlaBlupp) {

    EXPECT_TRUE(objectUnderTest.isEmpty());
}

TEST_F(StapelTest, Tataa) {

    objectUnderTest.push(1);
    EXPECT_FALSE(objectUnderTest.isEmpty());
}