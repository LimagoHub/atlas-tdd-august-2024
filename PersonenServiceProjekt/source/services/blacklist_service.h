//
// Created by JoachimWagner on 20.08.2024.
//

#pragma once
#include "../persistence/person.h"

class blacklist_service {
public:
    virtual bool is_blacklisted(const person &possibleBlacklistedPerson) const = 0;
};
