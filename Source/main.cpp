#include <iostream>
#include <list>
#include "tree.h"
#include "tree.cpp"
#include "lib/json.hpp"
using json = nlohmann::json;
using namespace std;

void print_estimates(Tree<string>* myTree, Organ spec, ofstream &testOutput);
void test_estimates(const string* treeFiles, int fileCount, ofstream &testOutput);
void print_tree(const string* treeFiles, int fileCount);
list<Organ> generate_organs();

int main() {
    ofstream testOutput("testOutput.txt");
    const int fileCount = 5;
    const string treeFiles[fileCount] = {"./trees/rules_d1.json",
                                         "./trees/rules_d2.json",
                                         "./trees/rules_d3.json",
                                         "./trees/rules_d4.json",
                                         "./trees/rules_d5.json"};

    // De output van deze functie is zeer lang, i.p.v printen in de console wordt het geschreven naar een extern bestand
    test_estimates(treeFiles, fileCount, testOutput);
    print_tree(treeFiles, fileCount);

    testOutput.close();
    cout << "Press any button to continue...";
    cin.get();
    return 0;
}

void test_estimates(const string* treeFiles, int fileCount, ofstream &testOutput) {
    Tree<string> myTree = Tree<string>();
    list<Organ> organs = generate_organs();
    try {
        for (int i = 0; i < fileCount; i++) {
            testOutput << "======== Begin Test on File " << i+1 << " ========" <<  '\n';
            myTree.load(treeFiles[i]); // Generate a tree with current file
            testOutput << "------------------------------------" << '\n';
            for (auto const &organ: organs) { // Estimate the values of ALL possible organs
                print_estimates(&myTree, organ, testOutput);
            }
            testOutput << "======== End Test on File " << i+1 << " ========" <<  '\n';
        }
    } catch (const char* msg) {
        cerr << msg << endl;
    }
}

void print_estimates(Tree<string>* myTree, Organ spec, ofstream &testOutput) {
    string price = myTree->estimate(spec); // Gets the estimate price from the tree
    testOutput << "Model: " << spec.model << ", Condition: " << spec.condition << ", Leslie: " << spec.leslie << '\n';
    testOutput << "Estimated price is " << price << '\n';
    testOutput << "------------------------------------" << '\n';
}

void print_tree(const string* treeFiles, int fileCount) {
    string input;
    cout << "Would you like to print a tree? [y/n]: " << endl;
    cin >> input;
    while (input != "y" && input != "n") {
        cout << "Invalid answer!" << endl;
        cout << "Would you like to print a tree? [y/n]: " << endl;
        cin >> input;
    }
    if (input == "y") {
        string str;
        cout << "Enter tree number [1 - 5]: " << endl;
        cin >> str;
        int i = stoi(str) - 1;
        while (i < 0 || i > fileCount) {
            cout << "Invalid number!" << endl;
            cout << "Enter tree number [1 - 5]: " << endl;
            cin >> str;
            i = stoi(str) - 1;
        }
        Tree<string> myTree = Tree<string>();
        myTree.load(treeFiles[i]);
        myTree.print(myTree.getRoot().v, 0);
    }
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