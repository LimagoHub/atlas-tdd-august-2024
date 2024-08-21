//
// Created by JoachimWagner on 21.08.2024.
//

#pragma once
#include <memory>;
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockDependency.h"
#include "../source/MyServiceUsingDependency.h"
using namespace testing;

class MyServiceUsingDepenencyTest: public Test {
protected:

    std::unique_ptr<Dependency> dependencyMock = std::make_unique<MockDependency>();

    Dependency *raw = dependencyMock.get();
    MyServiceUsingDependency objectUnderTest{std::unique_ptr<Dependency>{raw}};
};
