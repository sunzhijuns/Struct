#include <iostream>

#include <list>

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