
// Max Sum without Adjacents
// Difficulty: MediumAccuracy: 47.25%Submissions: 134K+Points: 4Average Time: 20m
// Given an array arr containing positive integers. Find the maximum sum of elements of any possible subsequence such that no two numbers in the subsequence should be adjacent in array arr[].

// Examples:

// Input: arr[] = [5, 5, 10, 100, 10, 5]
// Output: 110
// Explanation: If you take indices 0, 3 and 5, then = 5+100+5 = 110.
// Input: arr[] = [3, 2, 7, 10]
// Output: 13
// Explanation: 3 and 10 forms a non continuous subsequence with maximum sum.
// Input: arr[] = [9, 1, 6, 10]
// Output: 19
// Explanation: 9 and 10 forms a non continuous subsequence with maximum sum.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arri ≤ 105
#include<iostream>
using namespace std;
// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    // int pick_number(vector<int>& arr,int idx,vector<int>&dp){
    //     if(idx>=arr.size()) return 0;
    //     if(dp[idx]!=-1) return dp[idx];
    //     int take=arr[idx]+pick_number(arr,idx+2,dp);
    //     int leave=pick_number(arr,idx+1,dp);
    //     return dp[idx]=max(take,leave);
    // }
    int findMaxSum(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        // code here
        int n=arr.size();
        int prev2=0;
        int prev1=arr[n-1];
        for(int i=n-2;i>=0;i--){
            int take=arr[i]+prev2;
            int leave=prev1;
            int curr=max(take,leave);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};

