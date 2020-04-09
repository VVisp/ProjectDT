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

template<typename E>
list<Node<E>*> Node<E>::getChildren() {
    return list<Node *>();
}

// OUT OF LINE DEFINITIONS VAN CLASS TREE
/*
template<typename T>
Tree<T>::Tree() {
    Node<T> root_node = Node<T>();
    Position<T> myPosition{};
    myPosition.v = &root_node;
    size = 1;
    root.v = myPosition.v;
    empty = false;
}
 */

template<typename T>
void Tree<T>::addNode() {

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
    cout << "Root with element: " << root.v->getElement() << endl;
}

template <typename E>
void Tree<E>::load(const string& filename) {
    ifstream file(filename); //the program reads the file 'filename' and puts it in variable 'file'
    json j = json::parse(file); //the 'file' is being put in a json object, using nlohmann's json library
    string el = j.at("name").dump();
    el.erase(el.find('>'));
    el.erase(remove(el.begin(), el.end(), '"'), el.end());
    Node<string> rootNode = Node<string>(el, nullptr, {nullptr});
    root = Position<string> {&rootNode};
    cout << root.v->getElement() << endl;
}
