// 213. House Robber II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000
#include<iostream>
using namespace std;
class Solution {
public:
vector<vector<int>>dp;
int helper(vector<int>& nums,int idx,bool flag){
    if(idx>=nums.size()) return 0;
    if(dp[idx][flag]!=-1) return dp[idx][flag];
    int leave=helper(nums,idx+1,flag);
    int take=0;
    if(!flag){
        if(idx==0) flag=true;
        take=nums[idx]+helper(nums,idx+2,flag);
    }
    else{
        if(idx!=nums.size()-1){
            take=nums[idx]+helper(nums,idx+2,flag);
        }
    }
    return dp[idx][flag]=max(take,leave);
}
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(2,-1));
        return helper(nums,0,false);
    }
};