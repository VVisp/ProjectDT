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
        left = new Node<E>(format(jch[0]["name"]), this, jch[0]["children"]);
        right = new Node<E>(format(jch[1]["name"]), this, jch[1]["children"]);
        childless = false;
    } else {childless = true;}
}


// OUT OF LINE DEFINITIONS VAN CLASS TREE

template<typename T>
Tree<T>::~Tree() {
    for (auto const& i: positions) {
        delete i.v;
    }
}

template<typename T>
Position<T> Tree<T>::getRoot() const {
    return root;
}

//De 'children' moet nog gemaakt worden, of vervangen worden door iets anders. Dit is bedoeld een Array van de kinderen te zijn
template <typename T>
void Tree<T>::print(Node<T>* node, int spaties, string id) {
    spaties++; //verhoog de insprong met 1
    Node<T>* leftChild = node->getLeft();
    Node<T>* rightChild = node->getRight();
    string spatiestring = "        "; //maak een 'insprong'
    for (int i = 0; i < spaties; i++) { //print het nodige aantal
        cout << spatiestring;           //insprongen
    }
    cout << "->" << id << ": ";
    cout << node->getElement() << endl; //print het effectieve element
    if (!node->isChildless()) { // Indien er kinderen zijn, print de kinderen
        print(leftChild, spaties, "True");
        print(rightChild, spaties, "False");
    }
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
    if (!file) {
        throw "File not found";
    }
    json j = json::parse(file); //the 'file' is being put in a json object, using nlohmann's json library

    root = Position<E>{new Node<E>(format(j["name"]), nullptr, j["children"])};
    positions.push_back(root);

    pushNodes(root.v);
    empty = false;
    file.close();
}

template<typename T>
string Tree<T>::estimate(Organ spec) {
    // Left = True, Right = False
    Node<T>* current = root.v;
    while (!current->isChildless()) {
        string el = current->getElement();
        if (spec.model == el || spec.condition == el || spec.leslie == el) {
            current = current->getLeft();
            continue;
        }
        current = current->getRight();
    }
    return current->getElement();
}
