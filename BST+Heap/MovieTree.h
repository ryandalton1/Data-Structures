//
// Created by ryand on 10/28/2018.
//

#ifndef ASSIGNMENT_7_MOVIETREE_H
#define ASSIGNMENT_7_MOVIETREE_H
#include <string>

struct MovieNodeHeap{
    int ranking;
    std::string title;
    int year;
    int quantity;
    MovieNodeHeap(){};

    MovieNodeHeap(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
    };
};

struct MovieNodeBST{
    char letter;
    MovieNodeBST* parent;
    MovieNodeBST* leftChild;
    MovieNodeBST* rightChild;
    MovieNodeHeap *heap;
    int currentSize = 0;
    int *currentSizePointer;
    MovieNodeBST(){};

    MovieNodeBST(char in_letter, int heapSize)
    {
        letter = in_letter;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
        heap = new MovieNodeHeap[heapSize];
        currentSizePointer = &currentSize;
    };

};

class MovieTree {
public:
    MovieTree();
    ~MovieTree();
    void printMovieInventory();
    int countMovieNodes();
    void deleteMovieNode(std::string title);
    void addMovieNode(int ranking, std::string title, int releaseYear, int quantity,int);
    void findMovie(std::string title);
    void rentMovie(std::string title);
    void printBetween(char,char,int);

protected:

private:
    void DeleteAll(MovieNodeBST * node); //use this for the post-order traversal deletion of the tree
    void printMovieInventory(MovieNodeBST * node);
    void countMovieNodes(MovieNodeBST *node);
    MovieNodeBST* searchBST(MovieNodeBST *node, std::string title); //use this recursive function to find a pointer to a node in the BST, given a MOVIE TITLE
    MovieNodeHeap *searchHeap(MovieNodeBST* letterNode, std::string title,int*); //use this to return a pointer to a node in a linked list, given a MOVIE TITLE and the head of the linked list
    MovieNodeBST* treeMinimum(MovieNodeBST *node); //use this to find the left most leaf node of the BST, you'll need this in the delete function
    void addBSTNode(char,int);
    MovieNodeBST *deleteBSTNode(MovieNodeBST*, char);
    MovieNodeBST* root = NULL;
    void heapPush(MovieNodeHeap*,MovieNodeHeap,int,int*);
    MovieNodeHeap heapPop(MovieNodeHeap*,int,int*);
    void maxHeapify(MovieNodeHeap*,int*,int);
};

#endif //ASSIGNMENT_7_MOVIETREE_H
