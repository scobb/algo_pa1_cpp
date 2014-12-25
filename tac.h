#pragma once

class Tac {
private:
    int id, weigth;

public:
    int getId() const {
        return id;
    }

    int getWeigth() const {
        return weigth;
    }

public:
    Tac(int id, int weigth) : id(id), weigth(weigth) {
    }
};