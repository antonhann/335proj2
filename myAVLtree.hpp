#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
struct AvlNode
{
    int element;
    AvlNode *left;
    AvlNode *right;
    int height;
    int amount;

    AvlNode( const int & ele, AvlNode *lt, AvlNode *rt, int h = 1, int a = 1)
    :element{ ele }, left{ lt }, right{ rt }, height{ h }, amount { a }{};

    AvlNode( int && ele, AvlNode *lt, AvlNode *rt, int h = 1, int a = 1)
    :element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h }, amount { a }{};
};
int height(const AvlNode *t );
void insert(const int & x, AvlNode *&t);
void balance(AvlNode *&t);
void rightRotate( AvlNode * & k2 );
void leftRightRotate( AvlNode * & k3 );
void leftRotate( AvlNode * & k2 );
void rightLeftRotate( AvlNode * & k3 );
void remove( const int & x, AvlNode *&t);

void treeMedian (const std::vector<int> * instructions);

