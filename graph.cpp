#include "graph.h"

// O(u * v)
void Graph::createEdges() {
    for (Tic* tic: tics) {
        for (Tac* tac: tacs) {
            if (tac->getId() >= tic->getMin()  && tac->getId() <= tic->getMax()){
                // valid edge
                edges.push_back(new Edge(tic, tac));
            }
        }
    }
}
