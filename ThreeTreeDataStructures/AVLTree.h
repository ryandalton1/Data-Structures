//
// Created by ryand on 12/1/2018.
//

#ifndef FINALPROJECT_AVLTREE_H
#define FINALPROJECT_AVLTREE_H

struct AVLnode{
    int key;
    int height;
    AVLnode* left;
    AVLnode* right;

    explicit AVLnode(int);
};

class AVLTree {
public:
    void insert(int key);
    void deleteNode(int key);
    void findNode(int key);
    void preOrder();
private:
    AVLnode *root = nullptr;

    AVLnode* insert(AVLnode*,int);
    int max(int,int);
    int height(AVLnode*);
    int getBalance(AVLnode*);
    AVLnode* rightRotate(AVLnode* node);
    AVLnode* leftRotate(AVLnode* node);
    AVLnode* minValueNode(AVLnode*); //function used in delete function
    AVLnode* deleteNode(AVLnode*,int);
    AVLnode* searchTree(AVLnode *node, int key);
    void preOrder(AVLnode*);
};


#endif //FINALPROJECT_AVLTREE_H
