# Tree Data Structure and Iterators

## Overview

This assignment involves implementing a generic tree data structure in C++ that supports various types of nodes and provides different traversal methods. The tree supports multiple child nodes and includes iterators for pre-order, post-order, in-order, DFS, and BFS traversals. Additionally, we ensure that pre-order, post-order, and in-order traversals are only applied to binary trees, and we switch to DFS traversal for non-binary trees.

## Files

- `Node.hpp`: Contains the definition and implementation of the `Node` class.
- `Tree.hpp`: Contains the definition and implementation of the `Tree` class and its iterators.
- `complex.hpp`: Contains the definition and implementation of the `Complex` class (used for testing).
- `main.cpp`: Contains the main function to demonstrate and test the tree functionalities.
- `test.cpp`: Contains various test functions to validate the tree functionalities.
- `makefile`: Contains the makefile to compile the project and run tests.

## Node Class

The `Node` class represents a node in the tree. Each node contains a value and a list of children.

### Functions

- `Node(T val)`: Constructor to initialize a node with a given value.
- `~Node()`: Destructor to clean up the node and its children.
- `void add_child(Node<T>* child)`: Adds a child node.
- `T get_value() const`: Returns the value of the node.

## Tree Class

The `Tree` class represents the tree data structure. It supports adding nodes, clearing the tree, and generating DOT files for visualization.

### Functions

- `Tree()`: Constructor to initialize an empty tree.
- `~Tree()`: Destructor to clean up the tree.
- `void clear()`: Clears the entire tree.
- `void clear(Node<T>* node)`: Clears a specific node and its children.
- `void add_root(const Node<T>& node)`: Adds a root node to the tree.
- `Node<T>* get_root() const`: Returns the root node of the tree.
- `void add_sub_node(const Node<T>& parent, const Node<T>& child)`: Adds a child node to a parent node.
- `Node<T>* find_node(Node<T>* current, const Node<T>& target)`: Finds a node in the tree using DFS.
- `void to_dot(const std::string& filename) const`: Generates a DOT file representing the tree.
- `void to_dot_helper(std::ofstream& file, Node<T>* node) const`: Helper function to create edges between nodes for the DOT file.

## Iterators

### PreOrderIterator

Iterates through the tree in pre-order (current node -> left subtree -> right subtree). This is only supported for binary trees. For non-binary trees, it defaults to DFS traversal.

### PostOrderIterator

Iterates through the tree in post-order (left subtree -> right subtree -> current node). This is only supported for binary trees. For non-binary trees, it defaults to DFS traversal.

### InOrderIterator

Iterates through the tree in in-order (left subtree -> current node -> right subtree). This is only supported for binary trees. For non-binary trees, it defaults to DFS traversal.

### DFSIterator

Iterates through the tree using Depth-First Search (DFS) traversal.

### BFSIterator

Iterates through the tree using Breadth-First Search (BFS) traversal.

### HeapIterator

Iterates through the tree nodes in a heap-like order.

## Assignment Requirements

- Implement a generic tree that supports multiple types of nodes.
- Provide various traversal methods: pre-order, post-order, in-order, DFS, and BFS.
- Ensure that pre-order, post-order, and in-order traversals are only applied to binary trees. For non-binary trees, switch to DFS traversal.
- Implement test functions to validate the functionality of the tree and its iterators.

## Generating Tree Images

The `to_dot` function in the `Tree` class allows you to generate a DOT file representing the tree. This DOT file can then be converted to an image using the `dot` command from the Graphviz toolset.

### Steps to Generate Images

1. After running the main program, DOT files for each tree will be generated (e.g., `tree_int.dot`, `tree_double.dot`, etc.).
2. The `dot` command is used to convert these DOT files to PNG images. This is done automatically in the code using system calls:
   ```cpp
   system("dot -Tpng tree_int.dot -o tree_int.png");
   system("dot -Tpng tree_double.dot -o tree_double.png");
   system("dot -Tpng tree_string.dot -o tree_string.png");
   system("dot -Tpng tree_complex.dot -o tree_complex.png");

## Running the Project

1. Compile the project using the makefile:
- write
   ```
   make
- than
  ```  
  ./tree
2. Compile the project using the makefile:
- write
   ```
   make test

