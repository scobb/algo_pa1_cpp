#ifndef _TIC_H
#define _TIC_H

class Tic{

private:
    int id, min, max, weight;
public:
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
    }
};
#endif