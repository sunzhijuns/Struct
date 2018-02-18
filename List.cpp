//
// Created by sunzhijun on 18-2-18.
//

#include "List.h"

namespace structures {


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


    template<class Elem>
    // Insert at front of right partition;
    bool LList<Elem>::insert(const Elem &item) {
        _fence->next = new Link<Elem>(item, _fence->next);
        if (_tail == _fence) _tail = _fence->next;  //new tail
        _rightcnt++;
        return true;
    }

    template<class Elem>
    // Append Elem to end of the list
    bool LList<Elem>::append(const Elem &item) {
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

    template <class Elem> // Insert at front of right partition
    bool DList<Elem>::insert(const Elem & item) {
        _fence->next = new DLink<Elem>(item, _fence, _fence->next);
        if (_fence->next->next != NULL) // if not deleting at end
            _fence->next->next->prev = _fence->next;
        if (_tail == _fence)
            _tail = _fence->next;   //so set tail
        _rightcnt++;                //Added to right
        return true;
    }

    template <class Elem> // Append Elem to end of the list
    bool DList<Elem>::append(const Elem & item) {
        _tail = _tail->next = new DLink<Elem>(item, _tail, NULL);
        _rightcnt++;
        return true;
    }

    template <class Elem> // Remove and return first Elem in right partition;
    bool DList<Elem>::remove(Elem & it) {
        if (_fence->next == NULL) return false; // Empty right
        it = _fence->next->element;             //Remember value
        DLink<Elem>* ltemp = _fence->next;      //Remember link node
        if (ltemp->next != NULL) ltemp->next->prev = _fence;
        else _tail = _fence;
        _fence->next = ltemp->next;
        delete ltemp;
        _rightcnt--;
        return true;
    }

    template <class Elem> // Move fence one step left; no change if left is empty;
    void DList<Elem>::prev() {
        if (_fence != _head)
        { _fence = _fence->prev; _leftcnt--; _rightcnt++; }
    }


    //Set the size of left partition to pos
    template <class Elem>
    bool DList<Elem>::setPos(int pos) {
        if ((pos < 0) || (pos > _rightcnt + _leftcnt)) return false;
        _fence = _head;
        for (int i = 0; i < pos; ++i) _fence = _fence->next;
        return true;
    }

    template <class Elem>
    void DList<Elem>::print() const {
        DLink<Elem>* temp = _head;
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


#include "List.h"

#define LIST_TEST
#ifdef LIST_TEST

struct Point{
    int x;
    int y;
    Point(){
        x = y = 0;
    }
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }

    friend std::ostream&
    operator<<(std::ostream& out, Point point)
    { return out<<"(" << point.x << ", "<< point.y<<")"; }
//    operator<< (){
//
//    }
};

//#define TEST_DLIST_INSERT
#ifdef TEST_DLIST_INSERT

int main(){
    structures::DList<Point> a;
    a.insert(Point(1,1));
    a.insert(Point(1,2));
    a.print();
    Point temp;
    a.remove(temp);
    a.print();
    a.append(Point(2,3));
    a.print();
//    Point temp;
//    for (a.setStart(); a.getValue(temp); a.next()){
//        std::cout << temp << " ";
//    }
//    std::cout << std::endl;
}

#endif

//#define TEST_LLIST_APPEND
#ifdef TEST_LLIST_APPEND
int main(){
    structures::LList<Point> a;
    a.append(Point(1,2));
    a.append(Point(1,3));
    a.print();

    a.setPos(1);
    a.print();

    a.insert(Point(2,4));
    a.print();

    a.append(Point(3,5));
    a.print();
}
#endif

//#define TEST_LLIST_INSERT
#ifdef TEST_LLIST_INSERT
int main() {

    structures::LList<Point> a;
    a.insert(Point(1,2));
    a.insert(Point(1,3));
    a.insert(Point(1,4));
    a.setPos(2);
    a.print();

    a.insert(Point(1,100));
    a.insert(Point(1,99));
    a.print();

    Point temp;
    a.remove(temp);
    std::cout<< temp << "\n";
    a.print();


    structures::LList<int> b;
    b.insert(2);
    b.insert(5);
    b.insert(8);
    b.print();


    return 0;
}

#endif

#endif



