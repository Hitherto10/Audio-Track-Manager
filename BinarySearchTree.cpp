/*
    BinarySearchTree.cpp
    Author: M00804152
*/

#include "BinarySearchTree.h"


/* Call node constructor to initialize a BST node with a given track and
   sets left and right children to a null pointer */
BinarySearchTree::Node::Node(const Track &track) : track(track), left(nullptr), right(nullptr) {}


// BinarySearchTree constructor initializes an empty tree with root set to a null pointer
BinarySearchTree::BinarySearchTree() : root(nullptr) {}


// BinarySearchTree destructor deallocates memory used by the tree by calling the clear function
BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

/* definition of the public Insert function to insert a track into the BST
 by calling the private insert function */
void BinarySearchTree::insert(const Track &track) {
    insertHelper(root, track);
}

/* definition of the public remove function, removes a track from the BST
 by calling the private remove function */
void BinarySearchTree::remove(const Track &track) {
    removeHelper(root, track);
}

// Checks if the binary search tree is empty by comparing the root to nullptr
bool BinarySearchTree::empty() const {
    return root == nullptr;
}

// Call the private insert function to recursively insert a track into the BST
void BinarySearchTree::insertHelper(Node *&node, const Track &track) {
    if (node == nullptr) {
        // Create a new node with the given track if the current node is a null pointer
        node = new Node(track);
    }
    else if (track < node->track) {
        // Insert a track into the left subtree if it's less than the current node's track
        insertHelper(node->left, track);
    }
    else {
        // Insert a track into the right subtree if it's greater than the current node's track
        insertHelper(node->right, track);
    }
}

// Searches for a track in the binary search tree.
Track *BinarySearchTree::search(const Track &track) {
    // Call searchHelper to find the node containing the target track
    Node *result = searchHelper(root, track);

    // If the node is found, return the address of the track, otherwise return nullptr
    return (result != nullptr) ? &result->track : nullptr;
}

// Recursively searches for a node containing the target track in the binary search tree.
BinarySearchTree::Node *BinarySearchTree::searchHelper(Node *node, const Track &track) {
    // if the node is nullptr or the node's track is equal to the target track, return the node
    if (node == nullptr || node->track == track) {
        return node;
    }

    // If the target track is smaller than the current node's track, search in the left subtree
    if (track < node->track) {
        return searchHelper(node->left, track);
    }

    // Otherwise, search in the right subtree
    return searchHelper(node->right, track);
}


// Private remove function that recursively removes a track from the tree
void BinarySearchTree::removeHelper(Node *&node, const Track &track) {
    // If the current node is a null pointer, the track is not in the tree, so return
    if (node == nullptr) {
        return;
    }

    // Removes the track from the left subtree if it's smaller than the current node's track
    if (track < node->track) {
        removeHelper(node->left, track);
    }
    else if (track > node->track) {
        // Removes the track from the right subtree if it's greater than the current node's track
        removeHelper(node->right, track);
    }

    // If the track is equal to the current node's track, remove the current node
    else {
        // If there's no left child, replace the current node with its right child
        if (node->left == nullptr) {
            Node *temp = node->right;
            delete node;
            node = temp;
        }
        // If there's no right child, replace the current node with its left child
        else if (node->right == nullptr) {
            Node *temp = node->left;
            delete node;
            node = temp;
        }

        // If there are both left and right children, replace the current node's track
        // with the leftmost node's track in the right subtree, and remove that node
        else {
            Node *minNode = findLeftmostNode(node->right);
            node->track = minNode->track;
            removeHelper(node->right, minNode->track);
        }
    }
}


// Function to find the leftmost node (the smallest value) in a subtree
BinarySearchTree::Node *BinarySearchTree::findLeftmostNode(Node *node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}


// Recursive function to deallocate memory used by the tree nodes
void BinarySearchTree::clear(Node *node) {
    if (node != nullptr) {
        // Traverse left and right subtrees deallocating nodes
        clear(node->left);
        clear(node->right);
        delete node;
    }
}







