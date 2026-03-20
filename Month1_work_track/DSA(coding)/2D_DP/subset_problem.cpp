
// Subset Sum Problem
// Difficulty: MediumAccuracy: 32.0%Submissions: 443K+Points: 4
// Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

// Examples:

// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
// Output: false
// Explanation: There is no subset with target sum 30.
// Input: arr[] = [1, 2, 3], sum = 6
// Output: true
// Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
// Constraints:
// 1 <= arr.size() <= 200
// 1<= arr[i] <= 200
// 1<= sum <= 104

// Expected Complexities
// Time Complexity: O(sum*n)
// Auxiliary Space: O(sum)
#include<iostream>
using namespace std;
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        // 1. Declare locally to avoid state bleed between test cases.
        vector<int>prev(sum+1,false);
        
        // 2. Base Case: A sum of 0 is always possible (empty subset)
        prev[0]=true;
        
        // 3. Base Case: The first element can achieve a sum equal to its own value
        if (arr[0] <= sum) {
            prev[arr[0]] = true;
        }
        
        // 4. Fill the table
        for (int i = 1; i < n; i++) {
            vector<int>curr(sum+1,false);
            curr[0]=true;
            for (int j = 1; j <= sum; j++) {
                // Not taking the current element
                bool leave = prev[j];
                
                // Taking the current element
                bool take = false;
                if (arr[i] <= j) {
                    take = prev[j - arr[i]];
                }
                
                curr[j] = take || leave;
            }
            prev=curr;
        }
        
        return prev[sum];
    }
};
