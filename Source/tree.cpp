//
// Created by Stan Brunau on 21/03/2020.
//
#include "tree.h"

// OUT OF LINE DEFINITIONS VAN CLASS NODE

template<typename E>
E Node<E>::getElement() {
    return element;
}

template<typename E>
Node<E>* Node<E>::getParent() {
    return nullptr;
}

template<typename E>
bool Node<E>::isRoot() const {
    return parent == nullptr;
}

// OUT OF LINE DEFINITIONS VAN CLASS TREE

template<typename T>
Tree<T>::Tree() {
    Node<T> myNode = Node<T>();
    Position<T> myPosition{};
    myPosition.v = &myNode;
    size = 1;
    root.v = myPosition.v;
    empty = false;
}

template<typename T>
int Tree<T>::getSize() const {
    return size;
}

template<typename T>
bool Tree<T>::isEmpty() const {
    return empty;
}

template<typename T>
Position<T> Tree<T>::getRoot() const {
    return Position<T>();
}

template<typename T>
list<Position<T>> Tree<T>::getPositions() const {
    return list<Position<T>>();
}

template<typename T>
void Tree<T>::print() {
    cout << "Tree with root: " << root.v << endl;
}
