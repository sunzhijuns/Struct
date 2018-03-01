//
// Created by sunzhijun on 18-2-28.
//

#ifndef STRUCT_GENTREE_H
#define STRUCT_GENTREE_H

#include <iostream>

namespace structures {
// General tree node ADT
    template<class Elem>
    class GTNode {
    public:
        GTNode(const Elem &);

        ~GTNode();

        Elem Value();

        bool IsLeaf();

        GTNode *Parent();

        GTNode *LeftMostChild();

        GTNode *RightSibling();

        void SetValue(Elem &);

        void InsertFirst(GTNode<Elem> *n);

        void InsertNext(GTNode<Elem> *n);

        void RemoveFirst();

        void RemoveNext();
    };

// General tree ADT
    template<class Elem>
    class GenTree {
    private:
        void PrintHelp(GTNode<Elem> *);

    public:
        GenTree();

        ~GenTree();

        void clear();

        GTNode<Elem> *Root();

        void NewRoot(Elem &, GTNode<Elem> *, GTNode<Elem> *);

        void Print();
    };



    class UnionFind{
    private:
        int* _array;
        int _size;
        int Find(int) const;
//        const static int ROOT = 0;

    public:
        UnionFind(int);
        ~UnionFind() { delete[] _array; }
        void Union(int,int);    // Merge equivalences
        bool Differ(int,int);   // True if not in same tree
        void Print();
    };
}


namespace structures{
    template <class Elem>
    void GenTree<Elem>::PrintHelp(GTNode<Elem> * subroot) {
        if (subroot->IsLeaf()) std::cout << "Leaf: ";
        else std::cout << "Internal: ";
        std::cout << subroot->Value() << "\n";
        for (GTNode<Elem>* temp = subroot->LeftMostChild();
                temp != NULL; temp = temp->RightSibling()){
            PrintHelp(temp);
        }
    }

    UnionFind::UnionFind(int sz) {
        _size = sz;
        _array = new int[sz];
        for (int i = 0; i < sz; ++i) {
//            _array[i] = ROOT;
            _array[i] = i;
        }
    }

    bool UnionFind::Differ(int a, int b) {
        int root1 = Find(a);
        int root2 = Find(b);
        return root1 != root2;
    }

    void UnionFind::Union(int a, int b) {
        int root1 = Find(a);
        int root2 = Find(b);
        if (root1 != root2) _array[root2] = root1;  // Merge
    }

    void UnionFind::Print() {
        std::cout << "< ";
        for (int i = 0; i < _size; ++i) {
            std::cout << _array[i] << " ";
        }
        std::cout << ">\n";
    }

    int UnionFind::Find(int curr) const {
//        while (_array[curr] != ROOT) curr = _array[curr];
        while (_array[curr] != curr) curr = _array[curr];
        return curr;
    }
}

#endif //STRUCT_GENTREE_H
