//
// Created by JoachimWagner on 31.01.2024.
//
#include "euro_to_dollar_calculator_impl_test.h"


TEST_F(euro_to_dollar_calculator_impl_test, convert__exception_in_underlying_service__throws_std_runtime_error){
    try {
        EXPECT_CALL(exchangeRateServiceMock, get_rate_for).WillOnce(Throw("Irgend einen Unsinn"));
        auto dummy = objectUnderTest.convert(10.0);
        FAIL() << "Exception expected";
    } catch(const std::runtime_error & ex) {
        EXPECT_THAT(ex.what(), StrEq("Exchange Rate Service ist nicht erreichbar"));
    }

}
TEST_F(euro_to_dollar_calculator_impl_test, convert__happy_day__returnsExpectedDollarValue){

        EXPECT_CALL(exchangeRateServiceMock, get_rate_for("USD")).WillOnce(Return(2.999999999) );
        auto dollar = objectUnderTest.convert(10.0);
        EXPECT_THAT(dollar, DoubleNear(29.999999999999999, 0.001));
}
