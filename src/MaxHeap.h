//
// Created by sunzhijun on 18-2-24.
//

#ifndef STRUCT_MAXHEAP_H
#define STRUCT_MAXHEAP_H

#include <iostream>

namespace structures {
//Max-heap class
    template<class Elem, class Comp>
    class MaxHeap {
    private:
        Elem *_heap;            // Pointer to the heap array
        int _capacity;              // Maximum size of the heap
        int _count;                 // Number of elements now in the heap
        void shiftdown(int);    // Put element in its correct place
    public:
        MaxHeap(Elem *h, int num, int max) {
            _heap = h;
            _count = num;
            _capacity = max;
            buildheap();
        }

        int heapsize() const { return _count; }

        bool isleaf(int pos) const { return (pos < _count) && (pos >= _count / 2); }

        int leftchild(int pos) const { return 2 * pos + 1; }

        int rightchile(int pos) const { return 2 * pos + 2; }

        int parent(int pos) const { return (pos - 1) / 2; }

        bool insert(const Elem &);

        bool removemax(Elem &);

        bool remove(int, Elem &);

        void buildheap() { for (int i = _count / 2 - 1; i >= 0; i--) shiftdown(i); }

        void print() {
            for (int i = 0; i < _count; i++)
                std::cout <<  _heap[i] << " ";
            std::cout << std::endl;
        }
    };
}

#endif //STRUCT_MAXHEAP_H
