//
// Created by JoachimWagner on 13.04.2023.
//

#include "euro_to_dollar_impl_test.h"
TEST_F(euro_to_dollar_impl_test,convert__unexpectedErrorInExchangeRateService__throwsRuntime_exception ){
    try {
        EXPECT_CALL(exchange_rate_service_mock, get_rate_for(_)).WillOnce(Throw("Upps"));
        auto result = object_under_test.convert(100);
        FAIL() << "Exception wurde erwartet";
    } catch(const std::runtime_error & ex){
        EXPECT_THAT(ex.what(), StrEq("Exchange Rate Service nicht erreichbar"));
    }
}
TEST_F(euro_to_dollar_impl_test,convert__happy_day__success ){
    EXPECT_CALL(exchange_rate_service_mock, get_rate_for("USD")).WillOnce(Return(1.1));
    EXPECT_FLOAT_EQ(110.0,object_under_test.convert(100));
}
