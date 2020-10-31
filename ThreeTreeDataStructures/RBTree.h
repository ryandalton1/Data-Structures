//
// Red Black Tree Definition
//

#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

enum Color {RED, BLACK, DOUBLE_BLACK};

struct Node
{
    int data;
    int color;
    Node *left, *right, *parent;

    explicit Node(int);
};

class RBTree
{
    private:
        Node *root;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
        void fixInsertRBTree(Node *&);
        void fixDeleteRBTree(Node *&);
        void preorderBST(Node *&);
        void printTree(Node *&);
        void DeleteAll(Node *&);
        int getColor(Node *&);
        void setColor(Node *&, int);
        Node *minValueNode(Node *&);
        Node* insertBST(Node *&, Node *&);
        Node* deleteBST(Node *&, int);
        Node* searchTree(Node*, int);
    public:
        RBTree();
        void DeleteAll();
        void insertValue(int);
        void deleteValue(int);
        void findNode(int);
        void preorder();
        void printTree();
};


#endif //RED_BLACK_TREE_RBTREE_H
