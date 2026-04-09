// 312. Burst Balloons
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

 

// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// Example 2:

// Input: nums = [1,5]
// Output: 10
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// 0 <= nums[i] <= 100
#include<iostream>
using namespace std;
class Solution {
public:
vector<vector<int>>dp;
int helper(vector<int>& nums,int left,int right){
    if(left+1==right) return 0;
    if(dp[left][right]!=-1) return dp[left][right];
    int ans=0;
    for(int i=left+1;i<right;i++){
        int coins=nums[left]*nums[i]*nums[right];
        coins+=helper(nums,left,i)+helper(nums,i,right);
        ans=max(ans,coins);
    }
    return dp[left][right]=ans;
}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int x=n+2;
        vector<int>v(x,0);
        v[0]=1;
        v[x-1]=1;
        for(int i=0;i<n;i++){
            v[i+1]=nums[i];
        }
        dp.resize(x,vector<int>(x,-1));
        return helper(v,0,x-1);

        
    }
};