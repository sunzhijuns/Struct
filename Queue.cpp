//
// Created by sunzhijun on 18-2-19.
//
#include "Queue.h"

//#define TEST_STRUCT_QUEUE_H
#ifdef TEST_STRUCT_QUEUE_H


using structures::Queue;
using structures::AQueue;
using structures::LQueue;
int main(){
    LQueue<int> a;
    a.enqueue(1);
    a.enqueue(2);
    a.print();
    int tmp;
    a.dequeue(tmp);
    std::cout<< tmp<<"\n";
    a.enqueue(3);
    a.print();
    a.clear();
    a.print();
}

#endif
