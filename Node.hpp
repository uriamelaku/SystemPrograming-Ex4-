// ooriamelaku@gmail.com
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template<typename T>
class Node {
public:
    T value; // Value of the node
    std::vector<Node<T>*> children; // Vector to store pointers to the children of the node

    // Constructor to initialize a node with a given value
    Node(T val);

    // Destructor to delete children
    ~Node();

    // Function to add a child to the node
    void add_child(Node<T>* child);

    // Function to get the value of the node
    T get_value() const;
};


//this template class is used to create a node with a given value
template<typename T>
Node<T>::Node(T val) : value(val) {}

//this template class is used to delete the children of the node
template<typename T>
Node<T>::~Node() {
    // Delete all the children of the node
    for (auto& child : children) {
        delete child;
        //set the pointer to null
        child = nullptr;
    }
    //clear the children vector
    children.clear();

    //print the value of the deleted node
    //std::cout << "Deleted node with value: " << value << std::endl;

}


template<typename T>
void Node<T>::add_child(Node<T>* child) {
    // Add the child to the children vector
    children.push_back(child);
}

template<typename T>
T Node<T>::get_value() const {
    return value;
}

#endif
