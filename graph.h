#ifndef _GRAPH_H
#define _GRAPH_H
#include <vector>
#include <map>
#include "tic.h"
#include "tac.h"
#include "edge.h"
class Graph{
private:
    std::vector<Tic*> tics;
    std::vector<Tac*> tacs;
    std::vector<Edge*> edges;
    std::map<int, Tic*> tic_map;
    std::map<int, Tac*> tac_map;

public:
    // constructor
    Graph() {
        tics = std::vector<Tic*>();
        tacs = std::vector<Tac*>();
        edges = std::vector<Edge*>();
        tic_map = std::map<int, Tic*>();
        tac_map = std::map<int, Tac*>();
    };

    // copy constructor
    Graph(Graph& other) {
        tics = std::vector<Tic*>(other.getTics());
        tacs = std::vector<Tac*>(other.getTacs());
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

    virtual ~Graph() {
        for (Tic* aTic: tics) {
            delete aTic;
        }
        for (Tac* aTac: tacs) {
            delete aTac;
        }
        for (Edge* anEdge: edges){
            delete anEdge;
        }
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
