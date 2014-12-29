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
    void output(std::vector<Matching>, std::fstream*);
public:
    void process();
    std::vector<Matching> findAllMatchings(Graph graph, Matching matching, std::vector<Matching>);
    std::vector<Graph *> const &getGraphs() const {
        return graphs;
    }

    Parser(std::string &filename) : filename(filename) {
        parse();
    }

    virtual ~Parser() {
        for (Graph *graph: graphs) {
            delete graph;
        }
    }

};

#endif