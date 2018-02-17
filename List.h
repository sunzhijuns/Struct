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
    template <class Elem>
    bool AList<Elem>::remove(Elem & item) {
        if (rightLength() == 0) return false;
        item = _listArray[_fence];
        for (int i=_fence; i<_listSize-1; i++)
            _listArray[i] = _listArray[i+1];
        _listSize--;
        return true;
    }

}

#endif //STRUCT_LIST_H
