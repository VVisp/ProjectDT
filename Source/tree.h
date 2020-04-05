//
// Created by Stan Brunau on 21/03/2020.
//
#include <list>
#include <string>
#include <iostream>

#ifndef PROJECTDT_TREE_H
#define PROJECTDT_TREE_H

using namespace std;

template <typename E>
class Node {
private:
    E element;
    Node* parent;
    Node* children;
public:
    Node(): element(), parent(nullptr), children(nullptr){};
    E getElement();
    Node* getParent();
    list<Node*> getChildren();
    bool isRoot() const;
};

template <typename G>
struct Position {
    Node<G>* v;
};

template <typename T>
class Tree {
private:
    int size;
    bool empty;
    Position<T> root;
    list<Position<T>> positions;
public:
    Tree();

    int getSize() const; // Number of nodes
    bool isEmpty() const; // Is tree empty?
    Position<T> getRoot() const; // Get the root
    list<Position<T>> getPositions() const; // Get position of all nodes

    void print();
};

/*
void Tree::load(const std::string& filename) {
    std::ifstream json;
    json.open(filename);

    if (!json.is_open()) {
        return;
    }

    while (json) {
        std::string line;
        getline(json, line, ':');

        std::string leaf;
        json >> leaf;

        //leaf.erase(leaf.begin());

        if (leaf == "{") {
            continue;
        }

        std::cout << leaf << std::endl;
    }

    json.close();
}
*/

#endif //PROJECTDT_TREE_H
