#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * Coded by Josué Mongan on 21/11/2025.
 * A simple implementation of the trie data-structure.
 */
class Trie {
    public:
        // Attributes
        std::vector<Trie*> children;
        char val;


        // Constructors and destructors
        /**
         * Basic constructor for the Trie class.
         * Initializes the root with the special character #.
         */
        Trie();

        /**
         * The class' destructor.
         */
        ~Trie();


        // Methods
        /**
         * Used to insert a word in the trie.
         * @param entry the word to insert in the trie.
         */
        void insert(std::string entry);

        /**
         * Used to search a word in the trie.
         * @param toSearch is the word to search.
         * @return true if the word is found and false otherwise.
         */
        bool search(std::string toSearch);

        /**
         * Used to remove a word from the trie.
         * @param toDelete the word that must be deleted.
         */
        void erase(std::string toDelete);

        /**
         * Is used to check if a prefix is present in the Trie.
         * @param prefixToFind the prefix that must be found.
         * @return true if the prefix is present in the Trie.
         */
        bool isPrefixIn(std::string prefixToFind);

        /**
         * Helps to count the number of inserted words that have the prefix.
         * @param prefixToCount the prefix we want to consider.
         * @return the number of words with in the Trie that prefix.
         */
        int count(std::string prefixToCount);

    private:
        // Constructors and destructors
        /**
         * A constructor that initializes the value of the node.
         * @param init is a character that will be the value of the node (trie) created.
         */
        Trie(char init);

        // Methods
        /**
         * Used to remove a word from the trie.
         * @param toDelete the word that must be deleted.
         * @return false if the word wasn't found or the character
         * shouldn't be deleted because it has other children.
         */
        bool eraseRecursive(std::string toDelete);

        /**
         * Used to search a prefix in the Trie.
         * @param prefixToSearch the prefix we want to find.
         * @return where the matches stopped.
         */
        Trie* prefix(std::string prefixToSearch);

        /**
         * Used to count the number of distinct suffixes found from this point in
         * the Trie.
         * @return the number of suffixes found.
         */
        int countWords();
};
