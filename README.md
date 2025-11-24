# Trie Implementation in C++

This repository contains a clean and efficient implementation of a **Trie (prefix tree)** in modern C++. The data structure is designed to support fast prefix-based string operations and is suitable for applications such as autocomplete engines, predictive text systems, dictionary indexing, and prefix-driven analytics.

The implementation focuses on clarity, correctness, and performance while keeping the interface simple and intuitive.

## Overview

A Trie stores words by distributing their characters across a tree-like structure. Each node represents one character and maintains links to its child nodes. This layout enables operations whose complexity depends only on the length of the input string, not on the number of stored elements.

This project implements the core Trie operations commonly required in real-world systems.

## Supported Operations

**Insert (`insert`)**  
Adds a word to the structure by traversing its characters one by one. Nodes are created as needed, and each node maintains a counter that reflects how many words pass through it.

**Search (`search`)**  
Checks whether a complete word exists in the Trie. This is a direct membership test and does not confuse prefixes with full words.

**Prefix Query (`isPrefixIn`)**  
Determines whether a given prefix appears in the structure. This is fundamental for incremental search, autocomplete, and prefix-grouped lookups.

**Erase (`erase`)**  
Removes a word from the Trie. The deletion process uses recursive backtracking to discard nodes that no longer play a role in any remaining word. Shared paths between words are handled safely.

**Count (`count`)**  
Returns the number of stored words that begin with a given prefix. This is enabled by per-node counters that track how many words descend from each branch.

## Example Usage

```cpp
Trie t;

t.insert("code");
t.insert("coder");
t.insert("coding");
t.insert("coffee");

t.search("code");       // true
t.search("cod");        // false

t.isPrefixIn("cod");    // true
t.count("cod");         // 3

t.erase("coder");

t.search("coder");      // false
t.count("cod");         // 2
```

## Internal Design

The Trie uses a node-based structure where each node stores a character and a dynamic list of children. The class itself represents both the root container and all nodes in the structure.

### Node Structure

Each node contains:

- `char val`  
  The character represented by this node. Ordinary characters represent intermediate steps of a word.  
  The special character `'#'` is used as an **end-of-word marker**. Whenever a word finishes, a final child node with value `'#'` is inserted to mark termination.

- `std::vector<Trie*> children`  
  A dynamic list of pointers to child nodes. Children are searched linearly. This avoids assumptions about a fixed alphabet and allows arbitrary characters.

### Root Node

The public constructor:

- `Trie()`  
  Initializes the root as an empty container node with `val = '#'` by convention, but **this root `'#'` is not an end-of-word marker**. It simply acts as the entry point of the structure and as the presence of the empty word that is always in the Trie.

## More on the available operations

### Constructors and Destructors

- `Trie()`  
  Builds the root node.

- `Trie(char init)` (private)  
  Creates a node representing a character in a word.

- `~Trie()`  
  Recursively frees all dynamically allocated children.

### Public Interface

The class exposes the following operations for interacting with the Trie:

- `void insert(std::string entry)`  
  Inserts a word into the structure and records its end using a `'#'` node.

- `bool search(std::string toSearch)`  
  Checks whether a complete word is stored in the Trie.

- `void erase(std::string toDelete)`  
  Removes a word from the Trie if it exists.

- `bool isPrefixIn(std::string prefixToFind)`  
  Determines whether a given prefix is present.

- `int count(std::string prefixToCount)`  
  Counts the number of words that share the given prefix.

### Private Helpers

Two internal mechanisms support the public interface:

- `bool eraseRecursive(std::string toDelete)`  
  Handles recursive deletion and node cleanup.

- `Trie* prefix(std::string prefixToSearch)`  
  Finds the node where traversal of the prefix ends, or returns `nullptr`.

## Possible Improvements

- Add an iterator to traverse all stored words in lexicographical order.
- Implement a memory-efficient version using a compressed trie (radix tree / Patricia trie).
- Support wildcard searches (e.g., patterns with `?` or `*`).
- Add functionality to list all words with a given prefix.
- Add persistence by saving/loading the trie to/from a file.
- Replace raw pointers with smart pointers (`std::unique_ptr`) for safer memory management.
- Add thread-safe operations using mutexes if used in concurrent contexts.
- Optimize the children structure using arrays, `std::unordered_map`, or bitsets depending on the charset.
- Add benchmarks to compare performance with other dictionary data structures.
- Improve testing coverage with edge cases and randomized fuzz tests.


