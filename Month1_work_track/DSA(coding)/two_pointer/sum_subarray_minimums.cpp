// 907. Sum of Subarray Minimums
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444
 

// Constraints:

// 1 <= arr.length <= 3 * 10^4
// 1 <= arr[i] <= 3 * 10^4
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        long long count = 0; // Use long long to prevent overflow
        stack<int> st;
        int M = 1e9 + 7;

        // Finding Previous Smaller Element
        for(int i = 0; i < n; i++) {
            // Use >= to find the first element strictly smaller
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Finding Next Smaller Element
        for(int i = n - 1; i >= 0; i--) {
            // Use > (instead of >=) to handle duplicate values correctly
            // This ensures each subarray is counted exactly once
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            long long left_dist = i - pse[i];
            long long right_dist = nse[i] - i;
            
            // Correct logic: contribution = value * (subarrays it is min in)
            long long contribution = (left_dist * right_dist) % M;
            contribution = (contribution * nums[i]) % M;
            
            count = (count + contribution) % M;
        }

        return (int)count;
    }
};
