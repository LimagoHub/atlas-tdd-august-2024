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

    void setGewicht(int gewicht) noexcept{
        Schwein::gewicht = gewicht;
    }

public:
    inline static const int default_weight{10};
    Schwein():Schwein{"Nobody"} {}

    explicit Schwein(const std::string &name) :  gewicht(default_weight) {
        setName(name);
    }


    const std::string &getName() const noexcept{
        return name;
    }

    void setName(const std::string &name) {
        if(name == "Elsa") throw std::invalid_argument("Ungueltiger Name");
        Schwein::name = name;
    }

    int getGewicht() const noexcept{
        return gewicht;
    }

    void fuettern() noexcept{
        setGewicht(getGewicht() + 1);
    }

    bool operator==(const Schwein &rhs) const noexcept{
        return name == rhs.name &&
               gewicht == rhs.gewicht;
    }

    bool operator!=(const Schwein &rhs) const noexcept{
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) noexcept {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }

};
