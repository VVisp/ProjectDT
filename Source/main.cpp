//#include <iostream>
//#include <fstream>
#include <string>
#include "tree.h"
#include "tree.cpp"
#include "lib/json.hpp"
using json = nlohmann::json;
using namespace std;

void test_estimates(Tree<string>* myTree, Organ spec);

int main() {
    Tree<string> myTree = Tree<string>();
    myTree.load("tree.json");
    myTree.print();

    test_estimates(&myTree,Organ{"Model_B3", "None"});
    test_estimates(&myTree,Organ{"None", "Condition_fair"});
    test_estimates(&myTree,Organ{"None", "None"});

    return 0;
}

void test_estimates(Tree<string>* myTree, Organ spec) {
    string price = myTree->estimate(spec);
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
    cout << "Model: " << spec.model << ", Condition: " << spec.condition << '\n';
    cout << "Estimated price is " << price << '\n';
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
}