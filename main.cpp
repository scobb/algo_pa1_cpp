#include <iostream>
#include "parse.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " IN_FILE" << endl;
        return 1;
    }
    string in_file_path = argv[1];
    Parser myParser = Parser(in_file_path);
    myParser.process();

    return 0;
}