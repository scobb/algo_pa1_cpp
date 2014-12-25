#include "tic.h"
#include "tac.h"

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
};