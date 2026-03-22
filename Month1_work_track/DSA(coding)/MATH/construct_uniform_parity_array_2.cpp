// 3876. Construct Uniform Parity Array II
// Solved
// Medium
// premium lock icon
// Companies
// Hint
// You are given an array nums1 of n distinct integers.

// You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

// For each index i, you must choose exactly one of the following (in any order):

// nums2[i] = nums1[i]​​​​​​​
// nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
// Return true if it is possible to construct such an array, otherwise return false.

 

// Example 1:

// Input: nums1 = [1,4,7]

// Output: true

// Explanation:​​​​​​​​​​​​​​

// Set nums2[0] = nums1[0] = 1.
// Set nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3.
// Set nums2[2] = nums1[2] = 7.
// nums2 = [1, 3, 7], and all elements are odd. Thus, the answer is true.
// Example 2:

// Input: nums1 = [2,3]

// Output: false

// Explanation:

// It is not possible to construct nums2 such that all elements have the same parity. Thus, the answer is false.

// Example 3:

// Input: nums1 = [4,6]

// Output: true

// Explanation:

// Set nums2[0] = nums1[0] = 4.
// Set nums2[1] = nums1[1] = 6.
// nums2 = [4, 6], and all elements are even. Thus, the answer is true.
 

// Constraints:

// 1 <= n == nums1.length <= 105
// 1 <= nums1[i] <= 109
// nums1 consists of distinct integers.
#include<iostream>
using namespace std;
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int min_odd = INT_MAX;
        bool has_odd = false;
        bool flag = true;

        // Step 1: Find if there are odd numbers, and locate the smallest one
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) {
                has_odd = true;
                if (nums[i] < min_odd) {
                    min_odd = nums[i];
                }
            }
        }

        // Step 2: Equivalent to your first block passing (no odd numbers found)
        if (!has_odd) {
            return true;
        }

        // Step 3: Equivalent to your second block.
        // For the array to be uniform, every even number MUST be > the minimum odd number
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                if (nums[i] < min_odd) {
                    flag = false;
                    break;
                }
            }
        }

        return flag;
    }
};