//#include <iostream>
//#include <fstream>
#include <string>
#include "tree.h"
#include "tree.cpp"
#include "lib/json.hpp"
using json = nlohmann::json;
using namespace std;

int main() {
    Tree<string> myTree = Tree<string>();
    myTree.load("tree.json");
    myTree.print();

    return 0;
}
