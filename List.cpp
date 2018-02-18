//
// Created by sunzhijun on 18-2-18.
//

#include "List.h"


#include "List.h"

#define LIST_TEST
#ifdef LIST_TEST

struct Point{
    int x;
    int y;
    Point(){
        x = y = 0;
    }
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    friend std::ostream&
    operator<<(std::ostream& out, Point point)
    { return out<<"Point:(" << point.x << ", "<< point.y<<")"; }
//    operator<< (){
//
//    }
};
int main() {

    structures::LList<Point> a;
    a.insert(Point(1,2));
    a.insert(Point(1,3));
    a.insert(Point(1,4));
    a.setPos(2);
    a.print();

    a.insert(Point(1,100));
    a.insert(Point(1,99));
    a.print();

    Point temp;
    a.remove(temp);
    std::cout<< temp << "\n";
    a.print();

    structures::LList<int> b;
    b.insert(2);
    b.insert(5);
    b.insert(8);
    b.print();


    return 0;
}
#endif



