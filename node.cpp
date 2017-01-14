#include "node.h"
double getdistance(node n1,node n2)
{
    return std::sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
}
