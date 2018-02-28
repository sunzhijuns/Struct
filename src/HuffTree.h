//
// Created by sunzhijun on 18-2-26.
//

#ifndef STRUCT_HUFFTREE_H
#define STRUCT_HUFFTREE_H


#include <cstdio>
#include "List.h"

namespace structures {
    template<class Elem>
    class HuffNode {
    public:
        virtual ~HuffNode();

        virtual int weight() = 0;
        virtual bool isLeaf() = 0;

        virtual HuffNode* left() const = 0;
        virtual HuffNode* right() const = 0;
        virtual void setLeft(HuffNode*) = 0;
        virtual void setRight(HuffNode*) = 0;
    };

    template <class Elem>
    class FreqPair {
    private:
        Elem _it;
        int _freq;
    public:
        FreqPair(const Elem& e, int f)
        { _it = e; _freq = f; }
        ~FreqPair() {  }
        int weight() { return _freq; }
        Elem& val() { return _it; }
    };

    template <class Elem>
    class LeafNode:public HuffNode<Elem>{
    private:
        FreqPair<Elem>* _it;
    public:
        LeafNode(const Elem& val, int f) {
            _it = new FreqPair<Elem>(val, f);
        }
        Elem& val() { return _it->val(); }

        int weight() { return _it->weight(); }
        bool isLeaf() { return true; }

        virtual HuffNode* left() const { return NULL; }
        virtual HuffNode* right() const { return NULL; }
        virtual void setLeft(HuffNode*) {}
        virtual void setRight(HuffNode*) {}
    };

    template <class Elem>
    class IntlNode:public HuffNode<Elem>{
    private:
        HuffNode<Elem>* _left_child;
        HuffNode<Elem>* _right_child;
        int _weight;
    public:
        IntlNode(HuffNode<Elem>* l, HuffNode<Elem>* r) {
            _weight = l->weight() + r->weight();
            _left_child = l; _right_child = r;
        }
        int weight() { return _weight; }
        bool isLeaf() { return false; }
        HuffNode<Elem>* left() const { return _left_child; }
        HuffNode<Elem>* right() const { return _right_child; }
        void setLeft(HuffNode<Elem>* left ) { _left_child = left; }
        void setRight(HuffNode<Elem>* right) { _right_child = right; }
    };


    template <class Elem>
    class HuffTree{
    private:
        HuffNode<Elem>* _root;
    public:
        HuffTree(Elem& val, int f){
            _root = new LeafNode<Elem>(val, f);
        }
        HuffTree(HuffTree<Elem>* l, HuffTree<Elem>* r){
            _root = new IntlNode<Elem>(l->_root, r->_root);
        }
        ~HuffTree() {}
        HuffNode<Elem>* root() { return _root; }
        int weight() { return _root->weight(); }
    };


    // Compare two Huffman trees by total weight
    template <class Elem>
    class HHComp {
    public:
        static bool lt(HuffTree<Elem> *x, HuffTree<Elem> *y){
            return x->weight() < y->weight();
        }
        static bool eq(HuffTree<Elem>* x, HuffTree<Elem>* y){
            return x->weight() == y->weight();
        }
        static bool gt(HuffTree<Elem>* x, HuffTree<Elem>* y){
            return x->weight() > y->weight();
        }
    };

    // Build a Huffman tree from list f1
    template <class Elem> HuffTree<Elem>*
    buildHuff(SLList< HuffTree<Elem>*, HHComp<Elem> >* f1){
        HuffTree<Elem>* temp1;
        HuffTree<Elem>* temp2;
        HuffTree<Elem>* temp3;
        for (f1->setStart(); f1->leftLength() + f1->rightLength() > 1;
                f1->setStart()){
            f1->remove(temp1);
            f1->remove(temp2);
            temp3 = new HuffTree<Elem>(temp1, temp2);
            f1->insert(temp3);
            delete temp1;
            delete temp2;
        }
        return temp3;
    }


}

#endif //STRUCT_HUFFTREE_H
