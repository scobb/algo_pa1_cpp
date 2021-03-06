#include <iostream>
#include <sstream>
#include "parse.h"
#include "split.h"

using namespace std;
void Parser::parseGraph(ifstream &in_file) {
    // set up local vars we'll populate
    string line;
    Graph* graph = new Graph();
    vector<Tic> tics = graph->getTics();
    map<int, Tic> tic_map = graph->getTic_map();
    vector<Tac> tacs = graph->getTacs();
    map<int, Tac> tac_map = graph->getTac_map();

    // grab number of tics, tacs
    getline(in_file, line);
    vector<string> u_and_v = split(line, ' ');
    unsigned long num_tics = strtoul(u_and_v[0].c_str(), NULL, 0);
    unsigned long num_tacs = strtoul(u_and_v[1].c_str(), NULL, 0);

    // create objects for all tics
    for (int i = 0; i < num_tics; i++) {
        getline(in_file, line);
        vector<string> tic_args = split(line, ' ');
        Tic aTic = Tic(stoi(tic_args[0]), stoi(tic_args[1]), stoi(tic_args[2]), stoi(tic_args[3]));
        tics.push_back(aTic);
        tic_map[aTic.getId()] = aTic;
    }

    // create objects for all tacs
    for (int i = 0; i < num_tacs; i++) {
        getline(in_file, line);
        vector<string> tac_args = split(line, ' ');
        Tac aTac = Tac(stoi(tac_args[0]), stoi(tac_args[1]));
        tacs.push_back(aTac);
        tac_map[aTac.getId()] = aTac;
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

void Parser::output(vector<Matching> matchings, fstream* out_file) {
    sort(matchings.rbegin(), matchings.rend());
    if (matchings.size()) {
        unsigned long max_cardinality = matchings[0].getEdges().size();
        while (matchings.back().getEdges().size() != max_cardinality) {
            matchings.pop_back();
        }
    }
    sort(matchings.rbegin(), matchings.rend(), byWeight);
    int max_weight = matchings[0].getWeight();
    while (matchings.back().getWeight() != max_weight) {
        matchings.pop_back();
    }
    vector<string> matchingStrings = vector<string>();
    for (Matching m: matchings){
        ostringstream matchingOss;
        matchingOss << m << endl;
        matchingStrings.push_back(matchingOss.str());
    }
    sort(matchingStrings.begin(), matchingStrings.end());


    *out_file << matchings.size() << endl;
    for (string mString: matchingStrings){
        *out_file << mString;
    }
    out_file->close();

}

void Parser::process() {
    string out_file_path = filename;
    out_file_path.replace(filename.length()-2, filename.length(), "out");
    fstream out_file;
    out_file.open(out_file_path, fstream::out);
    for (Graph* g: graphs){
        vector<Matching> matchings = findAllMatchings(*g, Matching(), vector<Matching>());
        output(matchings, &out_file);
        out_file.open(out_file_path, fstream::app);
    }
    out_file.close();
}
vector<Matching> Parser::findAllMatchings(Graph graph, Matching matching, vector<Matching> matchings) {
    if (graph.getEdges().size() == 0) {
        matchings.push_back(matching);
        return matchings;
    }
    vector<Edge> edges = graph.getEdges();
    Edge e = edges.back();
    edges.pop_back();
    graph.setEdges(edges);
    map<int, Tic> tic_map = graph.getTic_map();
    map<int, Tac> tac_map = graph.getTac_map();
    Tic* tic = e.getTic();
    Tac* tac = e.getTac();

    // leave recursive call
    vector<Matching> leave_matchings = findAllMatchings(graph, matching, matchings);

    // build a new vector that combines the results
    vector<Matching> new_matchings = vector<Matching>();
    new_matchings.insert(new_matchings.end(), matchings.begin(), matchings.end());
    new_matchings.insert(new_matchings.end(), leave_matchings.begin(), leave_matchings.end());
    if (tic_map[tic->getId()].isFree() && tac_map[tac->getId()].isFree()) {
        tic_map[tic->getId()].setFree(false);
        tac_map[tac->getId()].setFree(false);
        graph.setTic_map(tic_map);
        graph.setTac_map(tac_map);
        matching.addEdge(Edge(tic, tac));

        // take recursive call
        vector<Matching> take_matchings = findAllMatchings(graph, matching, matchings);

        // combine results
        new_matchings.insert(new_matchings.end(), take_matchings.begin(), take_matchings.end());
    }

    // return combined results
    return new_matchings;

}
