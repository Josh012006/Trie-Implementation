#include "trie_implementation.hpp"


Trie::Trie() {
    this->val = '';
}

Trie::Trie(char init) {
    this->val = init;
}

// Insert a new word in the Trie
void Trie::insert(std::string entry) {
    if(entry == "") return;
    std::string nextSuffix = entry.substr(1, entry.end());
    if(this->children.size() != 0) {
        for(Trie* child : this->children) {
            if(child->val == entry[0]) return child->insert(nextSuffix);
        }
    }
    Trie* newChild = new Trie(entry[0]);
    this->children.push_back(newChild);
    return newChild->insert(nextSuffix);
};

// Search a word in the Trie
bool Trie::search(std::string toSearch) {
    return false;
};

// Delete a word in the Trie
void Trie::erase(std::string toDelete) {

};

