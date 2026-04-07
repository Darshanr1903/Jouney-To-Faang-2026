
// Top View of Binary Tree
// Difficulty: MediumAccuracy: 38.43%Submissions: 453K+Points: 4Average Time: 45m
// You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Note:

// Return the nodes from the leftmost node to the rightmost node.
// If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
// Examples:

// Input: root = [1, 2, 3]
// Output: [2, 1, 3]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
// Input: root = [10, 20, 30, 40, 60, 90, 100]
// Output: [40, 20, 10, 30, 100]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.


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

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
  
    vector<int> topView(Node *root) {
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
                if(mp.find(curr.second.second)==mp.end()){
                    mp[curr.second.second]=curr.first->data;
                }
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