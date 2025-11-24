#include "trie_implementation.hpp"



int main() {
    Trie* myTrie = new Trie();

    myTrie->insert("hello");
    myTrie->insert("helium");

    std::cout << myTrie->children[0]->val << std::endl;
    std::cout << myTrie->children[0]->children[0]->val << std::endl;
    std::cout << myTrie->children[0]->children[0]->children[0]->val << std::endl;

    for(Trie* child : myTrie->children[0]->children[0]->children[0]->children) {
        std::cout << child->val << std::endl;
    }

    auto seen = [myTrie] (std::string text) {
        std::cout << text + " " + ((myTrie->search(text)) ? "was" : "wasn't") + " found" << std::endl;
    };

    seen("hello");
    seen("helium");
    seen("not_inside");

    myTrie->erase("hello");

    seen("hello");
    seen("helium");

    delete myTrie;
}
