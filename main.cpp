// ooriamelaku@gmail.com
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "complex.hpp"

using namespace std;

// this function is used to generate and open png files
// the function gets the dot file name and the png file name that will be generated
void generate_and_open_png(const std::string& dot_filename, const std::string& png_filename) {
    // a command to generate the png file from the dot file
    std::string command = "dot -Tpng " + dot_filename + " -o " + png_filename;
    // run the command
    std::cout << "Running command: " << command << std::endl;
    // run the command
    int result = system(command.c_str());
    // check if the command was successful
    if (result != 0) {
        std::cerr << "Failed to generate PNG. Command returned: " << result << std::endl;
        return;
    }
}


int main() {

    // Tree with integer values
    Node<int> root_node_int(1);
    Tree<int> tree_int; // Binary tree that contains integers.
    tree_int.add_root(root_node_int);

    Node<int> n1_int(2);
    Node<int> n2_int(3);
    Node<int> n3_int(4);
    Node<int> n4_int(5);
    Node<int> n5_int(6);

    tree_int.add_sub_node(root_node_int, n1_int);
    tree_int.add_sub_node(root_node_int, n2_int);
    tree_int.add_sub_node(n1_int, n3_int);
    tree_int.add_sub_node(n1_int, n4_int);
    tree_int.add_sub_node(n2_int, n5_int);

    cout << "***** Binary int Tree *****" << endl;

    // Print Pre-Order Traversal
    cout << "Pre-Order Traversal:" << endl;
    for (auto node = tree_int.begin_pre_order(); node != tree_int.end_pre_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print Post-Order Traversal
    cout << "Post-Order Traversal:" << endl;
    for (auto node = tree_int.begin_post_order(); node != tree_int.end_post_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print In-Order Traversal
    cout << "In-Order Traversal:" << endl;
    for (auto node = tree_int.begin_in_order(); node != tree_int.end_in_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print BFS Traversal
    cout << "BFS Traversal:" << endl;
    for (auto node = tree_int.begin_bfs_scan(); node != tree_int.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print DFS Traversal
    cout << "DFS Traversal:" << endl;
    for (auto node = tree_int.begin_dfs_scan(); node != tree_int.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print Heap Traversal
    cout << "Heap Traversal:" << endl;
    for (auto node = tree_int.begin_heap_scan(); node != tree_int.end_heap_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    cout << "***** End of Binary int Tree *****" << endl << endl;


    // Tree with double values
    Node<double> root_node_double(1.1);
    Tree<double> tree_double; // Binary tree that contains doubles.
    tree_double.add_root(root_node_double);

    Node<double> n1_double(1.2);
    Node<double> n2_double(1.3);
    Node<double> n3_double(1.4);
    Node<double> n4_double(1.5);
    Node<double> n5_double(1.6);

    tree_double.add_sub_node(root_node_double, n1_double);
    tree_double.add_sub_node(root_node_double, n2_double);
    tree_double.add_sub_node(n1_double, n3_double);
    tree_double.add_sub_node(n1_double, n4_double);
    tree_double.add_sub_node(n2_double, n5_double);

    cout << "***** Binary double Tree *****" << endl;

    // Print Pre-Order Traversal
    cout << "Pre-Order Traversal:" << endl;
    for (auto node = tree_double.begin_pre_order(); node != tree_double.end_pre_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print Post-Order Traversal
    cout << "Post-Order Traversal:" << endl;
    for (auto node = tree_double.begin_post_order(); node != tree_double.end_post_order(); ++node) {
        //cout << "node value:" << endl;
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print In-Order Traversal
    cout << "In-Order Traversal:" << endl;
    for (auto node = tree_double.begin_in_order(); node != tree_double.end_in_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print BFS Traversal
    cout << "BFS Traversal:" << endl;
    for (auto node = tree_double.begin_bfs_scan(); node != tree_double.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print DFS Traversal
    cout << "DFS Traversal:" << endl;
    for (auto node = tree_double.begin_dfs_scan(); node != tree_double.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print Heap Traversal
    cout << "Heap Traversal:" << endl;
    for (auto node = tree_double.begin_heap_scan(); node != tree_double.end_heap_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    cout << "***** End of Binary double Tree *****" << endl << endl;


    // Tree with string values
    Node<string> root_node_string("root");
    Tree<string> tree_string; // Binary tree that contains strings.
    tree_string.add_root(root_node_string);

    Node<string> n1_string("n1");
    Node<string> n2_string("n2");
    Node<string> n3_string("n3");
    Node<string> n4_string("n4");
    Node<string> n5_string("n5");

    tree_string.add_sub_node(root_node_string, n1_string);
    tree_string.add_sub_node(root_node_string, n2_string);
    tree_string.add_sub_node(n1_string, n3_string);
    tree_string.add_sub_node(n1_string, n4_string);
    tree_string.add_sub_node(n2_string, n5_string);

    cout << "***** Binary string Tree *****" << endl;

    // Print Pre-Order Traversal
    cout << "Pre-Order Traversal:" << endl;
    for (auto node = tree_string.begin_pre_order(); node != tree_string.end_pre_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print Post-Order Traversal
    cout << "Post-Order Traversal:" << endl;
    for (auto node = tree_string.begin_post_order(); node != tree_string.end_post_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print In-Order Traversal
    cout << "In-Order Traversal:" << endl;
    for (auto node = tree_string.begin_in_order(); node != tree_string.end_in_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print BFS Traversal
    cout << "BFS Traversal:" << endl;
    for (auto node = tree_string.begin_bfs_scan(); node != tree_string.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print DFS Traversal
    cout << "DFS Traversal:" << endl;
    for (auto node = tree_string.begin_dfs_scan(); node != tree_string.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print Heap Traversal
    cout << "Heap Traversal:" << endl;
    for (auto node = tree_string.begin_heap_scan(); node != tree_string.end_heap_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;
    cout << "***** End of Binary string Tree *****" << endl << endl;


    // Tree with Complex values
    Node<Complex> root_node_complex(Complex(1.1, 2.2));
    Tree<Complex> tree_complex; // Binary tree that contains Complex numbers.
    tree_complex.add_root(root_node_complex);

    Node<Complex> n1_complex(Complex(1.2, 2.3));
    Node<Complex> n2_complex(Complex(1.3, 2.4));
    Node<Complex> n3_complex(Complex(1.4, 2.5));
    Node<Complex> n4_complex(Complex(1.5, 2.6));
    Node<Complex> n5_complex(Complex(1.6, 2.7));

    tree_complex.add_sub_node(root_node_complex, n1_complex);
    tree_complex.add_sub_node(root_node_complex, n2_complex);
    tree_complex.add_sub_node(n1_complex, n3_complex);
    tree_complex.add_sub_node(n1_complex, n4_complex);
    tree_complex.add_sub_node(n2_complex, n5_complex);

    cout << "***** Binary Complex Tree *****" << endl;

    // Print Pre-Order Traversal
    cout << "Pre-Order Traversal:" << endl;
    for (auto node = tree_complex.begin_pre_order(); node != tree_complex.end_pre_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print Post-Order Traversal
    cout << "Post-Order Traversal:" << endl;
    for (auto node = tree_complex.begin_post_order(); node != tree_complex.end_post_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print In-Order Traversal
    cout << "In-Order Traversal:" << endl;
    for (auto node = tree_complex.begin_in_order(); node != tree_complex.end_in_order(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print BFS Traversal
    cout << "BFS Traversal:" << endl;
    for (auto node = tree_complex.begin_bfs_scan(); node != tree_complex.end_bfs_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print DFS Traversal
    cout << "DFS Traversal:" << endl;
    for (auto node = tree_complex.begin_dfs_scan(); node != tree_complex.end_dfs_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl;

    // Print Heap Traversal
    cout << "Heap Traversal:" << endl;
    for (auto node = tree_complex.begin_heap_scan(); node != tree_complex.end_heap_scan(); ++node) {
        cout << (*node)->get_value() << " ";
    }
    cout << endl << endl;

    // create dot files
    tree_double.to_dot("tree_double.dot");
    tree_complex.to_dot("tree_complex.dot");
    tree_int.to_dot("tree_int.dot");
    tree_string.to_dot("tree_string.dot");
    


    std::cout << "Generating PNG images: " << std::endl;
    generate_and_open_png("tree_double.dot", "tree_double.png");
    generate_and_open_png("tree_complex.dot", "tree_complex.png");
    generate_and_open_png("tree_int.dot", "tree_int.png");
    generate_and_open_png("tree_string.dot", "tree_string.png");




    return 0;
}
