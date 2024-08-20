//
// Created by JoachimWagner on 31.01.2024.
//

#pragma once
#include "gmock/gmock.h"
#include "../Mockexchange_rate_service.h"
#include "../../source/services/euro_to_dollar_calculator_impl.h"

using namespace testing;

class euro_to_dollar_calculator_impl_test : public Test{
protected:
    Mockexchange_rate_service exchangeRateServiceMock;
    euro_to_dollar_calculator_impl objectUnderTest{exchangeRateServiceMock};
};
