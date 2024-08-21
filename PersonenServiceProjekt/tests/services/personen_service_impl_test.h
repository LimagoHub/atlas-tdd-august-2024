//
// Created by JoachimWagner on 20.08.2024.
//

#pragma once
#include "gmock/gmock.h"
#include "../Mockpersonen_repository.h"
#include "../Mockblacklist_service.h"

#include "../../source/services/personen_service_impl.h"
#include "../../source/services/personen_service_exception.h"

using namespace testing;

class personen_service_impl_test : public Test{

protected:
    Mockpersonen_repository repoMock;
    NiceMock<Mockblacklist_service> blacklistMock;
    personen_service_impl objectUnderTest{repoMock, blacklistMock};

    void SetUp() override;
};

class personen_service_impl_parameter_test : public personen_service_impl_test, public WithParamInterface<std::pair<person, std::string>> {
public:
    personen_service_impl_parameter_test(): personen_service_impl_test(){}

protected:
    person invalidPerson{"",""};
    std::string expectedErrorMessage;

    void SetUp() override{
        personen_service_impl_test::SetUp();
        std::tie<person, std::string>(invalidPerson, expectedErrorMessage) = GetParam();

    }

};
