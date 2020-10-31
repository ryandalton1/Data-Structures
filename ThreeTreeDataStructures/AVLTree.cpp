//
// Created by ryand on 12/1/2018.
//

#include "AVLTree.h"
#include <iostream>

AVLnode::AVLnode(int key) {
    this->key = key;
    height = 0;
    left = right = nullptr;
}
void AVLTree::insert(int key){
    root = insert(root, key);
}
void AVLTree::deleteNode(int key){
    root = deleteNode(root, key);
}
void AVLTree::findNode(int key){
    AVLnode *tmp = searchTree(root, key);
}
void AVLTree::preOrder(){
    preOrder(root);
    std::cout<<root->key<<std::endl;
}
void AVLTree::preOrder(AVLnode* node){
    if(node != nullptr){
        std::cout<<" "<<node->key;
        preOrder(node->left);
        preOrder(node->right);
    }
}
AVLnode* AVLTree::insert(AVLnode* node, int key) {
    //insert the node regularly
    if (node == nullptr){
        AVLnode *newNode = new AVLnode(key);
        return newNode;
    }

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;


    //the new value has been inserted into the tree check if the tree is still balanced
    node->height = 1 + max(height(node->left),height(node->right));

    //get the balance factor of node to see if a rotation is necessary
    int balance = getBalance(node);

    //Left Left Case aka a single right rotation
    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }
    //Right Right Case aka a single left rotation
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }
    //Left Right Case aka a left rotate then a right rotate
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //Right Left Case aka a right rotate then a left rotate
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    //there was no balance issue
    return node;
}
int AVLTree::height(AVLnode* node){
    if(node == nullptr)
        return 0;
    return node->height;
}
int AVLTree::max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int AVLTree::getBalance(AVLnode *node){
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}
AVLnode* AVLTree::rightRotate(AVLnode* node){
    AVLnode *leftChild = node->left;
    AVLnode *lowRight = leftChild->right;

    // Perform rotation
    leftChild->right = node;
    node->left = lowRight;

    // Update heights
    node->height = max(height(node->left), height(node->right))+1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right))+1;

    // Return new root
    return leftChild;
}
AVLnode* AVLTree::leftRotate(AVLnode *node){
    AVLnode *rightChild = node->right;
    AVLnode *lowLeft = rightChild->left;

    // Perform rotation
    rightChild->left = node;
    node->right = lowLeft;

    //  Update heights
    node->height = max(height(node->left), height(node->right))+1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right))+1;

    // Return new root
    return rightChild;
}
AVLnode* AVLTree::minValueNode(AVLnode* node){
    AVLnode* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != nullptr)
        current = current->left;

    return current;
}
AVLnode* AVLTree::deleteNode(AVLnode* node, int key){
    //perform regular bst delete
    if (node == nullptr)
        return node;

    if ( key < node->key )
        node->left = deleteNode(node->left, key);
    else if( key > node->key )
        node->right = deleteNode(node->right, key);
    else {
        // node with only one child or no child 
        if( (node->left == nullptr) || (node->right == nullptr) )
        {
            AVLnode* temp;
            if(node->left == nullptr)
                temp = node->right;
            else
                temp = node->left;

            // No child case 
            if (temp == NULL) {
                temp = node;
                node = NULL;
            }
            else // One child case 
                *node = *temp; // Copy the contents of 
            // the non-empty child 
            free(temp);
        }
        else {
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            AVLnode* temp = minValueNode(node->right);

            // Copy the inorder successor's data to this node 
            node->key = temp->key;

            // Delete the inorder successor 
            node->right = deleteNode(node->right, temp->key);
        }
    }
    // If the tree had only one node then return
    if (node == NULL)
        return node;

    //the node has been deleted regularly now check if the tree is unbalanced and fix it
    //first update height of tree
    node->height = 1 + max(height(node->left), height(node->right));

    //now get the balance factor of node and use it to determine which case to apply
    int balance = getBalance(node);

    //Left Left Case aka a single right rotation
    if(balance > 1 && key < node->left->key){
        return rightRotate(node);
    }
    //Right Right Case aka a single left rotation
    if(balance < -1 && key > node->right->key){
        return leftRotate(node);
    }
    //Left Right Case aka a left rotate then a right rotate
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //Right Left Case aka a right rotate then a left rotate
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
AVLnode* AVLTree::searchTree(AVLnode *node, int key){
    //use this recursive function to find a pointer to a node in the BST, given a key and the root
    //if there is no BST or if root is the one, return it
    if(node == NULL){
        return NULL;
    }
    if(node->key == key){
        return node;
    }
        //if the letter we're looking for is greater than the current node move to the right
    else if(node->key < key){
        return searchTree(node->right, key);
    }
        //else move the node to the left
    else{
        return searchTree(node->left, key);
    }
};