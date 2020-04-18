//
// Created by Stan Brunau on 09/04/2020.
//
#include "simple_format.h"

std::string format(const json& j) {
    std::string el = j.dump();
    el.erase(el.begin());
    return el.substr(0, el.find(' '));
}

// Dit is een algemenere, recursieve load functie die ik heb bedacht
void example_load(json j) {
    for (json::iterator it = j.begin(); it != j.end(); ++it) { // Begin iteration over entire JSON file
        if (it.key() == "name") {
            std::cout << it.key() << " : " << it.value() << "\n"; // Print the key-value pairs with "name" as key
        }
        if (it.key() == "children") {
            for (auto& element : it.value()) { // Converts non-object into object
                example_load(element);
            }
        }
    }
}
