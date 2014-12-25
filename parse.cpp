#include <iostream>
#include <fstream>
#include "parse.h"
#include "split.h"

using namespace std;
void Parser::parse() {
    cout << filename << endl;
    string line;
    ifstream in_file;
    in_file.open(this->filename);
    if (in_file.is_open()) {
        int num_graphs;
        getline(in_file, line);
        num_graphs = stoi(line);
        cout << "num_graphs: " << num_graphs << endl;

        getline(in_file, line);
        vector<string> u_and_v = split(line, ' ');
        unsigned long num_tics = strtoul(u_and_v[0].c_str(), NULL, 0);
        unsigned long num_tacs = strtoul(u_and_v[1].c_str(), NULL, 0);

        cout << "num_tics: " << num_tics << endl;
        cout << "num_tacs: " << num_tacs << endl;

        for (int i = 0; i < num_tics; i++) {
            getline(in_file, line);
            vector<string> tic_args = split(line, ' ');
            tics.push_back(Tic(stoi(tic_args[0]), stoi(tic_args[1]), stoi(tic_args[2]), stoi(tic_args[3])));
        }
        for (int i = 0; i < num_tacs; i++) {
            getline(in_file, line);
            vector<string> tac_args = split(line, ' ');
            tacs.push_back(Tac(stoi(tac_args[0]), stoi(tac_args[1])));
        }
        cout << "tics.size(): " << tics.size() << endl;
        cout << "tacs.size(): " << tacs.size() << endl;

        in_file.close();
    } else {
        cout << "Unable to open " << this->filename << endl;
    }
}
