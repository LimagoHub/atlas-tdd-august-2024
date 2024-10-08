//
// Created by JoachimWagner on 20.08.2024.
//

#include "personen_service_impl_test.h"

TEST_P(personen_service_impl_parameter_test, speichern__throws_personen_service_exception) {
    try {
        EXPECT_CALL(repoMock, save_or_update(_)).Times(0);
        objectUnderTest.speichern(invalidPerson);
        FAIL() << "Exception erwartet";
    } catch (personen_service_exception &ex) {
        EXPECT_STREQ(ex.what(), expectedErrorMessage.c_str());
    }
}

TEST_F(personen_service_impl_test,speichern__vorname_zu_kurz__throws_personen_service_exception){
    try {
        // Arrange
        person invalidPerson{"J", "Doe"};
        EXPECT_CALL(repoMock, save_or_update(_)).Times(0);
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
        EXPECT_CALL(repoMock, save_or_update(_)).Times(0);
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
        EXPECT_CALL(repoMock, save_or_update(_)).Times(0);
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


TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repo_overloaded) {
    // Arrange
    person captured_person{};
    EXPECT_CALL(blacklistMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(DoAll(SaveArg<0>(&captured_person)));

    objectUnderTest.speichern("John","Doe");

    EXPECT_THAT( captured_person.getVorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    EXPECT_THAT(captured_person.getNachname(), AnyOf(Eq("Doe"), Eq("Mustermann")));
    EXPECT_THAT(captured_person.getId(), Not(IsEmpty()));

}
void personen_service_impl_test::SetUp() {
    ON_CALL(blacklistMock, is_blacklisted(_)).WillByDefault(Return(false));
}

INSTANTIATE_TEST_SUITE_P(
        speichern_invalid_names, // Name der Testa frei waehlbar
        personen_service_impl_parameter_test, // Verbindung zur Testklasse
        Values(
                std::make_pair(person{"","Doe"},"Vorname zu kurz" ),
                std::make_pair(person{"J","Doe"},"Vorname zu kurz" ),
                std::make_pair(person{"John",""},"Nachname zu kurz" ),
                std::make_pair(person{"John","D"},"Nachname zu kurz" )
        )
);
