#include <iostream>
#include <chrono>
#include <fstream>
#include "BST.h"
#include "AVLTree.h"
#include "RBTree.h"
using namespace std;

void generateRandomNums(int nums[], int size){
    for(int i=0;i<size;i++){
        nums[i] = rand() % 1000;
    }
}
void runAllInsertTest(int num, double* time1, double* time2, double* time3){
    int randomNum[num];
    double totalTime = 0;

    //bst test
    totalTime = 0;
    for(int i=0;i<50;i++){
        BST tree;
        generateRandomNums(randomNum,num);

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        for(int i:randomNum){
            tree.addNode(i);
        }
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time1 = totalTime;

    //avl test
    totalTime = 0;
    for(int i=0;i<50;i++){
        AVLTree tree;
        generateRandomNums(randomNum,num);

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        for(int i:randomNum){
            tree.insert(i);
        }
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time2 = totalTime;

    //rbt test
    totalTime = 0;
    for(int i=0;i<50;i++){
        RBTree tree;
        generateRandomNums(randomNum,num);

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        for(int i:randomNum){
            tree.insertValue(i);
        }
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time3 = totalTime;
}
void runAllFindTest(int num, double* time1, double* time2, double* time3){
    int randomNum[num];
    double totalTime = 0;

    //bst test
    totalTime = 0;
    for(int i=0;i<50;i++){
        BST tree;
        generateRandomNums(randomNum,num);
        for(int i:randomNum){
            tree.addNode(i);
        }

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        tree.findMovie(rand()%1000);
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time1 = totalTime;

    //avl test
    totalTime = 0;
    for(int i=0;i<50;i++){
        AVLTree tree;
        generateRandomNums(randomNum,num);
        for(int i:randomNum){
            tree.insert(i);
        }

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        tree.findNode(rand()%1000);
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time2 = totalTime;

    //rbt test
    totalTime = 0;
    for(int i=0;i<50;i++){
        RBTree tree;
        generateRandomNums(randomNum,num);
        for(int i:randomNum){
            tree.insertValue(i);
        }

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        tree.findNode(rand()%1000);
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time3 = totalTime;
}
void runAllDeleteTest(int num, double* time1, double* time2, double* time3){
    int randomNum[num];
    double totalTime = 0;

    //bst test
    totalTime = 0;
    for(int i=0;i<50;i++){
        BST tree;
        generateRandomNums(randomNum,num);
        for(int i:randomNum){
            tree.addNode(i);
        }

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        tree.deleteNode(rand()%1000);
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time1 = totalTime;

    //avl test
    totalTime = 0;
    for(int i=0;i<50;i++){
        AVLTree tree;
        generateRandomNums(randomNum,num);
        for(int i:randomNum){
            tree.insert(i);
        }

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        int rNum = rand()%1000;
        if(rNum == 972)
            rNum = rand()%1000;
        tree.deleteNode(rNum);
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time2 = totalTime;

    //rbt test
    totalTime = 0;
    for(int i=0;i<50;i++){
        RBTree tree;
        generateRandomNums(randomNum,num);
        for(int i:randomNum){
            tree.insertValue(i);
        }

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        tree.deleteValue(rand()%1000);
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time3 = totalTime;
}
void runAllWorstCaseFindTest(int num, double* time1, double* time2, double* time3){
    double totalTime = 0;

    //bst test
    totalTime = 0;
    for(int i=0;i<50;i++){
        BST tree;
        for(int i=1;i<=num;i++){
            tree.addNode(i);
        }

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        tree.findMovie(rand()%1000);
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time1 = totalTime;

    //avl test
    totalTime = 0;
    for(int i=0;i<50;i++){
        AVLTree tree;
        for(int i=1;i<=num;i++){
            tree.insert(i);
        }

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        tree.findNode(rand()%1000);
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time2 = totalTime;

    //rbt test
    totalTime = 0;
    for(int i=0;i<50;i++){
        RBTree tree;
        for(int i=1;i<=num;i++){
            tree.insertValue(i);
        }

        auto begin = chrono::high_resolution_clock::now();
        // code to benchmark
        tree.findNode(rand()%1000);
        auto end = chrono::high_resolution_clock::now();

        double ns = chrono::duration_cast<chrono::nanoseconds>(end-begin).count();

        totalTime += ns;
    }
    *time3 = totalTime;
}



int main(int argc, char* argv[]) {
    double time1,time2,time3;
    double* bst=&time1;
    double* avl=&time2;
    double* rbtree=&time3;

    std::ofstream myfile;
    myfile.open ("final data.csv");

    myfile <<"Insert Test\n";
    myfile << "Number of Nodes,BST,AVL,Red Black Tree\n";
    runAllInsertTest(100, bst, avl, rbtree);
    myfile << "100,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllInsertTest(500, bst, avl, rbtree);
    myfile << "500,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllInsertTest(1000, bst, avl, rbtree);
    myfile << "1000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllInsertTest(5000, bst, avl, rbtree);
    myfile << "5000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllInsertTest(10000, bst, avl, rbtree);
    myfile << "10000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";

    myfile <<"Delete Test\n";
    myfile << "Number of Nodes,BST,AVL,Red Black Tree\n";
    runAllDeleteTest(100, bst, avl, rbtree);
    myfile << "100,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllDeleteTest(500, bst, avl, rbtree);
    myfile << "500,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllDeleteTest(1000, bst, avl, rbtree);
    myfile << "1000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllDeleteTest(5000, bst, avl, rbtree);
    myfile << "5000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllDeleteTest(10000, bst, avl, rbtree);
    myfile << "10000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";

    myfile <<"Find Test\n";
    myfile << "Number of Nodes,BST,AVL,Red Black Tree\n";
    runAllFindTest(100, bst, avl, rbtree);
    myfile << "100,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllFindTest(500, bst, avl, rbtree);
    myfile << "500,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllFindTest(1000, bst, avl, rbtree);
    myfile << "1000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllFindTest(5000, bst, avl, rbtree);
    myfile << "5000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllFindTest(10000, bst, avl, rbtree);
    myfile << "10000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";

    myfile <<"Worst Case Find Test\n";
    myfile << "Number of Nodes,BST,AVL,Red Black Tree\n";
    runAllWorstCaseFindTest(100, bst, avl, rbtree);
    myfile << "100,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllWorstCaseFindTest(500, bst, avl, rbtree);
    myfile << "500,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllWorstCaseFindTest(1000, bst, avl, rbtree);
    myfile << "1000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllWorstCaseFindTest(5000, bst, avl, rbtree);
    myfile << "5000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";
    runAllWorstCaseFindTest(10000, bst, avl, rbtree);
    myfile << "10000,"<<*bst<<","<<*avl<<","<<*rbtree<<"\n";



    myfile.close();
}