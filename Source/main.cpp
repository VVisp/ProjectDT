//#include <iostream>
//#include <fstream>
#include <string>
#include <list>
#include "tree.h"
#include "tree.cpp"
#include "lib/json.hpp"
using json = nlohmann::json;
using namespace std;

void print_estimates(Tree<string>* myTree, Organ spec);
void test_estimates();
list<Organ> generate_organs();

int main() {
    test_estimates();
    return 0;
}

void test_estimates() {
    const int fileCount = 5;
    const string treeFiles[fileCount] = {"./trees/rules_d1.json",
                                         "./trees/rules_d2.json",
                                         "./trees/rules_d3.json",
                                         "./trees/rules_d4.json",
                                         "./trees/rules_d5.json"};
    Tree<string> myTree = Tree<string>();
    list<Organ> organs = generate_organs();

    try {
        for (int i = 0; i < fileCount; i++) {
            cout << "======== Begin Test on File " << i+1 << " ========" <<  endl;
            myTree.load(treeFiles[i]); // Generate a tree with current file
            cout << "------------------------------------" << endl;
            for (auto const &organ: organs) { // Estimate the values of ALL possible organs
                print_estimates(&myTree, organ);
            }
            cout << "======== End Test on File " << i+1 << " ========" <<  endl;
        }
    } catch (const char* msg) {
        cerr << msg << endl;
    }
}

void print_estimates(Tree<string>* myTree, Organ spec) {
    string price = myTree->estimate(spec); // Gets the estimate price from the tree
    cout << "Model: " << spec.model << ", Condition: " << spec.condition << ", Leslie: " << spec.leslie << '\n';
    cout << "Estimated price is " << price << '\n';
    cout << "------------------------------------" << '\n';
}

list<Organ> generate_organs() { // Generates a list of Organs with all possible combinations of specifications
    list<Organ> organs;
    const int mCnt = 5;
    const int cCnt = 3;
    const int lCnt = 2;
    const string models[mCnt] = {"Model_B3", "Model_T202", "Model_A100", "Model_M102", "Model_E112"};
    const string conditions[cCnt] = {"Condition_excellent", "Condition_good", "Condition_fair"};
    const string leslies[lCnt] = {"Leslie_yes", "Leslie_no"};

    for (const auto & model : models) {
        for (const auto & condition : conditions) {
            for (const auto & leslie : leslies) {
                organs.push_back(Organ{model, condition, leslie});
            }
        }
    }

    return organs;
}