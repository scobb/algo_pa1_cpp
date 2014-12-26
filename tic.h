#ifndef _TIC_H
#define _TIC_H
#include <iostream>

class Tic{

private:
    int id, min, max, weight;
    bool free;
public:
    bool isFree() const {
        return free;
    }

    void setFree(bool free) {
        Tic::free = free;
    }
    int getId() const {
        return id;
    }

    int getMin() const {
        return min;
    }

    int getMax() const {
        return max;
    }

    int getWeight() const {
        return weight;
    }

public:
    Tic(int id, int min, int max, int weight) : id(id), min(min), max(max), weight(weight) {
        free = true;
    }
};
#endif