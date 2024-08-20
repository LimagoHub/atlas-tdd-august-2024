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