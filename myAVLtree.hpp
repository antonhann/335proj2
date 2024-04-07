#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
#include <chrono>
struct AvlNode
{
    int element;
    AvlNode *left;
    AvlNode *right;
    int height;
    int amount; //amount counter to take care of duplicates

    AvlNode( const int & ele, AvlNode *lt, AvlNode *rt, int h = 1, int a = 1)
    :element{ ele }, left{ lt }, right{ rt }, height{ h }, amount { a }{};

    AvlNode( int && ele, AvlNode *lt, AvlNode *rt, int h = 1, int a = 1)
    :element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h }, amount { a }{};
};
class AvlTree{
    public:
    int amount; //amount counter to take care of size constraint
    AvlNode* root;
    AvlTree() : amount(0), root(nullptr) {};
    bool empty();
    AvlNode* getMin(); 
    AvlNode* getMax();
};
int height(const AvlNode *t );
void insert(const int & x, AvlNode* &tree);
void balance(AvlNode *&t);
void rightRotate( AvlNode * & k2 );
void leftRightRotate( AvlNode * & k3 );
void leftRotate( AvlNode * & k2 );
void rightLeftRotate( AvlNode * & k3 );
void remove( const int & x, AvlNode* &tree);
void insertAvlMedian(AvlTree& small, AvlTree& large, int val);
void treeMedian (const std::vector<int> * instructions);

