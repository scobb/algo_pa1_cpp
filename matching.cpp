#include "matching.h"
bool operator<(const Matching& left, const Matching& right)
{
return left.getEdges().size() < right.getEdges().size();
}

std::ostream& operator<<(std::ostream& os, const Matching& matching)
{
    for (Edge edge: matching.getEdges()){
        os << edge.getTic()->getId() << ":" << edge.getTac()->getId();
    }
    return os;
}