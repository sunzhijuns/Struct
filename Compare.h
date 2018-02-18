//
// Created by sunzhijun on 18-2-18.
//

#ifndef STRUCT_COMPARE_H
#define STRUCT_COMPARE_H

#include <cstring>  /*strcmp*/

namespace test_compare{
    class intintCompare{
    public:
        static bool lt(int x, int y) { return x < y; }
        static bool eq(int x, int y) { return x == y; }
        static bool gt(int x, int y) { return x > y; }
    };

    class Payroll{
    public:
        int ID;
        char* name;
    };

    class IDCompare{
    public:
        static bool lt(Payroll& x, Payroll& y)
        { return x.ID < y.ID; }
        static bool eq(Payroll& x, Payroll& y)
        { return x.ID == y.ID; }
        static bool gt(Payroll& x, Payroll& y)
        { return x.ID > y.ID; }
    };

    class NameCompare{
    public:
        static bool lt(Payroll& x, Payroll& y)
        { return strcmp(x.name, y.name) < 0; }
        static bool eq(Payroll& x, Payroll& y)
        { return strcmp(x.name, y.name); }
        static bool gt(Payroll& x, Payroll& y)
        { return strcmp(x.name, y.name); }


    };
}


#endif //STRUCT_COMPARE_H
