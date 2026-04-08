//  Children Sum Property
// Moderate
// 80/80
// Average time to solve is 36m
// Contributed by
// 212 upvotes
// Asked in companies
// Problem statement
// Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.

// A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).

// Note :
//  1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
//  2. You can not change the structure of the original binary tree.
//  3. A binary tree is a tree in which each node has at most two children.      
//  4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 10^2
// 0 <= N <= 10^2
// 1 <= node.Value <= 10^6

// Time Limit : 1 sec
// Sample Input 1 :
// 1
// 2 35 10 2 3 5 2 -1 -1 -1 -1 -1 -1 -1 -1 
// Sample Output 1 :
// Valid ( One of the possible answers is : 45 35 10 32 3 8 2 -1 -1 -1 -1 -1, thus if the user modifies the given tree like this, the output printed will be valid).
// Explanation For Sample Input 1 :
// The tree can be represented as follows :

// The value at the root node is 2 which is less than the sum of its children’s values (35 + 10). So we simply increase the value at the root node to 45. The node with value  = 35 has children with values 2 and 3 so their sum i.s 2 + 3 = 5 < 35. As we can't decrement any value, so instead we have to increase the sum of children and thus we update 35's children (2 and 3) as 30 and 5 so that 30 + 5 = 35 and the same is done for the children of the node with value = 10.
// The final tree looks like this :

// Note that there can be many other valid solutions.
// Sample Input 2 :
// 1
// 10 5 5 -1 -1 -1 -1
// Sample Output 2 :
// Valid
#include<iostream>
using namespace std;

    class BinaryTreeNode
    {
    public :
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
void increase(BinaryTreeNode* root,int by){
    if(root->left==NULL&&root->right==NULL){
        root->data+=by;
        return;
    }
    root->data+=by;
    if(root->left) increase(root->left,by);
    else increase(root->right,by);
}
int helper(BinaryTreeNode * root){
    if(root==NULL) return 0;
    if(root->left==NULL&&root->right==NULL) return root->data;
    int left=helper(root->left);
    int right=helper(root->right);
    if(root->data<=left+right){
        root->data=left+right;
        return root->data;
    }
    else{
        if(root->left) increase(root->left,root->data-(left+right));
        else increase(root->right,root->data-(left+right));
        return root->data;
    }
}
void changeTree(BinaryTreeNode * root) {
    // Write your code here.
    int x=helper(root);
}  