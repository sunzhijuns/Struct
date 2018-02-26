//
// Created by sunzhijun on 18-2-19.
//


//#define TEST_STRUCT_STRING_H

#include <string>
#include "String.h"
#ifdef TEST_STRUCT_STRING_H
int main(){
    std::string a_str = "asdf";
    std::cout<< a_str<<"\n";
    using structures::String;
    String a("hello"); //调用普通构造函数
    String b("world"); //调用普通构造函数
    String c(a); //调用拷贝构造函数
    c=b; //调用赋值函数
    String d(a+b);
    return 0;
}

#endif
