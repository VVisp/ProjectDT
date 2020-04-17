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
Node<E> *Node<E>::getLeft() {
    return left;
}

template<typename E>
Node<E> *Node<E>::getRight() {
    return right;
}

template<typename E>
bool Node<E>::isChildless() const {
    return childless;
}

template<typename E>
Node<E>::Node(E el, Node *p, json jch) {
    element = el;
    parent = p;
    if(!jch.is_null()) {
        left = new Node<E>(jch[0]["name"], this, jch[0]["children"]);
        right = new Node<E>(jch[1]["name"], this, jch[1]["children"]);
        childless = false;
    } else {childless = true;}
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
Tree<T>::~Tree() {
    for (auto const& i: positions) {
        delete i.v;
    }
}

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

template<typename T>
void Tree<T>::pushNodes(Node<T> *p) {
    if (!p->isChildless()) {
        positions.push_back(Position<T>{p->getLeft()});
        positions.push_back(Position<T>{p->getRight()});
        pushNodes(p->getLeft());
        pushNodes(p->getRight());
    }
}

template <typename E>
void Tree<E>::load(const string& filename) {
    ifstream file(filename); //the program reads the file 'filename' and puts it in variable 'file'
    json j = json::parse(file); //the 'file' is being put in a json object, using nlohmann's json library

    root = Position<E>{new Node<E>(j["name"], nullptr, j["children"])};
    positions.push_back(root);

    pushNodes(root.v);

    for (auto const& i: positions) {
        cout << i.v->getElement() << endl;
    }
}
