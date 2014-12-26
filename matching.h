#ifndef _MATCHING_H
#define _MATCHING_H

#include <vector>
#include <algorithm>
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

    int getWeight() const {
        int weight = 0;
        for (Edge e: edges) {
            weight += e.getWeight();
        }
        return weight;
    }



    Matching& operator+=(const Matching& other) {
        std::vector<Edge> new_edges;
        new_edges.reserve(this->edges.size() + other.edges.size());
        new_edges.insert(new_edges.end(), this->edges.begin(), this->edges.end());
        new_edges.insert(new_edges.end(), other.edges.begin(), other.edges.end());
        this->edges = new_edges;
        return *this;

    }

    friend std::ostream& operator<<(std::ostream& os, const Matching& matching);
};

std::ostream& operator<<(std::ostream& os, const Matching& matching);
bool operator<(const Matching& left, const Matching& right);
bool byWeight(const Matching& left, const Matching& right);

#endif