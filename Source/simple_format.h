//
// Created by Stan Brunau on 09/04/2020.
//
#include <string>
#include "lib/json.hpp"
using json = nlohmann::json;

#ifndef PROJECTDT_SIMPLE_FORMAT_H
#define PROJECTDT_SIMPLE_FORMAT_H

std::string format(json j, std::string key);

#endif //PROJECTDT_SIMPLE_FORMAT_H
