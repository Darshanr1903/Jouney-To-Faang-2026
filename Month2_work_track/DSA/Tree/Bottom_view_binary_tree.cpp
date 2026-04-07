// Bottom View of Binary Tree
// Difficulty: MediumAccuracy: 54.18%Submissions: 349K+Points: 4Average Time: 45m
// You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

// Examples :

// Input: root = [1, 2, 3, 4, 5, N, 6]
    
// Output: [4, 2, 5, 3, 6]
// Explanation: The Green nodes represent the bottom view of below binary tree.
    
// Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
    
// Output: [5, 10, 4, 28, 25]
// Explanation: The Green nodes represent the bottom view of below binary tree.
    
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105
#include<iostream>
#include<map>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        if(root==NULL) return {};
        // code here
        map<int,int>mp;
        queue<pair<Node*,pair<int,int>>>q;
        vector<int>ans;
        q.push({root,{0,0}});
        while(q.size()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto curr=q.front();
                q.pop();
                mp[curr.second.second]=curr.first->data;
                if(curr.first->left) q.push({curr.first->left,{curr.second.first+1,curr.second.second-1}});
                if(curr.first->right) q.push({curr.first->right,{curr.second.first+1,curr.second.second+1}});
            }
        }
        for(auto ele:mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};