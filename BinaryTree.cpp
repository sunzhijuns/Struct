//
// Created by sunzhijun on 18-2-20.
//
#include "BinaryTree.h"

#define TEST_STRUCT_BINARYTREE_H
#ifdef TEST_STRUCT_BINARYTREE_H

using structures::binnode::BinNodePtr;
int main(){

    BinNodePtr<int>* a = new BinNodePtr<int>(1);
    a->setLeft(new BinNodePtr<int>(2));
    a->setRight(new BinNodePtr<int>(3));

    structures::binnode::preorder(a);

    structures::binnode::inorder(a);

    structures::binnode::postorder(a);

    structures::binnode::destroy(a);

}

#endif
