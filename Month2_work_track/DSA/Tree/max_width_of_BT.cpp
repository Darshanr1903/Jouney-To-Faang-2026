// 662. Maximum Width of Binary Tree
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

// It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

// Example 1:


// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
// Example 2:


// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
// Example 3:


// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2 (3,2).
 

// Constraints:

// The number of nodes in the tree is in the range [1, 3000].
// -100 <= Node.val <= 100
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };
#include<iostream>
using namespace std;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        deque<pair<TreeNode*, unsigned long long>> q;  // Track node and its position
        q.push_back({root, 1});
        int max1 = 0;
        
        while (!q.empty()) {
            int level_size = q.size();
            unsigned long long left_pos = q.front().second;
            unsigned long long right_pos = q.back().second;
            max1 = max(max1, (int)(right_pos - left_pos + 1));
            
            for (int i = 0; i < level_size; ++i) {
                auto curr = q.front();
                q.pop_front();
                
                if (curr.first->left) {
                    q.push_back({curr.first->left, 2 * curr.second});
                }
                if (curr.first->right) {
                    q.push_back({curr.first->right, 2 * curr.second + 1});
                }
            }
        }
        
        return max1;
    }
};