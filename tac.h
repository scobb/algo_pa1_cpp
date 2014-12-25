#ifndef _TAC_H
#define _TAC_H

class Tac {
private:
    int id, weight;

public:
    int getId() const {
        return id;
    }

    int getWeight() const {
        return weight;
    }

public:
    Tac(int id, int weight) : id(id), weight(weight) {
    }
};
#endif