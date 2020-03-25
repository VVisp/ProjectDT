//
// Created by Stan Brunau on 21/03/2020.
//
#include <list>
#include <string>

#ifndef PROJECTDT_TREE_H
#define PROJECTDT_TREE_H

class Node {
    std::string element;
    Node* parent;
    Node* children;
    Node(): element(), parent(nullptr), children(nullptr){}; //CONSTRUCTOR
};

class Tree {
public:
    class Position {
    private:
        Node* v;
    public:
        typedef std::list<Position> PositionList;

        //std::string& operator*();
        Position parent() const;
        PositionList children() const;
        bool isRoot() const;
        bool isExternal() const;

        friend class Tree;
    };
    typedef std::list<Position> PositionList;

    int size() const;
    bool empty() const;
    Position root() const;
    PositionList positions() const;

    void load(const std::string&);
};

#endif //PROJECTDT_TREE_H
