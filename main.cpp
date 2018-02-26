#include <iostream>

#include <list>
#define MAIN_CPP

#ifdef MAIN_CPP

#include <stdio.h>
//函数定义为inline即:内联函数
inline const char* dbtest(int i) {
    return (i % 2 > 0) ? "奇" : "偶";
}

int main()
{
    int i = 0;
    for (i=1; i < 100; i++) {
        printf("i:%d    奇偶性:%s \n", i, dbtest(i));
    }

}

#endif
