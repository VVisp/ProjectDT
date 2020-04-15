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
            // This conversion could probably be done without a loop
            // However, a different solution has not yet been found
        }
    }
}
