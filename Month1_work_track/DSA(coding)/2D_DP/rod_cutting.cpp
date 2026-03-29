
// Rod Cutting
// Difficulty: MediumAccuracy: 60.66%Submissions: 208K+Points: 4Average Time: 20m
// Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Note: n = size of price, and price[] is 1-indexed array.

// Example:

// Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
// Output: 22
// Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
// Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
// Output: 24
// Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.
// Input: price[] = [3]
// Output: 3
// Explanation: There is only 1 way to pick a piece of length 1.
// Constraints:
// 1 ≤ price.size() ≤ 103
// 1 ≤ price[i] ≤ 106
#include<iostream>
using namespace std;
// User function Template for C++

class Solution {
  public:
  vector<vector<int>>dp;
  int helper(vector<int>&price,int idx,int length){
      if(idx>=price.size()) return 0;
      if(dp[idx][length]!=-1) return dp[idx][length];
      int leave=helper(price,idx+1,length);
      int take=0;
      if(idx+1<=length){
          take=price[idx]+helper(price,idx,length-idx-1);
      }
      return dp[idx][length]=max(take,leave);
  }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        dp.resize(n,vector<int>(n+1,-1));
        return helper(price,0,price.size());
    }
};