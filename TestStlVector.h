//
// Created by sunzhijun on 18-2-24.
//

#ifndef STRUCT_TESTSTLVECTOR_H
#define STRUCT_TESTSTLVECTOR_H

#include <vector>
#include <cstdio>

int test_stl_vector()
{
    std::vector<int> arr;
    arr.push_back(10);
    arr.push_back(11);
    for (int i = 0; i < arr.size(); ++i) {
        int val = arr.at(i);
        printf("%d\n", val);
    }

    return 0;
}

#endif //STRUCT_TESTSTLVECTOR_H
