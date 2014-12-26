#ifndef _EDGE_H
#define _EDGE_H

#include "tic.h"
#include "tac.h"
#include <iostream>

class Edge{
private:
    Tic* tic;
    Tac* tac;
public:
    Edge(Tic *tic, Tac *tac) : tic(tic), tac(tac) {
    }

    Tac *getTac() const {
        return tac;
    }

    Tic *getTic() const {
        return tic;
    }

    int getWeight(){
        return tic->getWeight() + tac->getWeight();
    }
    friend std::ostream& operator<<(std::ostream& os, const Edge& e);


};

std::ostream& operator<<(std::ostream& os, const Edge& e);

#endif