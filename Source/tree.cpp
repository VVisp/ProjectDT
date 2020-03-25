//
// Created by Stan Brunau on 21/03/2020.
//
#include "tree.h"
#include <iostream>
#include <fstream>

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

        leaf.erase(leaf.begin());

        if (leaf == "{") {
            continue;
        }

        std::cout << leaf << std::endl;
    }

    json.close();
}


/*
std::string &Tree::Position::operator*() {

} */

Tree::Position Tree::Position::parent() const {
    return {};
}

Tree::PositionList Tree::Position::children() const {
    return Tree::PositionList();
}

bool Tree::Position::isRoot() const {
    return false;
}

bool Tree::Position::isExternal() const {
    return false;
}

int Tree::size() const {
    return 0;
}

bool Tree::empty() const {
    return false;
}

Tree::Position Tree::root() const {
    return {};
}

Tree::PositionList Tree::positions() const {
    return Tree::PositionList();
}
