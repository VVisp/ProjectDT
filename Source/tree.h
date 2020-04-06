//
// Created by Stan Brunau on 21/03/2020.
//
#include <list>
#include <string>
#include <iostream>

#include "lib/json.hpp"
using json = nlohmann::json;

#ifndef PROJECTDT_TREE_H
#define PROJECTDT_TREE_H

using namespace std;

template <typename E>
class Node {
    typedef list<Node*> NodeArray; //we intruduce NodeArray to intruduce a list of pointers
private:
    E element; //name of the node
    Node* parent; //pointer to the parent
    NodeArray children; //since  a node can have multiple children, this describes a list of pointers to all children
public:
    Node(): element(), parent(nullptr), children(NULL){}; //default constructor
    Node(E el, Node* par = nullptr, json child = Null, int& length = 0); //parameter constructor
    E getElement(); //function to get the Element
    Node* getParent(); //function to get the Parent
    list<Node*> getChildren(); //function to get the Children
    bool isRoot() const; //function to see if a Node is the RootNode
};

template <typename E> 
Node<E>::Node(E el, Node* par, json child, int& length) {
    element = el;
    parent = par;
    if (!child.isRoot()) { //if the Node is not a Root, process its children
        length++;
        NodeArray ChildrenArray;
        //todo: gebruik functie om de nude een level omhoog te duwen zodat het kind hier kan komen
        // voer deze functie dan uit op alle kinderen om zo recursief heel de boom op te bouwen
        children = ChildrenArray
    }
};



template <typename G>
struct Position {
    Node<G>* v;
};



template <typename T>
class Tree {
private:
    int size; //
    bool empty;
    Position<T> root;
    list<Position<T>> positions;
public:
    Tree(); // constuctor
    int levels; // the number of levels in the tree
    Node<T>* rootNode; //The base level of the tree

    int getSize() const; // Number of nodes
    bool isEmpty() const; // Is tree empty?
    Position<T> getRoot() const; // Get the root
    list<Position<T>> getPositions() const; // Get position of all nodes

    void load(string filename); //function to load a jsonfile in tree-format
    void print(); // function to print the tree
    //string estimate(... //function to display the value
};


void Tree<T>::Tree():rootNode(nullptr), lengte(0){

}


void Tree<E>::load<T>(string filename) {
    ifstream file(filename); //the program reads the file 'filename' and puts it in variable 'file'
    json j = json::parse(file); //the 'file' is being put in a json object, using nlohmann's json library
    json jsonchildren = j["children"];
    rootNode = new Node<E>(j["name"], nulptr, jsonchildren, levels);

}



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
