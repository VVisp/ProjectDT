//
// Created by Stan Brunau on 09/04/2020.
//
#include "simple_format.h"

std::string format(json::iterator j, std::string key) {
    std::string el = j->at(key).dump();
    el.erase(el.find('o')); // Remove > and " characters
    el.erase(remove(el.begin(), el.end(), '"'), el.end());

    return el;
}

std::string format(json j, std::string key) {
    std::string el = j.at(key).dump(); // The value of the first key gets converted into a string
    el.erase(el.find('>')); // Remove > and " characters
    el.erase(remove(el.begin(), el.end(), '"'), el.end());

    return el;
}
