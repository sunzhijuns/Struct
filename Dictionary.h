//
// Created by sunzhijun on 18-2-18.
//

#ifndef STRUCT_DICTIONARY_H
#define STRUCT_DICTIONARY_H


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

}

#endif //STRUCT_DICTIONARY_H
