#include <iostream>

#include <list>

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

    structures::AList<Point> a;
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

    return 0;
}
#endif


//#define MAIN_CPP
#ifdef MAIN_CPP
int main() {
    std::cout << "Hello, World!" << std::endl;

    structures::AList<int> a;
    a.insert(3);
    a.insert(4);
    a.insert(6);
    a.setPos(2);
    a.print();

    a.insert(100);
    a.insert(99);
    a.print();

    int temp;
    a.remove(temp);
    std::cout<< temp << "\n";
    a.print();

    return 0;
}
#endif