// 421. Maximum XOR of Two Numbers in an Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

// Example 1:

// Input: nums = [3,10,5,25,2,8]
// Output: 28
// Explanation: The maximum result is 5 XOR 25 = 28.
// Example 2:

// Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// Output: 127
 

// Constraints:

// 1 <= nums.length <= 2 * 105
// 0 <= nums[i] <= 231 - 1
#include<iostream>
using namespace std;
class trie{
    public:
    trie* child_0;
    trie* child_1;
    trie(){
        this->child_0=NULL;
        this->child_1=NULL;
    }
    bool check_bit(int n){
        if(n==0) return child_0!=NULL;
        else return child_1!=NULL;
    }
    void insert(int n,trie* node){
        if(n==0) child_0=node;
        else child_1=node;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie* root= new trie();
        // numbers are inserted to the trie
        for(int n:nums){
            trie* node=root;
            for(int i=31;i>=0;i--){
                if(n&(1<<i)){
                    if(!node->check_bit(1)){
                        node->insert(1,new trie());
                    }
                    node=node->child_1;
                }
                else{
                    if(!node->check_bit(0)){
                        node->insert(0,new trie());
                    }
                    node=node->child_0;
                }
            }
        }
        int max_answer=0;
        for(int n:nums){
            int ans=0;
            trie* node=root;
            for(int i=31;i>=0;i--){
                if(n&(1<<i)){
                    if(node->child_0) ans=ans|(1<<i),node=node->child_0;
                    else node=node->child_1;
                }
                else{
                    if(node->child_1) ans=ans|(1<<i),node=node->child_1;
                    else node=node->child_0;
                }
            }
            max_answer=max(max_answer,ans);
        }
        return max_answer;
    }
};