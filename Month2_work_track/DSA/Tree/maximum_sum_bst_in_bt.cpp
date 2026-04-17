// 1373. Maximum Sum BST in Binary Tree
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:



// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// Output: 20
// Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
// Example 2:



// Input: root = [4,3,null,1,2]
// Output: 2
// Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
// Example 3:

// Input: root = [-4,-2,-5]
// Output: 0
// Explanation: All values are negatives. Return an empty BST.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 4 * 104].
// -4 * 104 <= Node.val <= 4 * 104
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
int max1=INT_MIN;
vector<int> helper(TreeNode* root){
    if(root==NULL){//{min,max,sum}
        return {INT_MAX,INT_MIN,0};
    }
    vector<int>left=helper(root->left);
    vector<int>right=helper(root->right);
    if(root->val>left[1]&&root->val<right[0]){
        // valid bst
        int sum=root->val+left[2]+right[2];
        max1=max(max1,sum);
        return {min(left[0],root->val),max(root->val,right[1]),sum};

    }
    else{
        return {INT_MIN,INT_MAX,0};
    }
}
    int maxSumBST(TreeNode* root) {
        helper(root);
        if(max1<0) return 0;
        return  max1;
    }
};