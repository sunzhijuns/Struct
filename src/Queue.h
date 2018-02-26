//
// Created by sunzhijun on 18-2-19.
//

#ifndef STRUCT_QUEUE_H
#define STRUCT_QUEUE_H

#include <iostream>
#include <assert.h>
#include "List.h"

namespace structures{

    template <class Elem>
    class Queue{
    public:
        virtual ~Queue() {}
    public:
        virtual void clear() = 0;
        virtual bool enqueue(const Elem&) = 0;
        virtual bool dequeue(Elem&) = 0;
        virtual bool frontValue(Elem&) const = 0;
        virtual int length() const = 0;
        virtual void print() const = 0;
    };

    // Array-based queue implementation
    template <class Elem>
    class AQueue: public Queue<Elem>{
    private:
        int _size;          // Maximum size of queue
        int _front;         // Index of front element
        int _rear;          // Index of rear element
        Elem* _listArray;   // Array holding queue elements
    public:
        const static int DefaultListSize = 20;
        AQueue(int sz = DefaultListSize){
            assert(sz >= 1);
            // Make list array one position larger for empty slot
            _size = sz + 1;
            _rear = 0; _front = 1;
            _listArray = new Elem[_size];
        }
        ~AQueue() { delete [] _listArray; }
        void clear() { _front = 1;  _rear = 0;  }
        bool enqueue(const Elem& it){
            if (((_rear + 2) % _size) == _front) return false;  //Full
            _rear = (_rear+1) % _size;  //Circular increment
            _listArray[_rear] = it;
            return true;
        }
        bool dequeue(Elem& it){
            if (length() == 0) return false;    //Empty
            it = _listArray[_front];
            _front = (_front + 1) % _size;  //Circular increment
            return true;
        }
        bool frontValue(Elem& it) const {
            if (length() == 0) return false;    //Empty
            it = _listArray[_front];
            return true;
        }
        // Full : (_rear + 2) % _size == _front
        //        ((_rear + 2) % _size - _front) % _size = (_size - 1) % _size
        // Empty: (_rear + 1) % _size == _front
        //        (_rear + 1) % _size - _front = 0
        int length() const
        { return ((_rear + _size) - _front + 1) % _size; }

        void print() const {
            std::cout << "< ";
            if (length() != 0){
                int index = _front;
                while (index != _rear){
                    std::cout << _listArray[index] << " ";
                    index = (index + 1) % _size;
                }
                std::cout << _listArray[_rear] << " ";
            }
            std::cout << ">\n";
        }

    };

    template <class Elem>
    class LQueue: public Queue<Elem>{
    private:
        Link<Elem>* _front;
        Link<Elem>* _rear;
        int _size;
    public:
        const static int DefaultListSize = 20;
        LQueue(int sz = DefaultListSize)
        { _front = _rear = NULL; _size = 0; }
        ~LQueue() { clear(); }
        void clear(){   //Clear queue
            while (_front != NULL){     // Delete each link node
                _rear = _front;
                _front = _front->next;
                delete _rear;
            }
            _rear = NULL;
            _size = 0;
        }
        bool enqueue(const Elem& it){
            if (_rear == NULL)
                _front = _rear = new Link<Elem>(it, NULL);
            else {
                _rear->next = new Link<Elem>(it, NULL);
                _rear = _rear->next;
            }
            _size++;
            return true;
        }
        bool dequeue(Elem& it){ // Remove Elem from front
            if (_size == 0) return false;   //Empty
            it = _front->element;
            Link<Elem>* ltemp = _front;
            _front = _front->next;
            delete ltemp;
            if (_front == NULL) _rear = NULL;   // Dequeued last element
            _size--;
            return true;
        }
        bool frontValue(Elem& it) const {
            if (_size == 0) return false;
            it = _front->element;
            return true;
        }
        int length() const { return _size; }

        void print() const {
            std::cout << "< ";
            if (length() != 0){
                Link<Elem>* ltmp = _front;
                while (ltmp != NULL){
                    std::cout << ltmp->element << " ";
                    ltmp = ltmp->next;
                }
            }
            std::cout << ">\n";
        }
    };
}


#endif //STRUCT_QUEUE_H
