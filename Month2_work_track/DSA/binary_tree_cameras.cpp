// 968. Binary Tree Cameras
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

// Return the minimum number of cameras needed to monitor all nodes of the tree.

 

// Example 1:


// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
// Example 2:


// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// Node.val == 0
#include<iostream>
#include<map>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    // Memoization table to prevent Time Limit Exceeded (TLE)
    // Key: {TreeNode*, {kept_above, root_watched}}, Value: min cameras
    map<pair<TreeNode*, pair<bool, bool>>, int> memo;

public:
    int helper(TreeNode* root, bool kept_above, bool root_watched) {
        if(root == NULL) {
            // If we are forcing a camera on a NULL node, it's impossible.
            // Return a large number to invalidate this path.
            if(!kept_above && !root_watched) return 1e5; 
            return 0;
        }
        
        // Leaf node base case (Your original logic works perfectly here!)
        if(root->left == NULL && root->right == NULL) return !kept_above;

        // Check cache
        if (memo.count({root, {kept_above, root_watched}}))
            return memo[{root, {kept_above, root_watched}}];

        if(kept_above){
            // STATE 1: Parent has a camera. We are safe.
            int keep = 1 + helper(root->left, true, true) + helper(root->right, true, true);
            int leave = helper(root->left, false, true) + helper(root->right, false, true);
            return memo[{root, {kept_above, root_watched}}] = min(keep, leave);
        }
        
        if(root_watched){
            // STATE 2: Parent has NO camera, but we have a choice. 
            // We can either place a camera here, OR force at least one child to place a camera.
            int keep = 1 + helper(root->left, true, true) + helper(root->right, true, true);
            
            // Option A: Force LEFT child to have a camera, right child has a choice.
            int leave_left = helper(root->left, false, false) + helper(root->right, false, true);
            
            // Option B: Force RIGHT child to have a camera, left child has a choice.
            int leave_right = helper(root->left, false, true) + helper(root->right, false, false);
            
            return memo[{root, {kept_above, root_watched}}] = min({keep, leave_left, leave_right});
        }
        
        // STATE 3: If we reach here (!kept_above && !root_watched), we are FORCED 
        // to place a camera on this node (because a parent forced us to watch it).
        return memo[{root, {kept_above, root_watched}}] = 1 + helper(root->left, true, true) + helper(root->right, true, true);
    }

    int minCameraCover(TreeNode* root) {
        // Start at root. It has no parent camera (false), but it has a choice (true).
        return helper(root, false, true);
    }
};