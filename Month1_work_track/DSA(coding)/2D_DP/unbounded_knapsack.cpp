
// Knapsack with Duplicate Items
// Difficulty: MediumAccuracy: 52.13%Submissions: 225K+Points: 4
// Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively. Also, a knapsack with a weight limit capacity.
// Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

// Note: Each item can be taken any number of times.

// Examples:

// Input: val[] = [1, 1], wt[] = [2, 1], capacity = 3
// Output: 3
// Explanation: The optimal choice is to pick the 2nd element 3 times.
// Input: val[] = [10, 40, 50, 70], wt[] = [1, 3, 4, 5], capacity = 8
// Output: 110
// Explanation: The optimal choice is to pick the 2nd element and the 4th element.
// Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
// Output: 0
// Explanation: We can't pick any element. Hence, total profit is 0.
// Constraints:
// 1 ≤ val.size() = wt.size() ≤ 1000
// 1 ≤ capacity ≤ 1000
// 1 ≤ val[i], wt[i] ≤ 100
#include<iostream>
using namespace std;
class Solution {
  public:
  vector<vector<int>>dp;
  int helper(vector<int> &val, vector<int> &wt,int idx,int W){
      if(idx>=val.size()){
          return 0;
      }
      if(dp[idx][W]!=-1) return dp[idx][W];
      int leave=helper(val,wt,idx+1,W);
      int take=0;
      if(W-wt[idx]>=0) take=val[idx]+helper(val,wt,idx,W-wt[idx]);
      return dp[idx][W]=max(take,leave);
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        dp.resize(n,vector<int>(capacity+1,-1));
        return helper(val,wt,0,capacity);
    }
};