#include <iostream>
#include "parse.h"
#include "split.h"

using namespace std;
void Parser::parseGraph(ifstream &in_file) {
    // set up local vars we'll populate
    string line;
    Graph* graph = new Graph();
    vector<Tic*> tics = graph->getTics();
    map<int, Tic*> tic_map = graph->getTic_map();
    vector<Tac*> tacs = graph->getTacs();
    map<int, Tac*> tac_map = graph->getTac_map();

    // grab number of tics, tacs
    getline(in_file, line);
    vector<string> u_and_v = split(line, ' ');
    unsigned long num_tics = strtoul(u_and_v[0].c_str(), NULL, 0);
    unsigned long num_tacs = strtoul(u_and_v[1].c_str(), NULL, 0);

    // create objects for all tics
    for (int i = 0; i < num_tics; i++) {
        getline(in_file, line);
        vector<string> tic_args = split(line, ' ');
        Tic* aTic = new Tic(stoi(tic_args[0]), stoi(tic_args[1]), stoi(tic_args[2]), stoi(tic_args[3]));
        tics.push_back(aTic);
        tic_map[aTic->getId()] = aTic;
    }

    // create objects for all tacs
    for (int i = 0; i < num_tacs; i++) {
        getline(in_file, line);
        vector<string> tac_args = split(line, ' ');
        Tac* aTac = new Tac(stoi(tac_args[0]), stoi(tac_args[1]));
        tacs.push_back(aTac);
        tac_map[aTac->getId()] = aTac;
    }

    // populate our graph with vectors, maps we've made
    graph->setTacs(tacs);
    graph->setTics(tics);
    graph->setTac_map(tac_map);
    graph->setTic_map(tic_map);
    graph->createEdges();

    // add graph to the parser's list
    graphs.push_back(graph);
}

void Parser::parse() {
    cout << filename << endl;
    string line;
    ifstream in_file;
    in_file.open(this->filename);
    if (in_file.is_open()) {
        int num_graphs;
        getline(in_file, line);
        num_graphs = stoi(line);
        for (int i = 0; i < num_graphs; i++) {
            parseGraph(in_file);
        }
        in_file.close();
    } else {
        cout << "Unable to open " << this->filename << endl;
    }
}

void Parser::process() {
    for (Graph* g: graphs){
        findAllMatchings(*g, Matching());
        vector<Matching> sortedMatchings = g->getMatchings();
        sort(sortedMatchings.end(), sortedMatchings.begin());
        cout << sortedMatchings.size() << endl;
        for (Matching m: sortedMatchings) {
            cout << m;
        }
    }

}
void Parser::findAllMatchings(Graph graph, Matching matching) {
    if (graph.getEdges().size() == 0) {
        vector<Matching> matchings = graph.getMatchings();
        matchings.push_back(matching);
        cout << "Adding matching: " << matching << endl;
        graph.setMatchings(matchings);
        return;
    }
    vector<Edge*> edges = graph.getEdges();
    Edge* e = edges.back();
    edges.pop_back();
    graph.setEdges(edges);
    map<int, Tic*> tic_map = graph.getTic_map();
    map<int, Tac*> tac_map = graph.getTac_map();
    Tic* tic = e->getTic();
    Tac* tac = e->getTac();

    // leave recursive call
    findAllMatchings(graph, matching);
    if (tic_map[tic->getId()]->isFree() && tac_map[tac->getId()]->isFree()) {
        tic_map[tic->getId()]->setFree(false);
        tac_map[tac->getId()]->setFree(false);
        graph.setTic_map(tic_map);
        graph.setTac_map(tac_map);
        matching.addEdge(Edge(tic, tac));

        // take recursive call
        findAllMatchings(graph, matching);
    }

}
