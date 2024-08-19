//
// Created by JoachimWagner on 19.08.2024.
//

#pragma once


#include <string>
#include <ostream>
#include <stdexcept>
class Schwein {

private:

    std::string name;
    int gewicht;

    void setGewicht(int gewicht) {
        Schwein::gewicht = gewicht;
    }

public:
    Schwein():Schwein{"nobody"} {}

    explicit Schwein(const std::string &name) :  gewicht(10) {
        setName(name);
    }


    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        if(name == "Elsa") throw std::invalid_argument("Falscher Name");
        Schwein::name = name;
    }

    int getGewicht() const {
        return gewicht;
    }

    void fuettern() {
        setGewicht(getGewicht() + 1);
    }

    bool operator==(const Schwein &rhs) const {
        return name == rhs.name &&
               gewicht == rhs.gewicht;
    }

    bool operator!=(const Schwein &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }

};
