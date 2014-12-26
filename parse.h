#ifndef _PARSE_H
#define _PARSE_H
#include "graph.h"
#include "matching.h"
#include <vector>
#include <string>
#include <map>
#include <fstream>

class Parser{

private:
    std::vector<Graph*> graphs;
    std::string filename;
    void parseGraph(std::ifstream &in_file);
    void parse();
public:
    void process();
    void findAllMatchings(Graph graph, Matching matching);
    std::vector<Graph *> const &getGraphs() const {
        return graphs;
    }

    Parser(std::string &filename) : filename(filename) {
        parse();
    }

    virtual ~Parser() {
        for (Graph *graph: graphs) {
            std::cout << "In destructor." << std::endl;
            for (Tic* aTic: graph->getTics()) {
                delete aTic;
            }
            for (Tac* aTac: graph->getTacs()) {
                delete aTac;
            }
            for (Edge* anEdge: graph->getEdges()){
                delete anEdge;
            }
            delete graph;
        }
    }

};

#endif