#include "trie_implementation.hpp"

// Constructors
Trie::Trie() {
    this->val = '#';
}
Trie::Trie(char init) {
    this->val = init;
}

// Destructor
Trie::~Trie() {

}

// Insert a new word in the Trie
void Trie::insert(std::string entry) {
    if(entry == "") {
        Trie* endNode = new Trie('#');
        this->children.push_back(endNode);
        return;
    }
    std::string nextSuffix = entry.substr(1, entry.length() - 1);
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
    if(toSearch == "") {
        for(Trie* child : this->children) {
            if(child->val == '#')
                return true;
        }
    } else {
        for(Trie* child : this->children) {
            if(child->val == toSearch[0])
                return child->search(toSearch.substr(1, toSearch.length() - 1));
        }
    }
    return false;
};

// Delete a word in the Trie
bool Trie::erase(std::string toDelete) {
    if(toDelete == "") return true;

//    std::string actual
//    while(true) {
//
//    }
return false;
};

