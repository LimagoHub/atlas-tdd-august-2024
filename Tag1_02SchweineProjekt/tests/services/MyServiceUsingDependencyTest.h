//
// Created by JoachimWagner on 19.08.2024.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../source/services/MyServiceUsingDependency.h"
#include "MockDependency.h"

using namespace testing;



class MyServiceUsingDependencyTest : public Test{

protected:
    MockDependency dependencyMock;
    MyServiceUsingDependency objectUnderTest{dependencyMock};
};
