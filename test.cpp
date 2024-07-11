// ooriamelaku@gmail.com
#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "complex.hpp"
#include <cassert>

using namespace std;

// 1. Test add_root() method
void test_add_root() {
    cout << "Test add_root.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    if (tree.get_root()->get_value() == 1) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl;
}

// 2. Test add_sub_node() method
void test_add_sub_node() {
    cout << "Test add_sub_node.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    if (tree.get_root()->children[0]->get_value() == 2) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl;
}

// 3. Test pre_order_traversal() method
void test_pre_order_traversal() {
    cout << "Test pre_order_traversal.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6);
    tree.add_sub_node(n2, n5);
    string expected = "1 2 4 5 3 6 ";
    string result = "";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        result += to_string((*node)->get_value()) + " ";
    }
    if (result == expected) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl; 
}

// 4. Test post_order_traversal() method
void test_post_order_traversal() {
    cout << "Test post_order_traversal.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6);
    tree.add_sub_node(n2, n5);
    string expected = "4 5 2 6 3 1 ";
    string result = "";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        result += to_string((*node)->get_value()) + " ";
    }
    if (result == expected) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl; 
}

// 5. Test in_order_traversal() method
void test_in_order_traversal() {
    cout << "Test in_order_traversal.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6);
    tree.add_sub_node(n2, n5);
    string expected = "4 2 5 1 6 3 ";
    string result = "";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        result += to_string((*node)->get_value()) + " ";
    }
    if (result == expected) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl; 
}

// 6. Test BFS traversal
void test_bfs_traversal() {
    cout << "Test BFS traversal.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6);
    tree.add_sub_node(n2, n5);

    string expected = "1 2 3 4 5 6 ";
    string result = "";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        result += to_string((*node)->get_value()) + " ";
    }
    if (result == expected) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed! Expected: " << expected << " but got: " << result << endl;
    }
    cout << "******" << endl;
}


// 7. Test DFS traversal
void test_dfs_traversal() {
    cout << "Test DFS traversal.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6);
    tree.add_sub_node(n2, n5);

    string expected = "1 2 4 5 3 6 ";
    string result = "";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        result += to_string((*node)->get_value()) + " ";
    }
    if (result == expected) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed! Expected: " << expected << " but got: " << result << endl;
    }
    cout << "******" << endl;
}


// 8. Test Heap traversal
void test_heap_traversal() {
    cout << "Test Heap traversal.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6);
    tree.add_sub_node(n2, n5);

    vector<int> expected = {1, 2, 3, 4, 5, 6};
    vector<int> result;

    for (auto node = tree.begin_heap_scan(); node != tree.end_heap_scan(); ++node) {
        result.push_back((*node)->get_value());
    }

    if (result == expected) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed! Expected: ";
        for (const auto& val : expected) {
            cout << val << " ";
        }
        cout << "but got: ";
        for (const auto& val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "******" << endl;
}


// 9. Test find_node() method
void test_find_node() {
    cout << "Test find_node.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6);
    tree.add_sub_node(n2, n5);
    
    Node<int> target_node(4); // create a target node with value 4
    Node<int>* result = tree.find_node(tree.get_root(), target_node); 
    
    if (result != nullptr && result->get_value() == 4) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl; 
}

// 10. Test clear_tree() method
void test_clear_tree() {
    cout << "Test clear_tree.." << endl;
    Tree<int> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6);
    tree.add_sub_node(n2, n5);
    tree.clear();
    if (tree.get_root() == nullptr) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl; 
}


// 11. Test add_multiple_children() method
void test_add_multiple_children() {
    cout << "Test add_multiple_children.." << endl;
    Tree<int, 3> tree; // יש להגדיר את העץ עם ערך K המתאים (למשל, עץ טרינרי - 3 ילדים מקסימום)
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    tree.add_sub_node(root, n1);
    tree.add_sub_node(root, n2);
    tree.add_sub_node(root, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n1, n5);

    string expected = "1 2 3 4 5 6 ";
    string result = "";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        result += to_string((*node)->get_value()) + " ";
    }

    if (result == expected) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed! Expected: " << expected << " but got: " << result << endl;
    }
    cout << "******" << endl;
}


// 12. Test small tree with one child
void test_tree_with_custom_values() {
    cout << "Test tree_with_custom_values.." << endl;
    Tree<int> tree;
    Node<int> root(1.0);
    tree.add_root(root);
    Node<int> n1(2.0);
    tree.add_sub_node(root, n1);
    Node<int> n2(3.0);
    tree.add_sub_node(root, n2);
    Node<int> n3(4.0);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5.0);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6.0);
    tree.add_sub_node(n2, n5);
    string expected = "1 2 3 4 5 6 ";
    string result = "";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        result += to_string((*node)->get_value()) + " ";
    }
    if (result == expected) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed! Expected: " << expected << " but got: " << result << endl;
    }
    cout << "******" << endl;
};


// 13. Test complex equality
void test_complex_equality() {
    cout << "Test complex_equality.." << endl;
    Complex c1(1.0, 2.0);
    Complex c2(1.0, 2.0);
    if (c1 == c2) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl;

};

// 14. Test complex to string
void test_complex_to_string() {
    cout << "Test complex_to_string.." << endl;
    Complex c1(1.0, 2.0);
    string expected = "1+2i";
    string result = c1.toString();
    if (result == expected) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl;

    
};

// 15. edge case: Check if Pre-order traversal is only supported for binary trees
void test_pre_order_only_binary() {
    cout << "Test pre_order_only_binary.." << endl;
    Tree<int, 3> tree;  // Create a 3-ary tree (not binary)
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(root, n3);

    try {
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
            // This should throw an error
        }
        cout << "Test failed! No exception thrown." << endl;
    } 
    catch (const std::runtime_error& e) {
        if (string(e.what()) == "Pre-order traversal is only supported for binary trees.") {
            cout << "Test passed!" << endl;
        } 
        else 
        {
            cout << "Test failed! Wrong exception message: " << e.what() << endl;
        }
    }
    catch (...) {
        cout << "Test failed! Wrong exception type." << endl;
    }
    cout << "******" << endl;

    // Clear the tree
    tree.clear();
}

// 16. edge case: Check if In-order traversal is only supported for binary trees
void test_in_order_only_binary() {
    cout << "Test in_order_only_binary.." << endl;
    Tree<int, 3> tree;  // Create a 3-ary tree (not binary)
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(root, n3);

    try {
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
            // This should throw an error
        }
        cout << "Test failed! No exception thrown." << endl;
    } 
    catch (const std::runtime_error& e) {
        if (string(e.what()) == "In-order traversal is only supported for binary trees.") {
            cout << "Test passed!" << endl;
        } 
        else 
        {
            cout << "Test failed! Wrong exception message: " << e.what() << endl;
        }
    }
    catch (...) {
        cout << "Test failed! Wrong exception type." << endl;
    }
    cout << "******" << endl;

    // Clear the tree
    tree.clear();
}

// 17. edge case: Check if Post-order traversal is only supported for binary trees
void test_post_order_only_binary() {
    cout << "Test post_order_only_binary.." << endl;
    Tree<int, 3> tree;  // Create a 3-ary tree (not binary)
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(root, n3);

    try {
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
            // This should throw an error
        }
        cout << "Test failed! No exception thrown." << endl;
    } 
    catch (const std::runtime_error& e) {
        if (string(e.what()) == "Post-order traversal is only supported for binary trees.") {
            cout << "Test passed!" << endl;
        } 
        else 
        {
            cout << "Test failed! Wrong exception message: " << e.what() << endl;
        }
    }
    catch (...) {
        cout << "Test failed! Wrong exception type." << endl;
    }
    cout << "******" << endl;

    // Clear the tree
    tree.clear();
}


// 18. Check if the constructor of the Node class is working properly
void test_node_constructor() {
    cout << "Test node_constructor.." << endl;
    Node<int> node(1);
    if (node.get_value() == 1) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl;

    // Clear the children
    node.children.clear();
}

// 19. Check if the add_child() method of the Node class is working properly
void test_node_add_child() {
    cout << "Test node_add_child.." << endl;
    Node<int> node(1);
    Node<int> child(2);
    node.add_child(&child);
    if (node.children[0]->get_value() == 2) {
        cout << "Test passed!" << endl;
    } 
    else 
    {
        cout << "Test failed!" << endl;
    }
    cout << "******" << endl;

    // Clear the children
    node.children.clear();

}

// 20. Test a giant tree with 29 nodes
void test_giant_tree() {
    cout << "Test giant_tree.." << endl;
    const int MAX_CHILDREN = 5; 
    Tree<int, MAX_CHILDREN> tree;
    Node<int> root(1);
    tree.add_root(root);
    Node<int> n1(2);
    tree.add_sub_node(root, n1);
    Node<int> n2(3);
    tree.add_sub_node(root, n2);
    Node<int> n3(4);
    tree.add_sub_node(n1, n3);
    Node<int> n4(5);
    tree.add_sub_node(n1, n4);
    Node<int> n5(6);
    tree.add_sub_node(n2, n5);
    Node<int> n6(7);
    tree.add_sub_node(n2, n6);
    Node<int> n7(8);
    tree.add_sub_node(n2, n7);
    Node<int> n8(9);
    tree.add_sub_node(n2, n8);
    Node<int> n9(10);
    tree.add_sub_node(n2, n9);

    // Adding remaining nodes as children of n3 to keep the number of children <= MAX_CHILDREN
    Node<int> n10(11);
    tree.add_sub_node(n3, n10);
    Node<int> n11(12);
    tree.add_sub_node(n3, n11);
    Node<int> n12(13);
    tree.add_sub_node(n3, n12);
    Node<int> n13(14);
    tree.add_sub_node(n3, n13);
    Node<int> n14(15);
    tree.add_sub_node(n3, n14);

    Node<int> n15(16);
    tree.add_sub_node(n4, n15);
    Node<int> n16(17);
    tree.add_sub_node(n4, n16);
    Node<int> n17(18);
    tree.add_sub_node(n4, n17);
    Node<int> n18(19);
    tree.add_sub_node(n4, n18);
    Node<int> n19(20);
    tree.add_sub_node(n4, n19);

    Node<int> n20(21);
    tree.add_sub_node(n5, n20);
    Node<int> n21(22);
    tree.add_sub_node(n5, n21);
    Node<int> n22(23);
    tree.add_sub_node(n5, n22);
    Node<int> n23(24);
    tree.add_sub_node(n5, n23);
    Node<int> n24(25);
    tree.add_sub_node(n5, n24);

    Node<int> n25(26);
    tree.add_sub_node(n6, n25);
    Node<int> n26(27);
    tree.add_sub_node(n6, n26);
    Node<int> n27(28);
    tree.add_sub_node(n6, n27);
    Node<int> n28(29);
    tree.add_sub_node(n6, n28);

    // Verify the structure by checking the size and some values
    vector<int> result;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        result.push_back((*node)->get_value());
    }

    // Check if the size matches the expected number of nodes (28 + 1 root)
    if (result.size() == 29) {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }

    cout << "******" << endl;
}

// 21. edge case. Test adding more than 3 children to a 3-ary tree
void test_add_more_than_max_children() {
    cout << "Test add_more_than_max_children.." << endl;
    Tree<int, 3> tree; // עץ 3-ערכי
    Node<int> root(1);
    tree.add_root(root);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);

    try {
        tree.add_sub_node(root, n1);
        tree.add_sub_node(root, n2);
        tree.add_sub_node(root, n3);
    } 
    catch (const std::exception& e) {
        cout << "Test failed when adding first three children: " << e.what() << endl;
        assert(false);
    }

    // the fourth child should fail
    try {
        tree.add_sub_node(root, n4);
        cout << "Test failed!" << endl;
        assert(false); // This should not be reached
    } catch (const std::exception& e) {
        cout << "Test passed! " << endl;
    }

    cout << "******" << endl;
}



int main(){
    test_add_root();
    test_add_sub_node();
    test_pre_order_traversal();
    test_post_order_traversal();
    test_in_order_traversal();
    test_bfs_traversal();
    test_dfs_traversal();
    test_heap_traversal();
    test_find_node();
    test_clear_tree();
    test_add_multiple_children();
    test_tree_with_custom_values();
    test_complex_equality();
    test_complex_to_string();
    test_pre_order_only_binary();
    test_in_order_only_binary();
    test_post_order_only_binary();
    test_node_constructor();
    test_node_add_child();
    test_giant_tree();
    test_add_more_than_max_children();
    cout << "********************* All 21 tests passed! *********************" << endl;

    return 0;

}