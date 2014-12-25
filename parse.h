#include "tic.h"
#include "tac.h"
#include <vector>
#include <string>

class Parser{
private:
    std::vector<Tic> tics;
    std::vector<Tac> tacs;
    std::string filename;
public:
    Parser(std::string &filename) : filename(filename) {
        tics = std::vector<Tic>();
        tacs = std::vector<Tac>();
    }
    void parse();
};