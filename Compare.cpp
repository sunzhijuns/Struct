//
// Created by sunzhijun on 18-2-18.
//
#include "Compare.h"

//#define TEST_COMPARE_STRCMP
#ifdef TEST_COMPARE_STRCMP

/* strcpy example */
#include <stdio.h>
#include <string.h>

int main ()
{
    char str1[]="Sample string";
    char str2[4];
    char str3[40];
    strcpy (str2,str1);
    strcpy (str3,"copy successful");
    printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
    return 0;
}

#endif

#define TEST_DICTIONARY
#ifdef TEST_DICTIONARY

#include "Dictionary.h"
int main(){
//    {
//        typedef structures::UALdict<int, int,
//                test_compare::intintCompare,
//                test_compare::intintCompare> IntIntDic;
//        IntIntDic a;
//        a.insert(1);
//        a.insert(2);
//        std::cout<<"size : "<<a.size()<<std::endl;
//        int temp;
//        a.remove(2, temp);
//        std::cout<<"delete "<<temp<<", size : "<<a.size() <<std::endl;
//
//    }
    {

        using test_compare::Payroll;
        typedef structures::SALdict<int,
                test_compare::Payroll,
                test_compare::IDPayrollCompare,
                test_compare::IDCompare> IntPayrollDic;
        IntPayrollDic b(3);
        b.insert(Payroll(1,"sun",3));
//        b.insert(Payroll(2,"li",2));
//        b.insert(Payroll(3,"wang",4));

        b.print();

    }
}

#endif

