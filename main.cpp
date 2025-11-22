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

    delete myTrie;
}
