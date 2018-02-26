//
// Created by sunzhijun on 18-2-26.
//

#include <algorithm>
#include "MaxHeap.h"
namespace structures{
    template <class Elem, class Comp>
    void MaxHeap<Elem, Comp>::shiftdown(int pos) {
        while (!isleaf(pos)) {
            int max_index = leftchild(pos);
            int rc = rightchile(pos);
            if ((rc < _count) && Comp::lt(_heap[max_index], _heap[rc]))
                max_index = rc;
            if (!Comp::lt(_heap[pos], _heap[max_index])) return ;
            std::swap(_heap[pos], _heap[max_index]);
            pos = max_index;
        }
    }

    template <class Elem, class Comp>
    bool MaxHeap<Elem, Comp>::insert(const Elem & val) {
        if (_count >= _capacity) return false;
        int curr = _count++;
        _heap[curr] = val;
        // Now shift up until curr's parent > curr
        while (curr != 0
               && (Comp::gt(_heap[curr], _heap[parent(curr)]))){
            std::swap(_heap[curr], _heap[parent(curr)]);
            curr = parent(curr);
        }
        return true;
    }

    template <class Elem, class Comp>
    bool MaxHeap<Elem, Comp>::removemax(Elem & it) {
        if (_count == 0) return false;
        std::swap(_heap[0], _heap[--_count]);
        if (_count!=0) shiftdown(0);
        it = _heap[_count];
        return true;
    }

    template <class Elem, class Comp>
    bool MaxHeap<Elem, Comp>::remove(int pos, Elem & it) {
        if ( pos < 0 || pos >= _count) return false;
        std::swap(_heap[pos], _heap[--_count]);
        while (pos != 0
               && Comp::gt(_heap[pos], _heap[parent(pos)]))
            std::swap(_heap[pos], _heap[parent(pos)]);
        shiftdown(pos);
        it = _heap[_count];
        return true;
    }
}


#define DEBUG_STRUCT_MAXHEAP_H
#ifdef DEBUG_STRUCT_MAXHEAP_H

#include "Compare.h"


int main() {
    using structures::MaxHeap;
    using test_compare::intintCompare;
    int data[] = {1,2,3,4,5,6,7,8,9,0};
    MaxHeap<int,intintCompare> a(data,10,10);

    a.print();
}

#endif