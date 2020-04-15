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

template<typename E>
void Node<E>::setChildren(Node *ch) {
    children = ch;
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

template <typename E>
void Tree<E>::load(const string& filename) {
    ifstream file(filename); //the program reads the file 'filename' and puts it in variable 'file'
    json j = json::parse(file); //the 'file' is being put in a json object, using nlohmann's json library
    // TODO: implementeer onderstaande load functie
    cout << "-------------------------------------------------" << "\n";
    cout << "This is an example of the recursive load function: " << "\n\n";
    example_load(j);
    cout << "-------------------------------------------------" << endl;

    op = positions.begin(); // Insertion index refers to beginning of positions

    if (empty) {
        string el = format(j, "name"); // The JSON object gets converted into a string containing the value of the first key
        root = Position<string> {new Node<string>(el, nullptr, {nullptr})}; // The root node gets initialized
        empty = false; // The tree is no longer empty
        positions.insert(op, root); // Insert the root node as the first element of Positions
        size = 1;
        op++; // Increase insertion index
    }

    json::iterator it = j.at("children").begin();
    string el = format(it, "name");

    positions.insert(op, Position<string>{new Node<string>(el, root.v, {nullptr})}); // Insert another node in front
                                                                                        // of root in Positions

    for (auto const& i: positions) {
        cout << i.v->getElement() << endl; // Print de elementen van de Nodes (test)
    }
    // TODO: Veralgemeen bovenstaande functies zodat de rest van de boom kan gemaakt worden
    // TODO: Optimaliseer de code, ruim overbodige stukken op
}

