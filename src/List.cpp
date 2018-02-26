//
// Created by sunzhijun on 18-2-18.
//

#include "List.h"


//#define LIST_TEST
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
    { return out<<"(" << point.x << ", "<< point.y<<")"; }
//    operator<< (){
//
//    }
};

class PointComp{
public:
    static bool lt(const Point& a, const Point& b)
    { return a.x < b.x; }
    static bool eq(Point& a, Point& b)
    { return a.x == b.x; }
    static bool gt(Point& a, Point& b)
    { return a.x > b.x; }
};


//#define TEST_SALIST
#ifdef TEST_SALIST
int main(){
    structures::SAList<Point,PointComp> a;
//    structures::AList<Point> a;
    a.insert(Point(1,2));
    a.insert(Point(2,3));
    a.insert(Point(5,5));
    a.insert(Point(4,4));
    a.insert(Point(6,6));
    a.print();

}
#endif

//#define TEST_DLIST_INSERT
#ifdef TEST_DLIST_INSERT

int main(){
    structures::DList<Point> a;
    a.insert(Point(1,1));
    a.insert(Point(1,2));
    a.print();
    Point temp;
    a.remove(temp);
    a.print();
    a.append(Point(2,3));
    a.print();
//    Point temp;
//    for (a.setStart(); a.getValue(temp); a.next()){
//        std::cout << temp << " ";
//    }
//    std::cout << std::endl;
}

#endif

//#define TEST_LLIST_APPEND
#ifdef TEST_LLIST_APPEND
int main(){
    structures::LList<Point> a;
    a.append(Point(1,2));
    a.append(Point(1,3));
    a.print();

    a.setPos(1);
    a.print();

    a.insert(Point(2,4));
    a.print();

    a.append(Point(3,5));
    a.print();
}
#endif

//#define TEST_LLIST_INSERT
#ifdef TEST_LLIST_INSERT
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

#endif



