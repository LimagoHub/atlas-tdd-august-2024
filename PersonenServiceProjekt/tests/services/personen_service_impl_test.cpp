//
// Created by JoachimWagner on 20.08.2024.
//

#include "personen_service_impl_test.h"

TEST_F(personen_service_impl_test,speichern__vorname_zu_kurz__throws_personen_service_exception){
    try {
        // Arrange
        person invalidPerson{"J", "Doe"};

        // Act
        objectUnderTest.speichern(invalidPerson);

        FAIL() << "Exception expected";
    } catch(const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Vorname zu kurz"));
    }
}

TEST_F(personen_service_impl_test,speichern__nachname_zu_kurz__throws_personen_service_exception){
    try {
        // Arrange
        person invalidPerson{"John", "D"};

        // Act
        objectUnderTest.speichern(invalidPerson);

        FAIL() << "Exception expected";
    } catch(const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Nachname zu kurz"));
    }
}

TEST_F(personen_service_impl_test, speichern__Unerwuenschte_Person__throws_personen_service_exception) {
    try {
        person invalidPerson{"John", "der Hunne"};
        EXPECT_CALL(blacklistMock, is_blacklisted(invalidPerson)).WillOnce(Return(true));
        objectUnderTest.speichern(invalidPerson);
        FAIL() << "Exception expected";
    } catch(const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Unerwuenschte Person"));
    }
}

TEST_F(personen_service_impl_test, speichern__unexpected_exception_in_underlying_service__throws_personen_service_exception) {
    try {
        person validPerson{"John", "Doe"};
        EXPECT_CALL(repoMock,save_or_update(_)).WillOnce(Throw(std::invalid_argument{"upps"}));
        objectUnderTest.speichern(validPerson);
        // Assertion
        FAIL() << "Exception expected";

    } catch(const personen_service_exception &ex) {
        EXPECT_THAT(ex.what(), StrEq("Ein Fehler ist aufgetreten"));
        //EXPECT_THAT(ex.getNested(), Not (IsNull()));
    }
}

TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repo) {
    InSequence dummy;

    // Arrange
    person validPerson{"John", "Doe"};
    EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(validPerson));

    // Act
    objectUnderTest.speichern(validPerson);


}

void personen_service_impl_test::SetUp() {
    ON_CALL(blacklistMock, is_blacklisted(_)).WillByDefault(Return(false));
}
