//
// Created by sunzhijun on 18-2-28.
//

#include "GenTree.h"

#define DEBUG_STRUCT_GENTREE_H
#ifdef DEBUG_STRUCT_GENTREE_H

int main(){

    using structures::UnionFind;
    UnionFind a(8);
    a.Print();
    a.Union(1,2);
    a.Print();
    a.Union(2,3);
    a.Print();
    a.Union(4,3);
    a.Print();
    std::cout << a.Differ(1,2) << "\n";
    return 0;
}

#endif