//
// Created by JoachimWagner on 19.08.2024.
//

#pragma once



class Stapel {

private:
    int data[10];
    int index = 0;

public:
    Stapel() = default;
    auto push(int value)->void;
    auto pop()->int;

    auto isEmpty()->bool const;
    auto isFull()->bool const;

};
