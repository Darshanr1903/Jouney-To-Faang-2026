// 3878. Count Good Subarrays
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums.

// A subarray is called good if the bitwise OR of all its elements is equal to at least one element present in that subarray.

// Return the number of good subarrays in nums.

// Here, the bitwise OR of two integers a and b is denoted by a | b.

 

// Example 1:

// Input: nums = [4,2,3]

// Output: 4

// Explanation:

// The subarrays of nums are:

// Subarray	Bitwise OR	Present in Subarray
// [4]	4 = 4	Yes
// [2]	2 = 2	Yes
// [3]	3 = 3	Yes
// [4, 2]	4 | 2 = 6	No
// [2, 3]	2 | 3 = 3	Yes
// [4, 2, 3]	4 | 2 | 3 = 7	No
// Thus, the good subarrays of nums are [4], [2], [3] and [2, 3]. Thus, the answer is 4.

// Example 2:

// Input: nums = [1,3,1]

// Output: 6

// Explanation:

// Any subarray of nums containing 3 has bitwise OR equal to 3, and subarrays containing only 1 have bitwise OR equal to 1.

// In both cases, the result is present in the subarray, so all subarrays are good, and the answer is 6.

 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109
#include<iostream>
using namespace std;
class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<pair<int, int>> ans(n, {-1, -1});
        vector<int> left(32, -1);
        vector<int> right(32, n);
        long long count = 0;

        // Pass 1: Find effective left bounds
        for(int i = 0; i < n; i++){
            // Maintain monotonic stack for the next greater element
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            
            // Set exclusive left bound based on stack
            int effective_left = st.empty() ? -1 : st.top();

            // Restrict bound further based on incompatible bits
            for(int j = 0; j < 32; j++){
                if(!(nums[i] & (1LL << j))){
                    effective_left = max(effective_left, left[j]);
                }
                else left[j]=i;
            }
            ans[i].first = effective_left;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Pass 2: Find effective right bounds
        for(int i = n - 1; i >= 0; i--){
            // Maintain monotonic stack for the next greater or equal element
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            
            // Set exclusive right bound based on stack
            int effective_right = st.empty() ? n : st.top();

            for(int j = 0; j < 32; j++){
                if(!(nums[i] & (1LL << j))){
                    effective_right = min(effective_right, right[j]);
                }
                else right[j]=i;
            }
            ans[i].second = effective_right;
            st.push(i);
        }

        // Pass 3: Calculate the combinations
        for(int i = 0; i < n; i++){
            count += 1LL * (ans[i].second - i) * (i - ans[i].first);
        }
        
        return count;
    }
};