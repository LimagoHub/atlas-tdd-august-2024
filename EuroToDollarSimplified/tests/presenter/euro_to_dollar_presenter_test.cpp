//
// Created by JoachimWagner on 22.02.2024.
//

#include "euro_to_dollar_presenter_test.h"

TEST_F(euro_to_dollar_presenter_test, beenden__happy_day__mask_closed){
    //Arrange
    EXPECT_CALL(viewMock, dispose()).Times(1);

    // Act
    objectUnderTest.beenden();
}

TEST_F(euro_to_dollar_presenter_test, rechnen__NANInEuroField__ErrorMessageInDollarField){

    InSequence dummy;
    //Arrange
    EXPECT_CALL(viewMock, get_euro).WillOnce(Return("Not a Number"));
    EXPECT_CALL(viewMock, set_dollar("Keine Zahl"));
    // Act
    objectUnderTest.rechnen();
}
TEST_F(euro_to_dollar_presenter_test, populate_items__happy_day__mask_initialized){
    //Arrange (indirekt auch Assertion)
    EXPECT_CALL(viewMock, set_euro("0")).Times(1);
    EXPECT_CALL(viewMock, set_dollar("0")).Times(1);
    EXPECT_CALL(viewMock, set_rechnen_enabled(true)).Times(1);
    // Act
    objectUnderTest.populate_items();
}

void euro_to_dollar_presenter_test::SetUp() {
    objectUnderTest.set_view(&viewMock);
    objectUnderTest.set_model(&calculatorMock);
}
