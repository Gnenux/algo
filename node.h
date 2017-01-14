#ifndef __NODE_H
#define __NODE_H
#include <cmath>

class node
{
    friend double getdistance(node n1,node n2);
public:

    node(int id=-1,double x=0.0,double y=0.0):id(id),x(x),y(y){}
    int getid(){return this->id;}
    ~node()=default;
private:
    int id;         //点序号
    double x;       //坐标中的x
    double y;       //坐标中的y

};

#endif
