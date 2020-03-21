//
// Created by Stan Brunau on 21/03/2020.
//
#include "tree.h"

// Position

template<typename T>
template<typename E>
E &Tree<T>::Position<E>::operator*() {
    //...
}

template<typename T>
template<typename E>
bool Tree<T>::Position<E>::isRoot() const {
    return false;
}

template<typename T>
template<typename E>
bool Tree<T>::Position<E>::isExternal() const {
    return false;
}


// Tree

template<typename T>
int Tree<T>::size() const {
    return 0;
}

template<typename T>
bool Tree<T>::empty() const {
    return false;
}
