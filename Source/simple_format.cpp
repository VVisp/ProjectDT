//
// Created by Stan Brunau on 09/04/2020.
//
#include "simple_format.h"

std::string format(const json& j) {
    std::string el = j.dump();
    el.erase(el.begin());
    return el.substr(0, el.find(' '));
}
