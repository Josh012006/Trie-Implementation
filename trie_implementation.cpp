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
    Trie* foundPrefix = this->prefix(toSearch);
    if(foundPrefix != nullptr) {
        for(Trie* child : foundPrefix->children) {
            if(child->val == '#')
                return true;
        }
    }
    return false;
};


// See if a prefix is in the Trie
bool Trie::isPrefixIn(std::string prefixToFind) {
    return this->prefix(prefixToFind) != nullptr;
}

// Search till the prefix is found
Trie* Trie::prefix(std::string prefixToSearch) {
    if(prefixToSearch == "") {
        return this;
    } else {
        for(Trie* child : this->children) {
            if(child->val == prefixToSearch[0])
                return child->prefix(prefixToSearch.substr(1, prefixToSearch.length() - 1));
        }
    }
    return nullptr;
}

// Delete a word in the Trie
void Trie::erase(std::string toDelete) {
    this->eraseRecursive(toDelete);
}

// Delete a word in the Trie recursively
bool Trie::eraseRecursive(std::string toDelete) {
    if(toDelete == "") {
        return true;
    }

    Trie* toTest = nullptr;
    int toTestIdx;
    for(int i = 0; i < this->children.size(); i++) {
        Trie* child = this->children[i];
        if(child->val == toDelete[0]) {
            toTest = child;
            toTestIdx = i;
        }
    }
    if(toTest == nullptr) return false;

    std::string nextSuffix = toDelete.substr(1, toDelete.length() - 1);
    if(toTest->eraseRecursive(nextSuffix)) {
        this->children.erase(this->children.begin() + toTestIdx);
    }

    return this->children.empty();
};

