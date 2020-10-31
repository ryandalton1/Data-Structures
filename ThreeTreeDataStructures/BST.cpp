//
// Created by ryand on 12/1/2018.
//

#include "BST.h"
using namespace std;

node::node(int data) {
    key = data;
    leftChild = rightChild = nullptr;
}




//These methods are private, meaning they can only be called from within this .cpp

node* BST::searchBST(node *node, int key){
    //use this recursive function to find a pointer to a node in the BST, given a key and the root
    //if there is no BST or if root is the one, return it
    if(node == nullptr){
        return nullptr;
    }
    if(node->key == key){
        return node;
    }
        //if the letter we're looking for is greater than the current node move to the right
    else if(node->key < key){
        return searchBST(node->rightChild, key);
    }
        //else move the node to the left
    else{
        return searchBST(node->leftChild, key);
    }
};
node* BST::treeMinimum(node *nodeIn){
    if(nodeIn->leftChild == nullptr){
        return nodeIn;
    }

    treeMinimum(nodeIn->leftChild);
}; //use this to find the left most leaf node of the BST, you'll need this in the delete function
node* BST::insert(node* n, int key) {
    if (n == nullptr){
        node *newNode = new node(key);
        return newNode;
    }

    if (key < n->key)
        n->leftChild  = insert(n->leftChild, key);
    else if (key > n->key)
        n->rightChild = insert(n->rightChild, key);
    else // Equal keys are not allowed in BST
        return n;
}
//this function needs to be given a letter node BST, and a letter of the node to delete. It will then use a
//recursive function to look through the tree and return the inital root
node* BST::deleteBSTNode(node *tmpRoot, int key){
    if (tmpRoot == nullptr)
        return tmpRoot;

    if (key < tmpRoot->key)
        return deleteBSTNode(tmpRoot->leftChild, key);

    if (key > tmpRoot->key)
        return deleteBSTNode(tmpRoot->rightChild, key);

    if (tmpRoot->leftChild == nullptr || tmpRoot->rightChild == nullptr)
        return tmpRoot;

    node *temp = treeMinimum(tmpRoot->rightChild);
    tmpRoot->key = temp->key;
    return deleteBSTNode(tmpRoot->rightChild, temp->key);
};
//=======================================================================================================
//These methods are public, meaning they can be called from main.cpp
void BST::deleteNode(int key)
{
    node *tmp = deleteBSTNode(root, key);
}
void BST::addNode(int key){
    root = insert(root, key);
};
void BST::findMovie(int key){
    node *tmp = searchBST(root, key);
};