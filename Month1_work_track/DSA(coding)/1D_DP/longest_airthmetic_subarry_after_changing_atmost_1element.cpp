// 3872. Longest Arithmetic Sequence After Changing At Most One Element
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums.

// A subarray is arithmetic if the difference between consecutive elements in the subarray is constant.

// You can replace at most one element in nums with any integer. Then, you select an arithmetic subarray from nums.

// Return an integer denoting the maximum length of the arithmetic subarray you can select.

 

// Example 1:

// Input: nums = [9,7,5,10,1]

// Output: 5

// Explanation:

// Replace nums[3] = 10 with 3. The array becomes [9, 7, 5, 3, 1].
// Select the subarray [9, 7, 5, 3, 1], which is arithmetic because consecutive elements have a common difference of -2.
// Example 2:

// Input: nums = [1,2,6,7]

// Output: 3

// Explanation:

// Replace nums[0] = 1 with -2. The array becomes [-2, 2, 6, 7].
// Select the subarray [-2, 2, 6, 7], which is arithmetic because consecutive elements have a common difference of 4.
 

// Constraints:

// 4 <= nums.length <= 105
// 1 <= nums[i] <= 105
#include<iostream>
using namespace std;
class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        // L[i]: max length of arithmetic subarray ending at i
        // R[i]: max length of arithmetic subarray starting at i
        vector<int> L(n, 2), R(n, 2);
        L[0] = 1; 
        R[n-1] = 1;
        
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                L[i] = L[i-1] + 1;
            }
        }
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i+1] - nums[i] == nums[i+2] - nums[i+1]) {
                R[i] = R[i+1] + 1;
            }
        }
        
        int ans = 2;
        
        // Edge cases: changing the first or last element
        ans = max(ans, R[1] + 1);
        ans = max(ans, L[n-2] + 1);
        
        // Changing a middle element at index i
        for (int i = 1; i < n - 1; i++) {
            
            // Case A: we change nums[i] to just extend the left or right subarray
            ans = max(ans, L[i-1] + 1);
            ans = max(ans, R[i+1] + 1);
            
            // Case B: we change nums[i] to perfectly bridge nums[i-1] and nums[i+1]
            if ((nums[i+1] - nums[i-1]) % 2 == 0) {
                int diff = (nums[i+1] - nums[i-1]) / 2;
                int current_len = 3; // The bridge forms an AP: nums[i-1], new_nums[i], nums[i+1]
                
                // Does the left subarray share this exact same difference?
                if (i - 1 > 0 && nums[i-1] - nums[i-2] == diff) {
                    // Subtract 1 because nums[i-1] is already counted in current_len
                    current_len += L[i-1] - 1; 
                }
                
                // Does the right subarray share this exact same difference?
                if (i + 1 < n - 1 && nums[i+2] - nums[i+1] == diff) {
                    // Subtract 1 because nums[i+1] is already counted in current_len
                    current_len += R[i+1] - 1;
                }
                
                ans = max(ans, current_len);
            }
        }
        
        return ans;
    }
};
