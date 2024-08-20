//
// Created by JoachimWagner on 19.08.2024.
//

#include "MyServiceUsingDependencyTest.h"

TEST_F(MyServiceUsingDependencyTest, MockdemoFooFunc) {

    // Arrange + Assert
    //RecordMode
    EXPECT_CALL(dependencyMock, foo("HALLO"));

    //ReplayMode

    //Act
    objectUnderTest.f("Hallo");
}
TEST_F(MyServiceUsingDependencyTest, MockdemoFooBarFunc) {

    EXPECT_CALL(dependencyMock, foobar("Hallo Welt")).WillOnce(Return(2));

    auto result = objectUnderTest.g("Hallo");

    EXPECT_THAT(result, Eq(7));


}

TEST_F(MyServiceUsingDependencyTest, dummy) {

    EXPECT_CALL(dependencyMock, bar()).Times(AtLeast(1))
        .WillOnce(Return(10))
        .WillOnce(Return(20))
        .WillOnce(Throw(std::exception{}));
    //EXPECT_CALL(dependencyMock, foobar(_));

    ON_CALL(dependencyMock, foobar(_)).WillByDefault(Return(2));
    auto result = objectUnderTest.h();

    EXPECT_THAT(result, Eq(200));


}