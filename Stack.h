//
// Created by sunzhijun on 18-2-19.
//

#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H

#include "List.h"

namespace structures {

    template<class Elem>
    class Stack {
    public:
        virtual ~Stack() {}

    public:
        virtual void clear() = 0;

        virtual bool push(const Elem &) = 0;

        virtual bool pop(Elem &) = 0;

        virtual bool topValue(Elem &) const = 0;

        virtual int length() const = 0;

        virtual void print() const = 0;

    };

    // Array-based stack implementation
    template <class Elem>
    class AStack:public Stack<Elem>{
    private:
        int _size;          // Maximum size of stack
        int _top;           // Index for top element
        Elem* _listArray;   // Array holding stack elements
    public:
        const static int DefaultListSize = 20;
        AStack(int sz = DefaultListSize)
        { _size = sz; _top = 0; _listArray = new Elem[sz]; }
        ~AStack() { delete[] _listArray; }
        void clear() { _top = 0; }
        bool push(const Elem& item){
            if (_top == _size) return false;    // Stack is full
            else { _listArray[_top++] = item; return true; }
        }
        bool pop(Elem& it){
            if (_top == 0) return false;
            else { it = _listArray[--_top]; return true; }
        }
        bool topValue(Elem& it) const { //Return top element
            if (_top == 0) return false;
            else { it = _listArray[_top-1]; return true; }
        }
        int length() const { return _top; }
        void print() const {
            std::cout << "< ";
            for (int i = 0; i < _top; ++i) {
                std::cout << _listArray[i] << " ";
            }
            std::cout <<">"<< std::endl;
        }
    };

    template <class Elem>
    class LStack:public Stack<Elem>{
    private:
        Link<Elem>* _top;
        int _size;
    public:
        const static int DefaultListSize = 20;
        LStack(int sz = DefaultListSize) { _top = NULL; _size =  0; }
        ~LStack() { clear(); }
        void clear(){
            while (_top != NULL){
                Link<Elem>* temp = _top;
                _top = _top->next;
                delete temp;
            }
            _size = 0;
        }
        bool push(const Elem& item){
            _top = new Link<Elem>(item, _top);
            _size++;
            return true;
        }
        bool pop(Elem& it){
            if (_size == 0) return false;
            it = _top->element;
            Link<Elem>* temp = _top->next;
            delete _top;
            _top = temp;
            _size--;
            return true;
        }
        bool topValue(Elem& it) const {
            if (_size == 0) return false;
            it = _top->element;
            return true;
        }
        int length() const { return _size; }
        void print() const {
            std::cout << "< ";
            Link<Elem>* temp = _top;
            while(temp != NULL){
                std::cout << temp->element << " ";
                temp = temp->next;
            }
            std::cout << ">\n";
        }
    };
}



#endif //STRUCT_STACK_H
