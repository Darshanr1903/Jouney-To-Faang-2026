// 99. Recover Binary Search Tree
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

// Example 1:


// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
// Example 2:


// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<iostream>
using namespace std;
class Solution {
public:
vector<TreeNode*>v;
void helper(TreeNode* root){
    if(root==NULL) return;
    helper(root->left);
    v.push_back(root);
    helper(root->right);
}
    void recoverTree(TreeNode* root) {
        helper(root);
        int i=-1,j=-1;
        for(int k=0;k<v.size();k++){
            if(k==0||k==v.size()-1){
                 if(k==0){
                    if(v[k]->val>v[k+1]->val){
                        i=k;
                    }
                 }
                 else{
                    if(v[k]->val<v[k-1]->val){
                        j=k;
                    }
                 }
            }
            else{
                if(v[k]->val<v[k+1]->val&&v[k]->val>v[k-1]->val) continue;
                else{
                    if(i==-1) i=k;
                    else{
                        j=k;
                    }
                }
            }
        }
        int temp=v[i]->val;
        v[i]->val=v[j]->val;
        v[j]->val=temp;
    }
};
