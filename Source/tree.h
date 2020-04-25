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
    //typedef list<Node*> NodeArray; //we intruduce NodeArray to intruduce a list of pointers
private:
    E element; //name of the node
    Node* parent; //pointer to the parent
    //NodeArray children; //since  a node can have multiple children, this describes a list of pointers to all children
    Node* left; // Left Child, Assuming a node only has 2 children
    Node* right; // Right Child
    bool childless;
public:
    Node(): element(), parent(nullptr), left(nullptr), right(nullptr), childless(true){}; //default constructor
    Node(E el, Node* p, json jch); //recursive constructor
    //Node(E el, Node* p, Node* l, Node* r): element(el), parent(p), left(l), right(r){};
    E getElement(); //function to get the Element
    Node* getParent(); //function to get the Parent
    Node* getLeft();
    Node* getRight();
    bool isRoot() const; //function to see if a Node is the RootNode
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
    void addNode(); // Add another node to the tree

    int getSize() const; // Number of nodes
    bool isEmpty() const; // Is tree empty?
    Position<T> getRoot() const; // Get the root
    list<Position<T>> getPositions() const; // Get position of all nodes

    void load(const string& filename); //function to load a jsonfile in tree-format
    void pushNodes(Node<T>* p);
    void print(Node<T>* node, int spaces = -1, string id = "Root"); // function to print the tree
    string estimate(Organ spec); //function to display the value
};

#endif //PROJECTDT_TREE_H
