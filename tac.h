#ifndef _TAC_H
#define _TAC_H

class Tac {
private:
    int id, weight;
    bool free;

public:

    bool isFree() const {
        return free;
    }

    void setFree(bool free) {
        Tac::free = free;
    }

    int getId() const {
        return id;
    }

    int getWeight() const {
        return weight;
    }

public:
    Tac() {
        id = -1;
        weight = -1;
        free = false;
    }
    Tac(int id, int weight) : id(id), weight(weight) {
        free = true;
    }

    bool operator<(const Tac& other) {
        return this->id < other.id;
    }

    bool operator!=(const Tac& other) {
        return this->id != other.id;
    }
};
#endif