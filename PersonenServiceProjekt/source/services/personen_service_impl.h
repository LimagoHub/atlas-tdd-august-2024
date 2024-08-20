//
// Created by JoachimWagner on 21.02.2024.
//

#pragma once
#include "../persistence/personen_repository.h"
#include "personen_service.h"
#include "blacklist_service.h"

#include "personen_service_exception.h"

class personen_service_impl :public personen_service{


public:


    personen_service_impl(personen_repository &repo, blacklist_service &blacklistService) :
        repo(repo),
        blacklistService(blacklistService) {}

    /*
 *	Vorname < 2 -> PSE
 *	Nachname < 2 -> PSE
 *
 *	Attila -> PSE
 *
 *	Alle technische Exceptions -> PSE
 *
 *	Happy Day -> person an Save_or_update Methode uebergeben
 *
 */
    void speichern(person &person_)   override{

        try {
            speichernImpl(person_);

        }
        catch(const personen_service_exception &e) {
            throw e;
        }
        catch(const std::exception &e) {
            throw personen_service_exception{"Ein Fehler ist aufgetreten"};
        }

        catch(...) {
            throw personen_service_exception{"Ein Fehler ist aufgetreten"};
        }
    }




private:
    void speichernImpl(const person &person_) const {
        checkPerson(person_);

        repo.save_or_update(person_);
    }

    void checkPerson(const person &person_) const {
        validatePerson(person_);
        businessCheck(person_);
    }

    void businessCheck(const person &person_) const { if (blacklistService.is_blacklisted(person_)) throw personen_service_exception{"Unerwuenschte Person"}; }

    void validatePerson(const person &person_) const {
        if (person_.getVorname().length() < 2) throw personen_service_exception{"Vorname zu kurz"};
        if (person_.getNachname().length() < 2) throw personen_service_exception{"Nachname zu kurz"};
    }

    personen_repository &repo;
    blacklist_service & blacklistService;


};
