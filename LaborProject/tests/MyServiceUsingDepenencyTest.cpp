//
// Created by JoachimWagner on 21.08.2024.
//

#include "MyServiceUsingDepenencyTest.h"


TEST_F(MyServiceUsingDepenencyTest, demo){
    auto dependencyMock = std::make_unique<MockDependency>();

    EXPECT_CALL(*dependencyMock, foobar).WillOnce(Return(5));
    MyServiceUsingDependency objectUnderTest{std::move(dependencyMock)};

    auto result = objectUnderTest.g("Hallo");

    EXPECT_THAT(result, Eq(10));
}

void MyServiceUsingDepenencyTest::SetUp() {
    Test::SetUp();
}
