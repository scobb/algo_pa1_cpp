#include "edge.h"
#include <iostream>
using namespace std;

std::ostream& operator<<(std::ostream& os, const Edge& e)
{
    os << e.getTic()->getId() << ":" << e.getTac()->getId() << std::endl;
    return os;
}

bool operator<(const Edge &left, const Edge &right) {
    if (left.getTac() != right.getTac()) {
        return left.getTac() < right.getTac();
    } else {
        return left.getTic() < right.getTic();
    }
}
