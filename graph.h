#ifndef _GRAPH_H
#define _GRAPH_H
#include <vector>
#include <iostream>
#include <map>
#include "tic.h"
#include "tac.h"
#include "edge.h"
#include "matching.h"
class Graph{
private:
    std::vector<Tic*> tics;
    std::vector<Tac*> tacs;
    std::vector<Edge*> edges;
    std::vector<Matching> matchings;
    std::map<int, Tic*> tic_map;
    std::map<int, Tac*> tac_map;

public:
    std::vector<Matching> const &getMatchings() const {
        return matchings;
    }

    void setMatchings(std::vector<Matching> const &matchings) {
        Graph::matchings = matchings;
    }

// constructor
    Graph() {
        tics = std::vector<Tic*>();
        tacs = std::vector<Tac*>();
        edges = std::vector<Edge*>();
        matchings = std::vector<Matching>();
        tic_map = std::map<int, Tic*>();
        tac_map = std::map<int, Tac*>();
    };

    // copy constructor
    Graph(Graph& other) {
        tics = std::vector<Tic*>(other.getTics());
        tacs = std::vector<Tac*>(other.getTacs());;
        edges = std::vector<Edge*>(other.getEdges());
        matchings = std::vector<Matching>(other.getMatchings());
        tic_map = std::map<int, Tic*>(other.getTic_map());
        tac_map = std::map<int, Tac*>(other.getTac_map());
    }
    void createEdges();

    std::vector<Edge *> const &getEdges() const {
        return edges;
    }

    void setEdges(std::vector<Edge *> const &edges) {
        Graph::edges = edges;
    }

    void setTics(std::vector<Tic *> const &tics) {
        Graph::tics = tics;
    }

    void setTacs(std::vector<Tac *> const &tacs) {
        Graph::tacs = tacs;
    }

    void setTic_map(std::map<int, Tic *> const &tic_map) {
        Graph::tic_map = tic_map;
    }

    void setTac_map(std::map<int, Tac *> const &tac_map) {
        Graph::tac_map = tac_map;
    }

    std::vector<Tic *> const &getTics() const {
        return tics;
    }

    std::vector<Tac *> const &getTacs() const {
        return tacs;
    }

    std::map<int, Tic *> const &getTic_map() const {
        return tic_map;
    }

    std::map<int, Tac *> const &getTac_map() const {
        return tac_map;
    }
};
#endif
