// 322. Coin Change
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
 

// Constraints:

// 1 <= coins.length <= 12
// 1 <= coins[i] <= 231 - 1
// 0 <= amount <= 104
#include<iostream>
using namespace std;
class Solution {
public:
vector<vector<int>>dp;
int helper(vector<int>&nums,int idx,int amount){
    //if(amount==0) return 0;
    if(idx>=nums.size()){
        if(amount==0) return 0;
        return INT_MAX;
    }
    if(dp[idx][amount]!=-1) return dp[idx][amount];
    int leave=helper(nums,idx+1,amount);
    int take=INT_MAX;
    if(nums[idx]<=amount){
        take=helper(nums,idx,amount-nums[idx]);
        if(take!=INT_MAX) take++;
    }
    return dp[idx][amount]=min(take,leave);
}
    int coinChange(vector<int>& nums, int amount) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(amount+1,INT_MAX));
        dp[n][0]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=amount;j++){
                int leave=dp[i+1][j];
                int take=INT_MAX;
                if(nums[i]<=j){
                    take=dp[i][j-nums[i]];
                    if(take!=INT_MAX) take++;
                }
                dp[i][j]=min(take,leave);
            }
        }
        if(dp[0][amount]==INT_MAX) return -1;
        return dp[0][amount];
    }
};