#include "edge.h"

std::ostream& operator<<(std::ostream& os, const Edge& e)
{
    os << e.getTic()->getId() << ":" << e.getTac()->getId() << std::endl;
    return os;
}