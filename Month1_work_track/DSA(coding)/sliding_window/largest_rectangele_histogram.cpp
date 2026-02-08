// 84. Largest Rectangle in Histogram
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

// Example 1:


// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:


// Input: heights = [2,4]
// Output: 4
 

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int max_ans = 0;

        for (int i = 0; i < n; i++) {
            // Logic Fix 1: Pop when the current bar is SMALLER than the stack top.
            // This maintains a strictly increasing stack to find the NSE.
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                int nse_index = i;
                int top = st.top(); // top is the index of the bar
                st.pop();
                
                int pse_index = -1;
                if (!st.empty()) pse_index = st.top();
                
                // Logic Fix 2: Area must be (Width * Height). 
                // Height is nums[top], not top (which is an index).
                max_ans = max(max_ans, (nse_index - pse_index - 1) * nums[top]);
            }
            st.push(i);
        }

        // Processing remaining elements in the stack
        int nse_index = n;
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            
            int pse_index = -1;
            if (!st.empty()) pse_index = st.top();
            
            // Logic Fix 3: Use nums[top] for height here as well.
            max_ans = max(max_ans, (nse_index - pse_index - 1) * nums[top]);
        }

        return max_ans;
    }
};