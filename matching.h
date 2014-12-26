#ifndef _MATCHING_H
#define _MATCHING_H

#include <vector>
#include "edge.h"

class Matching {
private:
    std::vector<Edge> edges;

public:
    std::vector<Edge> const &getEdges() const {
        return edges;
    }

    Matching() {
        edges = std::vector<Edge>();
    }
    void addEdge(Edge edge) {
        edges.push_back(edge);
    }

    bool byWeight (Matching& other) {
        int this_weight = 0;
        int other_weight = 0;
        for (Edge edge: this->edges) {
            this_weight += edge.getWeight();
        }
        for (Edge edge: other.edges) {
            other_weight += edge.getWeight();
        }
        return this_weight < other_weight;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matching& matching);
};

std::ostream& operator<<(std::ostream& os, const Matching& matching);
bool operator<(const Matching& left, const Matching& right);

#endif