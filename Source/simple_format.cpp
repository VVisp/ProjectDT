//
// Created by Stan Brunau on 09/04/2020.
//
#include "simple_format.h"

std::string format(json j, std::string key) {
    std::string el = j.at(key).dump();
    el.erase(el.find('>'));
    el.erase(remove(el.begin(), el.end(), '"'), el.end());

    return el;
}
