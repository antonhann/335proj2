#include "myAVLtree.hpp" 
#include <queue>
/**
 * @brief find the height of the node given
 * @param AvlNode
 * @return the int of the height of the avl node
*/
int height(const AvlNode *t ){
    return t == nullptr ? 0 : t->height;
}

/**
 * @brief find the max of the x and y
 * @param int x, int y
 * @return int of the max of x and y
*/
int max(int x, int y){
    return (x >= y) ? x : y;
}

/**
 * @brief see if the tree is empty or not
 * 
 * @return boolean if tree is empty
*/
bool AvlTree::empty(){
    return amount == 0;
}

/**
 * @brief preform right rotate at the given node
 * @param avl node
*/
void rightRotate( AvlNode * & k2 ){
    //preform the right rotate
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    //update the height of the rotated nodes
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;
    
    //change k2 to the new root
    k2 = k1;
}
/**
 * @brief preform left rotate at the given node
 * @param avl node
*/
void leftRotate( AvlNode * & k2 ){
    //preform left rotate
    AvlNode *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    //update the height of the rotated nodes
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
    k1->height = max( height( k1->left ), k2->height ) + 1;

    //change k2 to the new root
    k2 = k1;
}

/**
 * @brief perform left right rotate at the given node
 * @param avl node
*/
void leftRightRotate( AvlNode * & k3 ){
    leftRotate( k3->left ); //left rotate the left node of the given node
    rightRotate( k3 ); //right rotate at the given node
}
/**
 * @brief perform right left rotate at the given node
 * @param avl node
*/
void rightLeftRotate( AvlNode * & k3 ){
    rightRotate( k3->right ); //right rotate at the right node of the given node
    leftRotate( k3 ); //left rotate at the given node
}
/**
 * @brief perform balance operation at the given node
 * @param avl node
*/
void balance( AvlNode *&t){
    if( t == nullptr ) return;

    int difference = height( t->left ) - height( t->right ); //difference in height from left node and right node
    
    if (difference < -1){
        //if difference less than negative 1 and right node's difference is also negative,
        //left rotate at the given node
        if(t->right && height( t->right->left ) - height( t->right->right ) < 0 ){
            leftRotate( t );
        }
        //if difference less than negative 1 and right node's difference is positive,
        //perform right left rotate at the given node
        else{
            rightLeftRotate( t );
        }
    }else if (difference > 1){
        //if difference greater than 1 and left node's difference is also positive,
        //right rotate at the given node
        if(t->left && height( t->left->left ) - height( t->left->right ) > 0){
            rightRotate( t );
        }
        //if difference greater than 1 and left node's difference is negative,
        //left right rotate at the given node
        else{
            leftRightRotate( t );
        }
    }
    //update the height of the given node
    t->height = max( height( t->left ), height( t->right ) ) + 1;
}
/**
 * @brief insert the node into the given node
 * @param avl node
*/
void insert(const int & x, AvlNode *&t){
    if(t == nullptr){
        //if there isnt a spot for the node, we insert it there
        t = new AvlNode{ x,nullptr,nullptr };
    }
    //if the element is less than the node's element, insert the value into the left node
    else if(x < t->element){
        insert(x, t->left);
    }
    //if the element is greater than the node's element, insert the value into the right node
    else if(x > t->element){
        insert(x, t->right);
    }
    //if the node is equal to the value, we increment the amount of the node by one (handle duplicates)
    else{
        t->amount += 1;
    }
    //balance the node as we traverse back up
    balance( t );
}
/**
 * @brief remove the node at the given node
 * @param avl node
*/
void remove( const int & x, AvlNode *&t){
    if(t == nullptr){
        return;
    }
    //if the node's element less than the value, remove the val at the right node
    if(t->element < x){
        remove(x, t->right);
    }
    //if the node's element greater than the value, remove the val at the left node
    else if(t->element > x){
        remove(x, t->left);
    }
    //we found the node that is being removed!
    else{
        //if the node has an amount greater than 1, decrement it by one
        if(t->amount > 1){
            t->amount -= 1;
        }
        //if the node has no children, simply delete the node and update pointer for memory leak
        else if(t->left == nullptr && t->right == nullptr){
            delete t;
            t = nullptr;
            return;
        }
        //if the node has one children, make the removed node to any of the children, and delete the node we need to remove
        else if(t->left == nullptr || t->right == nullptr){
            AvlNode *temp = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete temp;
            temp = nullptr;
            return;  
        }
        //if the node has two children, we make the swap the nodes with the right successor,
        //and then remove the successor node in the right side
        else{
            AvlNode *curr = t->right;
            while(curr->left != nullptr){
                curr = curr->left;
            }
            t->element = curr->element;
            remove(curr->element, t->right);
        }
    }   
    //balance each node as we traverse back up to the first call
    balance(t);
}
//helps me visualize by printing the tree to the terminal
// void printBinaryTree(AvlNode* root) {
//     if (root == nullptr)
//         return;

//     std::queue<AvlNode*> q;
//     q.push(root);
//     while (!q.empty()) {
//         int levelSize = q.size();
//         if(q.front()){
//             for(int i = 0; i < height(q.front()); i ++){
//                 std:: cout << " ";
//             }
//         }
//         for (int i = 0; i < levelSize; ++i) {
//             AvlNode* curr = q.front();
//             q.pop();
//             if (curr == nullptr) {
//                 std::cout << "n ";
//                 continue;
//             }else{
//                 int difference = height( curr->left ) - height( curr->right );
//                 std::cout << curr->element << " (" << height( curr ) << ") ";
//                 q.push(curr->left);
//                 q.push(curr->right);
//             }
//         }
//         std::cout << std::endl;
//     }
// }

/**
 * @brief find the min at the tree
 * 
 * @return the avl node of the min element
*/
AvlNode* AvlTree::getMin(){
    AvlNode* curr = root;
    //min will be at the left most of the tree
    while(curr->left != nullptr){
        curr = curr->left;
    }
    return curr;
}
/**
 * @brief find the max at the tree
 * 
 * @return the avl node of the max element
*/
AvlNode* AvlTree::getMax(){
    AvlNode* curr = root;
    //max will be at the right most of the tree
    while(curr->right != nullptr){
        curr = curr->right;
    }
    return curr;
}

/**
 * @brief find the min at the tree
 * @param 
 * reference of the AvlTree that holds the elements smaller than or equal to the median
 * reference of the AvlTree that holds the elements greater than the median
 * int value of the what is being inserted into this structure
*/
void insertAvlMedian(AvlTree& small, AvlTree& large, int val){
    if(small.empty()){
        //if small is empty insert the val into the small tree
        insert(val, small.root);
        small.amount += 1; //increment the size of the small tree
    }
    else{
        AvlNode* smallMax = small.getMax(); //the max of the small tree
        //find which tree the element belongs in
        if(val >= smallMax->element){
            //insert into large tree
            insert(val, large.root);
            large.amount += 1; //increment size of large tree
            if(large.amount == small.amount + 1){
                //rebalance the structure to keep size constraint
                //by adding the the min of large tree to small tree, then removing the min of the large tree
                AvlNode* largeMin = large.getMin();
                insert(largeMin->element,small.root);
                small.amount += 1;
                remove(largeMin->element,large.root);
                large.amount -= 1;
            }
        }else{
            //insert into small tree
            insert(val, small.root);
            small.amount += 1; //increment size of small tree
            if(small.amount == large.amount + 2){
                //rebalance the structure to keep size constraint
                //by adding the the max of small tree to large tree, then removing the max of the small tree
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
    AvlTree small; //avl tree that will hold all the elements less than or equal to the median
    AvlTree large; //avl tree that will hold all the elements greater than the median 
    std::vector<int> res; //result vector that will hold the popped medians
    const auto start = std::chrono::steady_clock::now(); //start time
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        //iterate through the instructions 
        if(*it != -1){
            //insert the value into the structure if the current iteration is not -1
            insertAvlMedian(small,large,*it);
        }else{
            //get the median of the structure (max element at the small tree)
            AvlNode* smallMax = small.getMax();
            res.push_back(smallMax->element);
            //pop the median
            remove(smallMax->element,small.root);
            small.amount -= 1;

            //rebalance the structure to keep size constraint
            //by adding the the min of large tree to small tree, then removing the min of the large tree
            if(large.amount == small.amount + 1){
                AvlNode* largeMin = large.getMin();
                insert(largeMin->element, small.root);
                small.amount += 1;
                remove(largeMin->element, large.root);
                large.amount -= 1;
            }
        }
    }
    const auto end = std::chrono::steady_clock::now(); //end time
    int time = std::chrono::duration <double, std::micro> (end - start).count(); //time taken to complete instructions
    // std::cout << "AVL Tree Median ran in "<<  time << " microseconds." << std::endl;
    for(int i = 0; i < res.size(); i++){
        //print the popped medians to the terminal
        std::cout << res[i] << " ";
    }   
}