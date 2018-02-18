//
// Created by sunzhijun on 18-2-17.
//

#ifndef STRUCT_LIST_H
#define STRUCT_LIST_H

#include <iostream>

namespace structures {

    template<class Elem>
    class List {
    public:
        virtual void clear() = 0;

        virtual bool insert(const Elem &) = 0;/* ---|i----- */
        virtual bool append(const Elem &) = 0;/* ---|-----a */
        virtual bool remove(Elem &) = 0;/* ---|r----- */
        virtual void setStart() = 0;/* |-------- */
        virtual void setEnd() = 0;/* --------| */
        virtual void prev() = 0;/* ---|-----  -> --|------  */
        virtual void next() = 0;/* ---|-----  -> ----|----  */
        virtual int leftLength() const = 0;/* 3 */
        virtual int rightLength() const = 0;/* 5 */
        virtual bool setPos(int pos) = 0;/* ---|-----  pos = 3 */
        virtual bool getValue(Elem &) const = 0;/* ---|v---- */
        virtual void print() const = 0;

        bool find(List<Elem> &L, Elem K) {
            Elem it;
            for (L.setStart(); L.getValue(it); L.next()) {
                if (K == it) return true;
            }
            return false;
        }

    };

    template<class Elem>
    class AList : public List<Elem> {
    private:
        int _maxSize;
        int _listSize;
        int _fence;
        Elem* _listArray;

    public:
        AList(int size = 32){
            _maxSize = size;
            _listSize = _fence = 0;
            _listArray = new Elem[_maxSize];
        }
        ~AList(){
            delete[] _listArray;
        }
        void clear(){
            delete[] _listArray;
            _listSize = _fence = 0;
            _listArray = new Elem[_maxSize];
        }
        bool insert(const Elem&);
        bool append(const Elem&);
        bool remove(Elem&);

        void setStart() { _fence = 0; }
        void setEnd() { _fence = _listSize; }
        void prev() { if (_fence != 0) _fence--; }
        void next() { if (_fence <= _listSize) _fence++; }
        int leftLength() const { return _fence; }
        int rightLength() const { return _listSize - _fence; }
        bool setPos(int pos) {
            if (pos >= 0 && pos <= _listSize) { _fence = pos; }
            return pos >= 0 && pos <= _listSize;
        }
        bool getValue(Elem& it) const{
            if (rightLength() == 0) {
                return false;
            }
            else{
                it = _listArray[_fence];
                return true;
            }
        }
        void print() const {
            int temp = 0;
            std::cout << "< ";
            while (temp < _fence) std::cout << _listArray[temp++] << " ";
            std::cout << "| ";
            while (temp < _listSize) std::cout << _listArray[temp++] << " ";
            std::cout << ">\n";
        }
    };
    template <class Elem>//Insert at front of partition
    bool AList<Elem>::insert(const Elem& item) {
        if (_listSize == _maxSize) return false;    //List is full;
        for (int i=_listSize; i>_fence; i--)        //Shift Elems up
            _listArray[i] = _listArray[i-1];        //  to make room
        _listArray[_fence] = item;
        _listSize++;                //Increment list size
        return true;
    }
    template <class Elem>// Append Element to end of the list
    bool AList<Elem>::append(const Elem & item) {
        if (_listSize == _maxSize) return false;
        _listArray[_listSize++] = item;
        return true;
    }
    //Remove and return first Elem in right partition
    template <class Elem>
    bool AList<Elem>::remove(Elem & item) {
        if (rightLength() == 0) return false;   //Nothing in right
        item = _listArray[_fence];              //Copy removed Elem
        for (int i=_fence; i<_listSize-1; i++)  //Shift them down
            _listArray[i] = _listArray[i+1];    //Decrement size
        _listSize--;
        return true;
    }


//    namespace link {
        // Singly-linked list node
        template<class Elem>
        class Link {
        public:
            Elem element;       //Value for this node
            Link *next;         //Pointer to next node in list
            Link(const Elem &element, Link *next = NULL) {
                this->element = element;
                this->next = next;
            }

            Link(Link *next = NULL) { this->next = next; }
        };
//    }


    template <class Elem>
    class LList:public List<Elem>{
    private:
        Link<Elem>* _head;  //Pointer to list header
        Link<Elem>* _tail;  //Pointer to last Elem in list
        Link<Elem>* _fence; //Last element on left side;
        int _leftcnt;
        int _rightcnt;
        void init(){
            _fence = _tail = _head = new Link<Elem>;
            _leftcnt = _rightcnt = 0;
        }
        void removeall(){
            while (_head != NULL){
                _fence = _head;
                _head = _head->next;
                delete _fence;
            }
        }

        const int DefaultListSize = 32;
    public:
        LList(int size = DefaultListSize) { init(); }
        ~LList() { removeall(); }
        void clear() { removeall(); init(); }
        bool insert(const Elem&);
        bool append(const Elem&);
        bool remove(Elem&);
        void setStart()
        { _fence = _head; _rightcnt += _leftcnt; _leftcnt = 0; }
        void setEnd()
        { _fence = _tail; _leftcnt += _rightcnt; _rightcnt = 0; }
        void prev();
        void next(){
            if (_fence != _tail)
            { _fence = _fence->next; _rightcnt--; _leftcnt++; }
        }
        int leftLength() const { return _leftcnt; }
        int rightLength() const { return _rightcnt; }
        bool setPos(int pos);
        bool getValue(Elem& it) const {
            if (rightLength() == 0) return false;
            it = _fence->next->element;
            return true;
        }
        void print() const;

    };

    template <class Elem> // Insert at front of right partition;
    bool LList<Elem>::insert(const Elem & item) {
        _fence->next = new Link<Elem>(item, _fence->next);
        if (_tail == _fence) _tail = _fence->next;  //new tail
        _rightcnt++;
        return true;
    }

    template <class Elem>// Append Elem to end of the list
    bool LList<Elem>::append(const Elem & item) {
        _tail = _tail->next = new Link<Elem>(item, NULL);
        _rightcnt++;
        return true;
    }

    template <class Elem>//Remove and return first Elem in right partition
    bool LList<Elem>::remove(Elem & it) {
        if (_fence->next == NULL) return false; //Empty right
        it = _fence->next->element;
        Link<Elem>* ltemp = _fence->next;
        _fence->next = ltemp->next;
        if (_tail == ltemp) _tail = _fence;
        delete ltemp;
        _rightcnt--;
        return true;

    }

    //Move fence one step left; no change if left is empty
    template <class Elem>
    void LList<Elem>::prev() {
        if (_fence == _head) return; // No previous Elem
        Link<Elem>* temp = _head;
        while (temp->next != _fence) temp = temp->next;
        _fence = temp;
        _leftcnt--; _rightcnt++;
    }

    //Set the size of left partition to pos
    template <class Elem>
    bool LList<Elem>::setPos(int pos) {
        if ((pos < 0) || (pos > _rightcnt + _leftcnt)) return false;
        _fence = _head;
        for (int i = 0; i < pos; ++i) _fence = _fence->next;
        return true;
    }

    template <class Elem>
    void LList<Elem>::print() const {
        Link<Elem>* temp = _head;
        std::cout << "< ";
        while (temp != _fence){
            std::cout << temp->next->element << " ";
            temp = temp->next;
        }
        std::cout << "| ";
        while (temp->next != NULL){
            std::cout << temp->next->element << " ";
            temp = temp->next;
        }
        std::cout << ">\n";
    }
}

#endif //STRUCT_LIST_H
