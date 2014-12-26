#include "matching.h"

bool operator<(const Matching& left, const Matching& right)
{
    return left.getEdges().size() < right.getEdges().size();
}

std::ostream& operator<<(std::ostream& os, const Matching& matching)
{
    std::string prefix = "";
    std::vector<Edge> output = matching.getEdges();
    std::sort(output.begin(), output.end());
    for (Edge edge: output){
        os << prefix << edge.getTic()->getId() << ":" << edge.getTac()->getId();
        prefix = " ";
    }
    return os;
}

bool byWeight(const Matching &left, const Matching &right) {
    return left.getWeight() < right.getWeight();
}
