#pragma once

#include <iostream>
#include <vector>

class Trie {
public:
    std::vector<Trie*> children;
    char val;

    // Insert a new word in the Trie
    void insert(std::string entry) {};

    // Search a word in the Trie
    bool search(std::string toSearch) {};

    // Delete a word in the Trie
    void erase(std::string toDelete) {};
};
