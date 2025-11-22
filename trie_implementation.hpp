#pragma once

#include <iostream>
#include <vector>
#include <string>

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
         * Initializes a root with the special character #.
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

    private:
        // Constructors and destructors
        /**
         * A constructor that initializes the value of the node.
         * @param init is a character that will be the value of the node (trie) created.
         */
        Trie(char init);
};
