//
// Created by ryand on 12/1/2018.
//

#ifndef FINALPROJECT_BST_H
#define FINALPROJECT_BST_H
#include <iostream>
using namespace std;

struct node
{
    int key;
    node *leftChild, *rightChild;

    explicit node(int);
};

class BST {
public:
    void deleteNode(int key);
    void addNode(int);
    void findMovie(int key);
private:
    node* searchBST(node *node, int); //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE
    node* treeMinimum(node *node); //use this to find the left most leaf node of the BST, you'll need this in the delete function
    node* insert(node*, int );
    node *deleteBSTNode(node*, int);

    node* root = nullptr;
};

#endif //FINALPROJECT_BST_H
