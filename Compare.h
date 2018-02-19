//
// Created by sunzhijun on 18-2-18.
//

#ifndef STRUCT_COMPARE_H
#define STRUCT_COMPARE_H

#include <cstring>  /*strcmp*/
#include <iostream>

namespace test_compare{

    class intintCompare{
    public:
        static bool lt(const int x, const int y) { return x < y; }
        static bool eq(const int x, const int y) { return x == y; }
        static bool gt(const int x, const int y) { return x > y; }
    };

    class Payroll{
    private:
        void init(int id, char* nameval, int size){
            ID = id;
            nameSize = size;
            name = new char[nameSize+1];
            strcpy(name, nameval);
        }
        void clear(){
            ID = 0;
            nameSize = 0;
            name = NULL;
        }
        void init(const Payroll& p){
            init(p.ID, p.name, p.nameSize);
        }
        void destroy(){
            delete name;
        }
    public:
        int ID;
        char* name;
        int nameSize;
        Payroll(){
            clear();
            std::cout<<this<<" 默认构造 "<<*this<<" \n";
        }
        Payroll(const Payroll& p){
            init(p);
            std::cout<<this<<" 拷贝构造 "<<*this<<" \n";
        }
        Payroll(int id, char* nameval, int size) {
            init(id,nameval,size);
            std::cout<<this<<" 完整构造 "<<*this<<" \n";
        }
        ~Payroll(){
            std::cout<<this <<" 析构:" << *this <<" \n";
            delete name;
        }

        Payroll& operator = (const Payroll& other){
            std::cout << "赋值：" << &other <<"("<<other<<")" << " -> " << this<<"("<<*this<<")" << " \n";
            destroy();
//            clear();
            init(other);
        }

        friend std::ostream&
        operator<<(std::ostream& out, const Payroll& p)
        { return out<<"(id:" << p.ID << ", name:"<< (p.name == NULL ? "NULL": p.name) <<")"; }
    };

    class IDPayrollCompare{
    public:
        static bool lt(const int& id, const Payroll& payroll)
        { return id < payroll.ID; }
        static bool eq(const int& id, const Payroll& payroll)
        { return id == payroll.ID; }
        static bool gt(const int& id, const Payroll& payroll)
        { return id > payroll.ID; }
    };

    class IDCompare{
    public:
        static bool lt(const Payroll& x, const Payroll& y)
        { return x.ID < y.ID; }
        static bool eq(const Payroll& x, const Payroll& y)
        { return x.ID == y.ID; }
        static bool gt(const Payroll& x, const Payroll& y)
        { return x.ID > y.ID; }
    };

    class NameCompare{
    public:
        static bool lt(const Payroll& x, const Payroll& y)
        { return strcmp(x.name, y.name) < 0; }
        static bool eq(const Payroll& x, const Payroll& y)
        { return strcmp(x.name, y.name); }
        static bool gt(const Payroll& x, const Payroll& y)
        { return strcmp(x.name, y.name); }


    };
}


#endif //STRUCT_COMPARE_H
