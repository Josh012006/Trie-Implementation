#include "trie_implementation.hpp"



int main() {
    Trie t;

    t.insert("code");
    t.insert("coder");
    t.insert("coding");
    t.insert("coffee");

    std::cout << std::boolalpha <<  t.search("code") << std::endl;       // true
    std::cout << std::boolalpha << t.search("cod") << std::endl;        // false

    std::cout << std::boolalpha << t.isPrefixIn("cod") << std::endl;    // true
    std::cout << t.count("cod") << std::endl;         // 3

    t.erase("coder");

    std::cout << std::boolalpha << t.search("coder") << std::endl;      // false
    std::cout << t.count("cod") << std::endl;         // 2
}
