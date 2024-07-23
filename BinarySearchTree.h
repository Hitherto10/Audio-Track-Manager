/*
    BinarySearchTree.h
    Author: M00804152
*/

#ifndef COURSEWORK2_BINARYSEARCHTREE_H
#define COURSEWORK2_BINARYSEARCHTREE_H

#include "Track.h"

class BinarySearchTree {
private:
    // Node struct representing a node in the binary search tree
    struct Node {
        // The track data stored in the node
        Track track;

        // Pointer to the left and right child node
        Node *left;
        Node *right;

        // declaration of the Node constructor
        Node(const Track &track);
    };

    // Pointer to the root node of the binary search tree
    Node *root;

    /*
        Private helper function to insert a track into the binary search tree.
        This private function is necessary for encapsulation and to support recursion
        in the tree traversal and insertion process.
        @param - node  this references a pointer to a Node for traversing and modifying the BST
        @param - track (the track to be inserted into the BST)
    */
    void insertHelper(Node *&node, const Track &track);

    /*
        Private helper function to remove a track from the binary search tree.
        This private function is necessary for encapsulation and to support recursion
        in the tree traversal and removal process.
        @param - node  this references a pointer to a Node for traversing and modifying the BST
        @param - track (the track to be removed from the BST)
    */
    void removeHelper(Node *&node, const Track &track);


    /*
        Recursively searches for a node containing the target track in the binary search tree.
        @param - node (pointer to a Node, used for traversing the BST)
        @param - track (the track to be searched for in the BST)
        @return - pointer to the node containing the track if found, nullptr otherwise
    */
    Node *searchHelper(Node *node, const Track &track);

    /*
        Finds the leftmost node in a subtree, which represents the minimum value in that subtree
        @param - node (pointer to a Node, used as the root of the subtree to be searched)
        @return - a pointer to the leftmost node (minimum value node) in the subtree
    */
    Node *findLeftmostNode(Node *node) const;

    // Templated forEach function to perform a given action on each node in the tree
    // in an in-order traversal manner (left subtree, current node, right subtree)
    template <typename Func>
    void forEach(Node *node, Func func) const {
        if (node != nullptr) {
            // Process the left subtree
            forEach(node->left, func);

            // Apply the given templated function on the current node's track
            func(node->track);

            // Process the right subtree
            forEach(node->right, func);
        }
    }

    // function to clear the binary search tree by deleting all its nodes
    void clear(Node *node);


public:

    // Default constructor and Destructor for the BinarySearchTree class
    BinarySearchTree();
    ~BinarySearchTree();

    /*
       Public function to insert a track into the binary search tree.
       This function provides functionality for inserting a track
       into the BST, calling the private insertHelper function to handle
       the actual insertion process.
       @param - track (the track to be inserted into the BST)
   */
    void insert(const Track &track);

    /*
        Public function to remove a track from the binary search tree.
        This function provides functionality for removing a track
        from the BST, calling the private removeHelper function to handle
        the actual removal process.
        @param - track (the track to be removed from the BST)
    */
    void remove(const Track &track);

    /*
        Searches for a track in the binary search tree.
        @param - track (the track to be searched for in the BST)
        @return - pointer to the track if found, nullptr otherwise
     */
    Track *search(const Track &track);

    /*
        Executes a provided function on each track in the tree, in ascending order
        @param - func (an object, such as a function that accepts a single Track as a parameter)
    */
    template <typename Func>
    void forEach(Func func) const {
        forEach(root, func);
    }

    /*
        Checks if the binary search tree is empty
        @return - true if the tree is empty, false otherwise
    */
    bool empty() const;
};

#endif //COURSEWORK2_BINARYSEARCHTREE_H

