// Partitions with Given Difference
// Difficulty: MediumAccuracy: 36.76%Submissions: 228K+Points: 4Average Time: 20m
// Given an array arr[] and an integer diff, count the number of ways to partition the array into two subsets such that the difference between their sums is equal to diff.

// Note: A partition in the array means dividing an array into two subsets say S1 and S2 such that the union of S1 and S2 is equal to the original array and each element is present in only one of the subsets.

// Examples :

// Input: arr[] = [5, 2, 6, 4], diff = 3
// Output: 1
// Explanation: There is only one possible partition of this array. Partition : [6, 4], [5, 2]. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.
// Input: arr[] = [1, 1, 1, 1], diff = 0 
// Output: 6 
// Explanation: We can choose two 1's from indices [0,1], [0,2], [0,3], [1,2], [1,3], [2,3] and put them in sum1 and remaning two 1's in sum2.
// Thus there are total 6 ways for partition the array arr. 
// Input: arr[] = [3, 2, 7, 1], diff = 4  
// Output: 0
// Explanation: There is no possible partition of the array that satisfy the given difference. 
// Constraint:
// 1 ≤ arr.size() ≤ 50
// 0 ≤ diff ≤ 50
// 0 ≤ arr[i] ≤ 6
#include<iostream>
using namespace std;
class Solution {
  public:
  vector<vector<int>>dp;
  int total_sum;
  int helper(vector<int>& arr,int idx, int target,int diff){
      if(idx>=arr.size()) return (target-(total_sum-target))==diff;
      if(dp[idx][target]!=-1) return dp[idx][target];
      int leave=helper(arr,idx+1,target,diff);
      int take=helper(arr,idx+1,target+arr[idx],diff);
      return dp[idx][target]=take+leave;
      
  }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        total_sum=0;
        for(auto ele:arr) total_sum+=ele;
        dp.resize(n,vector<int>(total_sum+1,-1));
        return helper(arr,0,0,diff);
    }
};
