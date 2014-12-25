#include <iostream>
#include <fstream>
#include "split.h"
#include "parse.h"

using namespace std;

int main() {
    string local_path = "/Users/scobb/ClionProjects/Algo_PA1/";
    string in_file_path = local_path + "small/input0.txt";
    Parser myParser = Parser(in_file_path);
    myParser.parse();

    return 0;
}