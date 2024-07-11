#ifndef TREE_HPP
#define TREE_HPP

#include <queue>
#include <stack>
#include <stdexcept>
#include <iostream>
#include <set>
#include <fstream>
#include "Node.hpp"
#include <algorithm>

template<typename T, int K = 2>
class Tree {
private:
    Node<T>* root;

public:
    // in the beginning the root is nullptr
    Tree() : root(nullptr) {}

    // Destructor to delete the tree
    ~Tree() {
        clear();
    }

    // Clear the tree
    void clear() {
        clear(root);
        root = nullptr;
    }

    // Clear a node and its children
    void clear(Node<T>* node) {
        // if the node is nullptr return
        if (!node) return;
        for (Node<T>* child : node->children) {
            clear(child);
        }
        node->children.clear();
        delete node;
        node = nullptr;
    }

    void add_root(const Node<T>& node) {
        // if the root is already initialized, delete it
        if (root != nullptr) {
            delete root;
        }
        // create a new node and assign it to the root
        root = new Node<T>(node);
    }

    // get root function returns the root node of the tree
    Node<T>* get_root() const {
        return root;
    }

    // this function adds a child to a parent node
    void add_sub_node(const Node<T>& parent, const Node<T>& child) {
        // parent_ptr is a pointer to the parent node
        Node<T>* parent_ptr = find_node(root, parent);
        // if the parent node is found and the number of children is less than K
        if (parent_ptr && parent_ptr->children.size() < K) {
            parent_ptr->add_child(new Node<T>(child));
        } 
        else {
            throw std::runtime_error("Parent not found or maximum number of children reached.");
        }
    }

    // this function finds a node in the tree using DFS
    Node<T>* find_node(Node<T>* current, const Node<T>& target) {
        // if we reach to the end of the tree and the target node is not found return nullptr
        if (!current) return nullptr;
        // if the current node is the target node return the current node
        if (current->value == target.value) return current;
        // iterate over the children of the current node
        for (auto& child : current->children) {
            // recursively call the function to find the target node
            Node<T>* result = find_node(child, target);
            // if the target node is found return the result
            if (result) return result;
        }
        // if the target node is not found return nullptr
        return nullptr;
    }

    // to dot function is used to create a dot file that represents the tree
    void to_dot(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file");
        }
        file << "digraph G {\n";
        to_dot_helper(file, root);
        file << "}\n";
        file.close();
    }

    // to dot helper function is used to create the edges between the nodes
    void to_dot_helper(std::ofstream& file, Node<T>* node) const {
        if (!node) return;
        for (auto child : node->children) {
            file << "\"" << node->get_value() << "\" -> \"" << child->get_value() << "\";\n";
            to_dot_helper(file, child);
        }
    }

    // only for statment
    class DFSIterator;

    // Pre-order iterator
    class PreOrderIterator {
    private:
        std::stack<Node<T>*> stack;
        bool use_dfs;
        DFSIterator dfs_iterator;

    public:
        PreOrderIterator(Node<T>* root) : use_dfs(K != 2), dfs_iterator(root) {
            // If use_dfs is false and root is not nullptr, push the root onto the stack
            if (!use_dfs && root) {
                stack.push(root);
            }
        }

        // This function checks if the iterator has not finished traversing the tree.
        // It returns true if the stack is not empty, meaning there are still nodes to visit.
        // Otherwise, it returns false.
        bool operator!=(const PreOrderIterator& /*other*/) const {
            if (use_dfs) {
                return dfs_iterator != DFSIterator(nullptr);
            } 
            else {
                return !stack.empty();
            }
        }

        // This function returns the current node that the iterator is pointing to.
        Node<T>* operator*() const {
            // if use_dfs is true return the current node of the DFS iterator
            if (use_dfs) 
            {
                return *dfs_iterator;
            } 
            // else return the top node of the stack
            else 
            {
                return stack.top();
            }
        }

        // This function moves the iterator to the next node in the Pre-order traversal.
        PreOrderIterator& operator++() {
            if (use_dfs) 
            {
                ++dfs_iterator;
            } 
            else 
            {
                Node<T>* node = stack.top();
                stack.pop();
                // Iterate over the children of the current node and push them to the stack
                for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                    stack.push(*it);
                }
            }
            return *this;
        }
    };

    // This function returns the begin iterator of the Pre-order traversal
    PreOrderIterator begin_pre_order() const {
        return PreOrderIterator(root);
    }

    // This function returns the end iterator of the Pre-order traversal
    PreOrderIterator end_pre_order() const {
        return PreOrderIterator(nullptr);
    }




    // Post-order iterator
    class PostOrderIterator {
    private:
        // this stack is used to store the nodes that are not visited yet
        std::stack<Node<T>*> stack;
        // this stack is used to store the visited nodes
        std::stack<Node<T>*> visited;
        bool use_dfs; // Flag to indicate whether to use DFS instead of post-order
        DFSIterator dfs_iterator; // DFS iterator to use if K != 2

        void push_leftmost_children(Node<T>* node) {
            while (node) {
                stack.push(node);
                if (!node->children.empty()) {
                    node = node->children.front();
                } else {
                    node = nullptr;
                }
            }
        }

    public:
        PostOrderIterator(Node<T>* root) : use_dfs(K != 2), dfs_iterator(root) {
            // If K is not 2, use DFS traversal
            if (!use_dfs && root) {
                push_leftmost_children(root);
            }
        }

        // This function checks if the iterator has not finished traversing the tree.
        // It returns true if the stack is not empty, meaning there are still nodes to visit.
        // if the stack is not empty return true
        // otherwise return false        
        bool operator!=(const PostOrderIterator&) const {
            if (use_dfs) {
                return dfs_iterator != DFSIterator(nullptr);
            }
            return !stack.empty();
        }

        // This function returns the current node that the iterator is pointing to.
        Node<T>* operator*() const {
            if (use_dfs) {
                return *dfs_iterator;
            }
            return stack.top();
        }

        PostOrderIterator& operator++() {
            if (use_dfs) {
                ++dfs_iterator;
                return *this;
            }

            if (stack.empty()) {
                return *this;
            }

            Node<T>* node = stack.top();
            stack.pop();
            visited.push(node);

            if (!stack.empty()) {
                Node<T>* parent = stack.top();
                auto it = std::find(parent->children.begin(), parent->children.end(), node);
                if (it != parent->children.end() && ++it != parent->children.end()) {
                    push_leftmost_children(*it);
                }
            }

            return *this;
        }
    };

    PostOrderIterator begin_post_order() const {
        return PostOrderIterator(root);
    }

    PostOrderIterator end_post_order() const {
        return PostOrderIterator(nullptr);
    }

    // In-order iterator
    class InOrderIterator {
    private:
        std::stack<Node<T>*> stack;
        Node<T>* current;
        bool use_dfs; // Flag to indicate whether to use DFS instead of in-order
        DFSIterator dfs_iterator; // DFS iterator to use if K != 2

        void push_left(Node<T>* node) {
            while (node) {
                stack.push(node);
                if (!node->children.empty()) {
                    node = node->children[0];
                } else {
                    node = nullptr;
                }
            }
        }

    public:
        InOrderIterator(Node<T>* root) : current(root), use_dfs(K != 2), dfs_iterator(root) {
            if (!use_dfs) {
                push_left(root);
            }
        }

        bool operator!=(const InOrderIterator& /*other*/) const {
            if (use_dfs) {
                return dfs_iterator != DFSIterator(nullptr);
            }
            return !stack.empty();
        }

        Node<T>* operator*() const {
            if (use_dfs) {
                return *dfs_iterator;
            }
            return stack.top();
        }

        InOrderIterator& operator++() {
            if (use_dfs) {
                ++dfs_iterator;
                return *this;
            }

            Node<T>* node = stack.top();
            stack.pop();
            if (!node->children.empty() && node->children.size() > 1) {
                push_left(node->children[1]);
            }
            return *this;
        }
    };

    InOrderIterator begin_in_order() const {
        return InOrderIterator(root);
    }

    InOrderIterator end_in_order() const {
        return InOrderIterator(nullptr);
    }


    // DFS iterator
    class DFSIterator {
    private:
        std::stack<Node<T>*> stack;
    public:
        DFSIterator(Node<T>* root) {
            if (root) stack.push(root);
        }

        bool operator!=(const DFSIterator& /*other*/) const {
            return !stack.empty();
        }

        Node<T>* operator*() const {
            return stack.top();
        }

        DFSIterator& operator++() {
            Node<T>* node = stack.top();
            stack.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stack.push(*it);
            }
            return *this;
        }
    };

    DFSIterator begin_dfs_scan() const {
        return DFSIterator(root);
    }

    DFSIterator end_dfs_scan() const {
        return DFSIterator(nullptr);
    }

    // BFS iterator
    class BFSIterator {
    private:
        std::queue<Node<T>*> queue;
    public:
        BFSIterator(Node<T>* root) {
            if (root) queue.push(root);
        }

        bool operator!=(const BFSIterator& /*other*/) const {
            return !queue.empty();
        }

        Node<T>* operator*() const {
            return queue.front();
        }

        BFSIterator& operator++() {
            Node<T>* node = queue.front();
            queue.pop();
            for (auto& child : node->children) {
                queue.push(child);
            }
            return *this;
        }
    };

    BFSIterator begin_bfs_scan() const {
        return BFSIterator(root);
    }

    BFSIterator end_bfs_scan() const {
        return BFSIterator(nullptr);
    }

    // Heap iterator
    class HeapIterator {
    private:
        std::vector<Node<T>*> heap;

        void collect_nodes(Node<T>* node, std::vector<Node<T>*>& nodes) {
            if (!node) return;
            nodes.push_back(node);
            for (auto child : node->children) {
                collect_nodes(child, nodes);
            }
        }

    public:
        HeapIterator(Node<T>* root) {
            if (root) {
                collect_nodes(root, heap);
                auto comp = [](Node<T>* lhs, Node<T>* rhs) { return lhs->get_value() > rhs->get_value(); };
                std::make_heap(heap.begin(), heap.end(), comp);
            }
        }

        bool operator!=(const HeapIterator& other) const {
            return !heap.empty() || !other.heap.empty();
        }

        Node<T>* operator*() const {
            return heap.front();
        }

        HeapIterator& operator++() {
            if (!heap.empty()) {
                auto comp = [](Node<T>* lhs, Node<T>* rhs) { return lhs->get_value() > rhs->get_value(); };
                std::pop_heap(heap.begin(), heap.end(), comp);
                heap.pop_back();
            }
            return *this;
        }
    };

    HeapIterator begin_heap_scan() const {
        return HeapIterator(root);
    }

    HeapIterator end_heap_scan() const {
        return HeapIterator(nullptr);
    }
};

#endif
