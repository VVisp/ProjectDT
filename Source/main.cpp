#include <iostream>
#include <fstream>
#include "tree.h"
using namespace std;

int main() {
    ifstream json;
    json.open("tree.json");

    if (!json.is_open()) {
        return 1;
    }

    while (json) {
        string line;
        getline(json, line, ':');

        string leaf;
        json >> leaf;

        leaf.erase(leaf.begin());

        if (leaf == "{") {
            continue;
        }

        cout << leaf << endl;
    }

    json.close();

    return 0;
}
