//
// Created by sunzhijun on 18-2-18.
//

#ifndef STRUCT_DICTIONARY_H
#define STRUCT_DICTIONARY_H


#include "List.h"

namespace structures {

    // The Dictionary abstract class. KEComp compares a key
    // and an element. EEComp compares two elements.
    template <class Key, class Elem, class KEComp, class EEComp>
    class Dictionary{
        // Reinitialize dictionary
        virtual void clear() = 0;
        // Insert an element. Return true if insert is
        // successful, false otherwise.
        virtual bool insert(const Elem&) = 0;
        // Remove some element matching Key. Return true if such
        // exists. false otherwise. If multiple entries match
        // Key, an arbitrary one is removed;
        virtual bool remove(const Key&, Elem&) = 0;
        // Remove and return an arbitrary element from dictionary.
        // Return true if some element is found, false otherwise.
        virtual bool removeAny(Elem&) = 0;
        // Return a copy of some Elem matching Key. Return true
        // if such exists, false otherwise. If multiple element
        // match Key, return an arbitrary one.
        virtual bool find(const Key&, Elem&) const = 0;
        // Return the number of elements in the dictionary.
        virtual int size() = 0;
    };

    // Dictionary implemented with an unsorted array-based list
    template <class Key, class Elem, class KEComp, class EEComp>
    class UALdict:public Dictionary<Key, Elem, KEComp, EEComp>{
    private:
        AList<Elem>* _list;
        const static int DefaultListSize = 20;
    public:
        UALdict(int size = DefaultListSize)
        { _list = new AList<Elem>(size); }
        ~UALdict() { delete _list; }
        void clear() { _list->clear(); }
        bool insert(const Elem& e) { return _list->append(e); }
        bool remove(const Key& k, Elem&e){
            for (_list->setStart(); _list->getValue(e); _list->next())
                if (KEComp::eq(k, e)){
                    _list->remove(e);
                    return true;
                }
            return false;
        }
        bool removeAny(Elem& e){
            if (size() == 0) return false;
            _list->setEnd();
            _list->prev();
            _list->remove(e);
            return true;
        }

        bool find(const Key& k, Elem& e) const {
            for (_list->setStart(); _list->getValue(e); _list->next())
                if (KEComp::eq(k, e)) return true;
            return false;
        }

        int size()
        { return _list->leftLength() + _list->rightLength(); }
    };

    template <class Key, class Elem, class KEComp, class EEComp>
    class SALdict:public Dictionary<Key, Elem, KEComp, EEComp>{
    private:
        SAList<Elem, EEComp>* _list;
    public:
        const static int DefaultListSize = 20;
        SALdict(int size = DefaultListSize)
        { _list = new SAList<Elem, EEComp>(size); }
        ~SALdict() { delete _list; }
        void clear() { _list->clear(); }
        bool insert(const Elem& e)
        { _list->insert(e); }
        bool remove(const Key& k, Elem&e){
            for (_list->setStart(); _list->getValue(e); _list->next())
                if (KEComp::eq(k, e)){
                    _list->remove(e);
                    return true;
                }
            return false;
        }
        bool removeAny(Elem& e){
            if (size() == 0) return false;
            _list->setEnd();
            _list->prev();
            _list->remove(e);
            return true;
        }

        bool find(const Key& k, Elem& e) const {
            int left = 0;
            int right = _list->leftLength() + _list->rightLength() - 1;
            while (left <= right){
                int mid = left + (right - left) / 2;
                _list->setPos(mid);
                _list->getValue(e);
                if (KEComp::eq(k, e)) return true;
                else if (KEComp::lt(k,e))
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return false;
        }

        void print() const
        { _list->print(); }

        int size()
        { return _list->leftLength() + _list->rightLength(); }
    };

}

#endif //STRUCT_DICTIONARY_H
