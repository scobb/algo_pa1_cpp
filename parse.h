#include "graph.h"
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
    void findAllMatchings(Graph graph);
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