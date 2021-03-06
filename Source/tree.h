//
// Created by Stan Brunau on 21/03/2020.
//
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "simple_format.h"
#include "lib/json.hpp"
using json = nlohmann::json;

#ifndef PROJECTDT_TREE_H
#define PROJECTDT_TREE_H

using namespace std;

struct Organ {
    string model;
    string condition;
    string leslie;
};

template <typename E>
class Node {
private:
    E element; //name of the node
    Node* parent; //pointer to the parent
    Node* left; // Left Child, Assuming a node only has 2 children
    Node* right; // Right Child
    bool childless;
public:
    Node(): element(), parent(nullptr), left(nullptr), right(nullptr), childless(true){}; //default constructor
    Node(E el, Node* p, json jch); //recursive constructor
    E getElement(); //function to get the Element
    Node* getLeft();
    Node* getRight();
    bool isChildless() const;
};

template <typename G>
struct Position {
    Node<G>* v;
};

template <typename T>
class Tree {
private:
    int size; // Amount of layers inside the tree
    bool empty;
    Position<T> root;
    list<Position<T>> positions;
    typename list<Position<T>>::iterator op;
public:
    Tree():size(0), empty(true), root(Position<T>()), positions(list<Position<T>>()){}; // constuctor: constructs a tree with a single root node
    ~Tree(); // Destructor

    Position<T> getRoot() const; // Get the root

    void load(const string& filename); //function to load a jsonfile in tree-format
    void pushNodes(Node<T>* p);
    void print(Node<T>* node, int spaces = -1, string id = "Root"); // function to print the tree
    string estimate(Organ spec); //function to display the value
};

#endif //PROJECTDT_TREE_H
