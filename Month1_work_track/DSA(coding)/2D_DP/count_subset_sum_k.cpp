// Perfect Sum Problem
// Difficulty: MediumAccuracy: 20.58%Submissions: 618K+Points: 4
// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

// Examples:

// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
// Input: arr[] = [2, 5, 1, 4, 3], target = 10
// Output: 3
// Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.
// Input: arr[] = [5, 7, 8], target = 3
// Output: 0
// Explanation: There are no subsets of the array that sum up to the target 3.
// Input: arr[] = [35, 2, 8, 22], target = 0
// Output: 1
// Explanation: The empty subset is the only subset with a sum of 0.
// Constraints:
// 1 ≤ arr.size() ≤ 103
// 0 ≤ arr[i] ≤ 103
// 0 ≤ target ≤ 103
#include<iostream>
using namespace std;
class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        // Edge case: empty array
        if (n == 0) return target == 0 ? 1 : 0;
        
        int MOD = 1e9 + 7;
        
        // Use target + 1 instead of hardcoding 1001
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        // CORRECT INITIALIZATION for the last row (i = n - 1)
        if (arr[n-1] == 0) {
            dp[n-1][0] = 2; // 2 ways to make sum 0 if the element is 0 (pick or leave)
        } else {
            dp[n-1][0] = 1; // 1 way to make sum 0 (leave it)
            if (arr[n-1] <= target) {
                dp[n-1][arr[n-1]] = 1; // 1 way to make sum equal to the element (pick it)
            }
        }
        
        // DP Transitions
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= target; j++) {
                int leave = dp[i+1][j];
                int take = 0;
                
                if(arr[i] <= j) {
                    take = dp[i+1][j - arr[i]];
                }
                
                // Add Modulo to prevent integer overflow
                dp[i][j] = (take + leave) % MOD; 
            }
        }
        return dp[0][target];
    }
};
