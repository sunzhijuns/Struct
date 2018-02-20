//
// Created by sunzhijun on 18-2-20.
//

#ifndef STRUCT_BINARYTREE_H
#define STRUCT_BINARYTREE_H

#include <cstdlib>
#include <iostream>

namespace structures{

    namespace binnode {

        template<class Elem>
        class BinNode {
        public:
            virtual ~BinNode() {}

        public:
            // Return the node's element
            virtual Elem &val() = 0;

            // Set the node's element
            virtual void setVal(const Elem &) = 0;

            // Return the node's left child
            virtual BinNode *left() const = 0;

            virtual BinNode *right() const = 0;

            virtual void setLeft(BinNode *) = 0;

            virtual void setRight(BinNode *) = 0;

            virtual bool isLeaf() = 0;
        };


        template<class Elem>
        void visit(BinNode<Elem> *node) {
            std::cout << node->val() << " ";
        }

        template<class Elem>
        void preorder(BinNode<Elem> *subroot) {
            if (subroot == NULL) return;
            visit(subroot);
            preorder(subroot->left());
            preorder(subroot->right());
        }

        template<class Elem>
        void inorder(BinNode<Elem> *subroot) {
            if (subroot == NULL) return;
            inorder(subroot->left());
            visit(subroot);
            inorder(subroot->right());
        }

        template<class Elem>
        void postorder(BinNode<Elem> *subroot) {
            if (subroot == NULL) return;
            postorder(subroot->left());
            postorder(subroot->right());
            visit(subroot);
        }

        template<class Elem>
        void destroy(BinNode<Elem> * subroot){
            if ( subroot == NULL) return ;
            destroy(subroot->left());
            destroy(subroot->right());
            delete subroot;
        }

        template<class Elem>
        int count(BinNode<Elem> *subroot) {
            if (subroot == NULL) return 0;
            return 1 + count(subroot->left()) + count(subroot->right());
        }

#define DEBUG_STRUCT_BINARYTREE_H_BINNODE_BINNODEPTR_FREELIST

        // Binary tree node class
        template<class Elem>
        class BinNodePtr : public BinNode<Elem> {
        private:
#ifdef DEBUG_STRUCT_BINARYTREE_H_BINNODE_BINNODEPTR_FREELIST
            static int _freeListSize;
#endif
            const static int NewOnceCount = 20;
            static BinNodePtr<Elem> * _freeList;
        private:
            Elem _it;
            BinNodePtr *_lc;
            BinNodePtr *_rc;
        public:
            BinNodePtr() { _lc = _rc = NULL; }

            BinNodePtr(Elem e,
                       BinNodePtr *l = NULL,
                       BinNodePtr *r = NULL) {
                _it = e, _lc = l;
                _rc = r;
            }

            ~BinNodePtr() {}

            Elem &val() { return _it; }

            void setVal(const Elem &e) { _it = e; }

            inline BinNode<Elem> *left() const { return _lc; }

            inline BinNode<Elem> *right() const { return _rc; }

            void setLeft(BinNode<Elem> *b) { _lc = (BinNodePtr *) b; }

            void setRight(BinNode<Elem> *b) { _rc = (BinNodePtr *) b; }

            bool isLeaf() { return (_lc == NULL) && (_rc == NULL); }

            void* operator new(size_t);
            void operator delete(void*);
        };

#ifdef DEBUG_STRUCT_BINARYTREE_H_BINNODE_BINNODEPTR_FREELIST
        template <class Elem>
        int BinNodePtr<Elem>::_freeListSize = 0;
#endif
        template <class Elem>
        BinNodePtr<Elem> * BinNodePtr<Elem>::_freeList = NULL;

        template <class Elem>
        void* BinNodePtr<Elem>::operator new(size_t){
#ifdef DEBUG_STRUCT_BINARYTREE_H_BINNODE_BINNODEPTR_FREELIST
            std::cout << "\nfreeListSize : "<<_freeListSize << " new --start\n";
#endif
            if (_freeList == NULL) {
                BinNodePtr<Elem> (*tmpArray) = new BinNodePtr<Elem>[NewOnceCount];
                _freeList = &tmpArray[0];
                BinNodePtr<Elem> * tmp = &tmpArray[0];
                for (int i = 1; i < NewOnceCount; ++i) {
                    tmp->_lc = &tmpArray[i];
                    tmp = &tmpArray[i];
                }
#ifdef DEBUG_STRUCT_BINARYTREE_H_BINNODE_BINNODEPTR_FREELIST
                _freeListSize = NewOnceCount;
                std::cout << "\nfreeListSize : "<<_freeListSize << "\n";
#endif
            }//return ::new BinNodePtr;
            BinNodePtr<Elem> * tmp = (BinNodePtr<Elem> *)_freeList;
            _freeList = _freeList->_lc;

            tmp->_lc = NULL;
            tmp->_rc = NULL;
#ifdef DEBUG_STRUCT_BINARYTREE_H_BINNODE_BINNODEPTR_FREELIST
            _freeListSize--;
            std::cout << "\nfreeListSize : "<<_freeListSize << " new --end\n";
#endif
            return tmp;
        }

        template <class Elem>
        void BinNodePtr<Elem>::operator delete(void* ptr){
            ((BinNodePtr<Elem>*)ptr)->_lc = _freeList;
            _freeList = (BinNodePtr<Elem>*)ptr;
#ifdef DEBUG_STRUCT_BINARYTREE_H_BINNODE_BINNODEPTR_FREELIST
            _freeListSize++;
            std::cout << "\nfreeListSize : "
                      <<_freeListSize << " delete "<<"\n";
#endif
        }
    }

    namespace union_varbinnode {
        enum NodeType {
            kLeaf, kInternal
        };

        template <class Operator, class Operand>
        class VarBinNode{
        public:
            NodeType mytype;
            union{
                struct{
                    VarBinNode* left;
                    VarBinNode* right;
                    Operator opx;
                } intl;
                Operand var;
            };
            VarBinNode(const Operand& val) // Constructor: left
            { mytype = kLeaf, var = val; }
            VarBinNode(const Operator& op,
                       VarBinNode* l, VarBinNode* r){
                mytype = kInternal; intl.opx = op;
                intl.left = l; intl.right = r;
            }
            bool isLeaf() { return mytype == kLeaf; }
            VarBinNode* left() const { return intl.left; }
            VarBinNode* right() const { return intl.right; }
        };

        template <class Operator, class Operand>
        void visitLeaf(VarBinNode<Operator, Operand>* node)
        { std::cout << "Leaf: " << node->var << "\n"; }

        template <class Operator, class Operand>
        void visitInternal(VarBinNode<Operator, Operand>* node){
            std::cout << "Internal: " << node->intl.opx << "\n";
        }

        template <class Operator, class Operand>
        void preorder(VarBinNode<Operator, Operand>* subroot){
            if (subroot == NULL) return ;
            if (subroot->isLeaf())
                visitLeaf(subroot);
            else {
                visitInternal(subroot);
                preorder(subroot->left());
                preorder(subroot->right());
            }
        }

        template <class Operator, class Operand>
        void inorder(VarBinNode<Operator, Operand>* subroot){
            if (subroot == NULL) return ;
            if (subroot->isLeaf())
                visitLeaf(subroot);
            else {
                inorder(subroot->left());
                visitInternal(subroot);
                inorder(subroot->right());
            }
        }

        template <class Operator, class Operand>
        void postorder(VarBinNode<Operator, Operand>* subroot){
            if (subroot == NULL) return ;
            if (subroot->isLeaf())
                visitLeaf(subroot);
            else {
                postorder(subroot->left());
                postorder(subroot->right());
                visitInternal(subroot);
            }
        }
    }

    namespace varbinnode{
        class VarBinNode{   // Node abstract base class
        public:
            virtual ~VarBinNode() {}
            virtual bool isLeaf() = 0;
        };

        template <class Operand>
        class LeafNode:public VarBinNode{
        private:
            Operand _var;
        public:
            LeafNode(const Operand& val) { _var = val; }
            bool isLeaf() { return true; }
            Operand value() { return _var; }
        };

        template < class Operator>
        class IntlNode : public VarBinNode
        {
        private:
            VarBinNode* _left;
            VarBinNode* _right;
            Operator _opx;
        public:
            IntlNode(const Operator& op, VarBinNode* l, VarBinNode* r)
            { _opx = op; _left = l; _right = r; }
            bool isLeaf() { return false; }
            VarBinNode* left() { return _left; }
            VarBinNode* right() { return _right; }
            Operator value() { return _opx; }
        };

        template <class Operand>
        void visitLeaf(LeafNode<Operand>* node){
            std::cout << "Leaf: " << node->value() << std::endl;
        }

        template <class Operator>
        void visitInternal(IntlNode<Operator>* node){
            std::cout << "Leaf: " << node->value() << std::endl;
        }

        template <class Operator, class Oprand>
        void preorder(VarBinNode* subroot){
            if (subroot == NULL) return ;
            if (subroot->isLeaf())
                visitLeaf((LeafNode<Oprand>*)subroot);
            else {
                visitInternal((IntlNode<Operator>*)subroot);
                preorder(((IntlNode<Operator>*)subroot)->left());
                preorder(((IntlNode<Operator>*)subroot)->right());
            }

        }

    }


}

#endif //STRUCT_BINARYTREE_H
