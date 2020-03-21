//
// Created by Stan Brunau on 21/03/2020.
//
#include <list>
#ifndef PROJECTDT_TREE_H
#define PROJECTDT_TREE_H

template <typename T>
class Node {
    T element;
    Node* parent;
    Node* children;
    Node(): element(), parent(nullptr), children(nullptr){}; //CONSTRUCTOR
};

template <typename T>
class Position;

template <typename T>
class Tree {
public:
    typedef std::list<Position<T>> PositionList;
    template <typename E>
    class Position {
    private:
        Node<E>* v;
    public:
        E& operator*();
        Position parent() const;
        PositionList children() const;
        bool isRoot() const;
        bool isExternal() const;

        template <typename G>
        friend class Tree;
    };

    int size() const;
    bool empty() const;
    Position<T> root() const;
    PositionList positions() const;
};

#endif //PROJECTDT_TREE_H
