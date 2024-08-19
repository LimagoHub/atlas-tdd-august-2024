//
// Created by JoachimWagner on 05.06.2023.
//

#pragma once


#include <exception>

class StapelException: public std::exception {
    const char *const message;
public:
    //StapelException() {}

    explicit StapelException(const char *const message="") :message(message) {}

    const char *what() const  override {
        return message;
    }
};
