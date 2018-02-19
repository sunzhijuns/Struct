//
// Created by sunzhijun on 18-2-19.
//
#include <assert.h>
#include "Stack.h"
#define TEST_STRUCT_STACK_H
#ifdef TEST_STRUCT_STACK_H

namespace test_stack {

    using structures::Stack;

    long fact(int n, Stack<int> &s) {
        assert(n >= 1 && n <= 12);
        while (n > 1) s.push(n--);
        long result = 1;
        int val;
        while (s.pop(val)) result = result * val;
        return result;
    }


    enum TOHop {
        DOMOVE, DOTOH
    };

    template<typename Pole>
    class TOHobj {
    public:
        TOHop op_;
        int num_;
        Pole start_, goal_, tmp_;
        //DOTOH operation
        TOHobj(int n, Pole s, Pole g, Pole t){
            op_ = DOTOH; num_ = n;
            start_ = s; goal_ = g; tmp_ = t;
        }
        TOHobj(Pole s, Pole g){
            op_ = DOMOVE; start_ = s; goal_ = g;
        }

    };
    template<typename Pole>
    void move(Pole start, Pole goal){
        std::cout << start << " -> " << goal << "\n";
    }

    template<typename Pole>
    void TOH(int n, Pole start, Pole goal, Pole tmp, Stack<TOHobj<Pole>*>&s){
        s.push(new TOHobj<Pole>(n, start, goal, tmp));
        TOHobj<Pole>*t;
        while (s.pop(t)){
            if (t->op_ == DOMOVE)
                move(t->start_, t->goal_);
            else if (t->num_ > 0){
                int num = t->num_;
                tmp = t->tmp_; goal = t->goal_;
                start = t->start_;
                s.push(new TOHobj<Pole>(num-1, tmp, goal, start));
                s.push(new TOHobj<Pole>(start, goal));
                s.push(new TOHobj<Pole>(num-1, start, tmp, goal));
            }
            delete t;
        }

    }

}
int main(){
    using test_stack::fact;
    using structures::LStack;
    using test_stack::TOHobj;
    LStack<TOHobj<int>*> a;
    test_stack::TOH(5,1,3,2,a);
//    std::cout << fact(3, a);

}

#endif
