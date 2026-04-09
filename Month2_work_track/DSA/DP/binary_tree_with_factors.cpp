// 823. Binary Trees With Factors
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

// We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

// Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [2,4]
// Output: 3
// Explanation: We can make these trees: [2], [4], [4, 2, 2]
// Example 2:

// Input: arr = [2,4,5,10]
// Output: 7
// Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

// Constraints:

// 1 <= arr.length <= 1000
// 2 <= arr[i] <= 109
// All the values of arr are unique.
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<int, int> s;
    int MOD=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for (int i = 0; i < arr.size(); i++)
            s[arr[i]] = i;
        int sum=0;
        vector<int>dp(arr.size(),0);
        for (int idx = 0; idx < arr.size();idx++) {
            int root = arr[idx];
            long long count = 1;
            for (int i = 0; i < idx; i++) {
                if (root % arr[i] == 0 && s.find(root / arr[i]) != s.end()) {
                    count+=(1LL*dp[i]*dp[s[root/arr[i]]])%MOD;
                }
            }
            dp[idx] = count%MOD;
            sum+=count%MOD;
            sum=sum%MOD;
        }
        return sum;
    }
};
