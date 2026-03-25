
// Minimum sum partition
// Difficulty: HardAccuracy: 38.97%Submissions: 183K+Points: 8
// Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

// Examples:

// Input: arr[] = [1, 6, 11, 5]
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11 
// Hence, minimum difference is 1.  
// Input: arr[] = [1, 4]
// Output: 3
// Explanation: 
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {4}, sum of Subset2 = 4
// Hence, minimum difference is 3.
// Input: arr[] = [1]
// Output: 1
// Explanation: 
// Subset1 = {1}, sum of Subset1 = 1
// Subset2 = {}, sum of Subset2 = 0
// Hence, minimum difference is 1.
// Constraints:
// 1 ≤ arr.size()*|sum of array elements| ≤ 105
// 1 <= arr[i] <= 105

#include<iostream>
using namespace std;
class Solution {
public:
    // Our 2D DP table
    vector<vector<int>> dp;
    int total_sum;

    int helper(vector<int>& arr, int idx, int sum1) {
        // Base case: We've processed all elements
        if (idx >= arr.size()) {
            // If sum1 is the sum of the first subset, 
            // the second subset is just whatever is left over!
            int sum2 = total_sum - sum1;
            return abs(sum1 - sum2);
        }
        
        // Check our 2D vector. If it's not -1, we've solved this exact state before.
        if (dp[idx][sum1] != -1) {
            return dp[idx][sum1];
        }
        
        // Choice 1: Add the current element to subset 1
        int set_1 = helper(arr, idx + 1, sum1 + arr[idx]);
        
        // Choice 2: Do NOT add it to subset 1 (meaning it goes to subset 2)
        int set_2 = helper(arr, idx + 1, sum1);
        
        // Store the best result in our vector and return it
        return dp[idx][sum1] = min(set_1, set_2);
    }

    int minDifference(vector<int>& arr) {
        int n = arr.size();
        total_sum = 0;
        
        // 1. Calculate the absolute total sum of the array
        for (int i = 0; i < n; i++) {
            total_sum += arr[i];
        }
        
        // 2. Size the DP table and fill it with -1 (meaning "uncalculated")
        // Rows = n, Columns = total_sum + 1
        // We use .assign() instead of .resize() to wipe data between test cases!
        dp.assign(n, vector<int>(total_sum + 1, -1));
        
        // 3. Start the recursion!
        return helper(arr, 0, 0);
    }
};