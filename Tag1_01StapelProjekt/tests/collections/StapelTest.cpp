//
// Created by JoachimWagner on 19.08.2024.
//

#include "StapelTest.h"

TEST_F(StapelTest, isEmpty__emptyStack__returnsTrue) {
    // Arrange


    // Action

    auto result = objectUnderTest.isEmpty();

    // Assertion
    EXPECT_TRUE(result);

}

TEST_F(StapelTest, isEmpty__NotEmptyStack__returnsFalse) {

    auto const validValue = 1;
    // Arrange

    objectUnderTest.push(validValue);
    // Action

    auto result = objectUnderTest.isEmpty();

    // Assertion
    EXPECT_FALSE(result);

}

TEST_F(StapelTest, push__fillUpToMaximum__noExceptionIsThrown) {
    auto const validValue = 1;
    fillUpToLimitWithoutException();
}

TEST_F(StapelTest, push__Overflow__StapelExceptionIsThrown) {
    // Arrange

    const int validValue = 10;

    fillUpToLimitWithoutException();

    // Act + Assertion
    EXPECT_THROW(objectUnderTest.push(validValue), StapelException);

}

TEST_F(StapelTest, push__Overflow__StapelExceptionIsThrown_variante){
    try {
        fillUpToLimitWithoutException();
        objectUnderTest.push(1);
        FAIL() << "Fehler: StapelException erwartet";
    }catch(const StapelException & ex) {
        EXPECT_STREQ("Overflow", ex.what());
    }

}
