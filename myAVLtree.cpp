#include "myAVLtree.hpp" 
#include <queue>
int height(const AvlNode *t ){
    return t == nullptr ? 0 : t->height;
}
int max(int x, int y){
    return (x >= y) ? x : y;
}
void rightRotate( AvlNode * & k2 ){
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2 = k1;
}
void leftRotate( AvlNode * & k2 ){
    AvlNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    k2 = k1;
}
void leftRightRotate( AvlNode * & k3 ){
    leftRotate( k3->left );
    rightRotate( k3 );
}
void rightLeftRotate( AvlNode * & k3 ){
    // rightRotate( k3->right );
    // leftRotate( k3 );
}
void balance( AvlNode *&t){
    if( t == nullptr ) return;
    int difference = height( t->left ) - height( t->right );
    if (difference < -1){
        if(t->right && height( t->right->left ) - height( t->right->right ) < 0 ){
            leftRotate( t );
        }
        else{
            rightLeftRotate( t );
        }
    }else if (difference > 1){
        if(t->left && height( t->left->left ) - height( t->left->right ) > 0){
            rightRotate( t );
        }else{

            leftRightRotate( t );
        }
    }
    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

void insert(const int & x, AvlNode *&t){
    if(t == nullptr){
        t = new AvlNode{ x,nullptr,nullptr };
    }else if(x < t->element){
        insert(x, t->left);
    }else if(x > t->element){
        insert(x, t->right);
    }else{
        t->amount += 1;
    }
    balance( t );
}
void remove( const int & x, AvlNode *&t){
    if(t == nullptr){
        return;
    }
    if(t->element < x){
        remove(x, t->right);
    }
    else if(t->element > x){
        remove(x, t->left);
    }else{
        if(t->amount > 1){
            t->amount -= 1;
        }else{
            if(t->left == nullptr && t->right == nullptr){
                delete t;
                t = nullptr;
                return;
            }
            else if(t->left == nullptr || t->right == nullptr){
                AvlNode *temp = t;
                t = (t->left != nullptr) ? t->left : t->right;
                delete temp;
                temp = nullptr;
                return;
            }else{
                AvlNode *curr = t->right;
                while(curr->left != nullptr){
                    curr = curr->left;
                }
                t->element = curr->element;
                remove(curr->element, t->right);
            }
        }
    }   
    balance(t);
}
void printBinaryTree(AvlNode* root) {
    if (root == nullptr)
        return;

    std::queue<AvlNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        if(q.front()){
            for(int i = 0; i < height(q.front()); i ++){
                std:: cout << " ";
            }
        }
        for (int i = 0; i < levelSize; ++i) {
            AvlNode* curr = q.front();
            q.pop();
            if (curr == nullptr) {
                std::cout << "n ";
                continue;
            }else{
                int difference = height( curr->left ) - height( curr->right );
                std::cout << curr->element << " (" << height( curr ) << ") ";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        std::cout << std::endl;
    }
}
void treeMedian (const std::vector<int> * instructions){
    AvlNode *root = nullptr;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        insert(*it, root);
    }
    remove(2,root);
    printBinaryTree(root);

}