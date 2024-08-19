//
// Created by JoachimWagner on 19.08.2024.
//

#pragma once


class Stapel {
private:
    bool empty{true};

public:
    bool isEmpty();
    void push(int value) {
        empty = false;
    }
};
