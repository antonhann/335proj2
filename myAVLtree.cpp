#include "myAVLtree.hpp" 
#include <queue>
int height(const AvlNode *t ){
    return t == nullptr ? 0 : t->height;
}
int max(int x, int y){
    return (x >= y) ? x : y;
}
bool AvlTree::empty(){
    return amount == 0;
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
            if(t->amount > 1){
                t->amount -= 1;
            }
            else if(t->left == nullptr && t->right == nullptr){
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
AvlNode* AvlTree::getMin(){
    AvlNode* curr = root;
    while(curr->left != nullptr){
        curr = curr->left;
    }
    return curr;
}
AvlNode* AvlTree::getMax(){
    AvlNode* curr = root;
    while(curr->right != nullptr){
        curr = curr->right;
    }
    return curr;
}
void insertAvlMedian(AvlTree& small, AvlTree& large, int val){
    if(small.empty()){
        insert(val, small.root);
        small.amount += 1;
    }
    else if (large.empty()){
        AvlNode* smallMax = small.getMax();
        if(val >= smallMax->element){
            insert(val, large.root);
            large.amount += 1;
        }
        else{
            insert(smallMax->element,large.root);
            remove(smallMax->element, small.root);
            insert(val, small.root);
            large.amount += 1;
        }
    }else{
        AvlNode* largeMin = large.getMin();
        if(val >= largeMin->element){
            insert(val, large.root);
            large.amount += 1;
            if(large.amount == small.amount + 1){
                insert(largeMin->element,small.root);
                small.amount += 1;
                remove(largeMin->element,large.root);
                large.amount -= 1;
            }
        }else{
            insert(val, small.root);
            small.amount += 1;
            if(small.amount == large.amount + 2){
                AvlNode* smallMax = small.getMax();
                insert(smallMax->element,large.root);
                large.amount += 1;
                remove(smallMax->element, small.root);
                small.amount -= 1;
            }
        }
    }
}
void treeMedian (const std::vector<int> * instructions){
    AvlTree small;
    AvlTree large;
    std::vector<int> res;
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if(*it != -1){
            insertAvlMedian(small,large,*it);
        }else{
            AvlNode* smallMax = small.getMax();
            // std::cout << "Median Popped: " << smallMax->element << std::endl;
            res.push_back(smallMax->element);
            remove(smallMax->element,small.root);
            small.amount -= 1;
            if(large.amount == small.amount + 1){
                AvlNode* largeMin = large.getMin();
                insert(largeMin->element, small.root);
                small.amount += 1;
                remove(largeMin->element, large.root);
                large.amount -= 1;
            }
        }
    }
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i] << " ";
    }   
}