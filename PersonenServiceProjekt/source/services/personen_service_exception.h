//
// Created by JoachimWagner on 13.12.2022.
//

#pragma once


#include <exception>
#include <string>
class personen_service_exception : public std::exception
{
    char const* message;

public:
    personen_service_exception()
    {
    }

    personen_service_exception(char const* _Message)
            : message(_Message)
    {
    }


    personen_service_exception(exception const& _Other)
            : exception(_Other)
    {
    }
    personen_service_exception(char const* _Message,exception const& _Other)
            : exception(_Other), message(message)
    {
    }

    const char *what() const override {
        return message;
    }
};
