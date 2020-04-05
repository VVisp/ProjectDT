//#include <iostream>
//#include <fstream>
#include "tree.h"
#include "tree.cpp"
using namespace std;

int main() {
    Tree<int> myTree = Tree<int>();
    myTree.print();
    //myTree.load("tree.json");

    return 0;
}
