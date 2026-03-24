// 3877. Minimum Removals to Achieve Target XOR
// Solved
// Medium
// premium lock icon
// Companies
// Hint
// You are given an integer array nums and an integer target.

// You may remove any number of elements from nums (possibly zero).

// Return the minimum number of removals required so that the bitwise XOR of the remaining elements equals target. If it is impossible to achieve target, return -1.

// The bitwise XOR of an empty array is 0.

 

// Example 1:

// Input: nums = [1,2,3], target = 2

// Output: 1

// Explanation:

// Removing nums[1] = 2 leaves [nums[0], nums[2]] = [1, 3].
// The XOR of [1, 3] is 2, which equals target.
// It is not possible to achieve XOR = 2 in less than one removal, therefore the answer is 1.
// Example 2:

// Input: nums = [2,4], target = 1

// Output: -1

// Explanation:

// It is impossible to remove elements to achieve target. Thus, the answer is -1.

// Example 3:

// Input: nums = [7], target = 7

// Output: 0

// Explanation:

// The XOR of all elements is nums[0] = 7, which equals target. Thus, no removal is needed.

 

// Constraints:

// 1 <= nums.length <= 40
// 0 <= nums[i] <= 104
// 0 <= target <= 104
#include<iostream>
using namespace std;
class Solution {
public:
    // Faster than map<pair<int,int>, int>
    vector<unordered_map<int, int>> memo;

    int pick_notpick(vector<int>& nums, int idx, int x, int target) {
        // BASE CASE: We reached the end of the array. 
        // Now we check if our final XOR sum matches the target.
        if (idx == nums.size()) {
            return (x == target) ? 0 : INT_MAX;
        }
        
        // Return memoized result if we've seen this exact state
        if (memo[idx].count(x)) return memo[idx][x];
        
        // OPTION 1: Leave (Remove) the element
        // XOR sum 'x' stays the same, cost increases by 1
        int leave = pick_notpick(nums, idx + 1, x, target);
        if (leave != INT_MAX) leave++;
        
        // OPTION 2: Take (Keep) the element
        // XOR sum updates to 'x ^ nums[idx]', no removal cost added
        int take = pick_notpick(nums, idx + 1, x ^ nums[idx], target);
        
        return memo[idx][x] = min(leave, take);
    }

    int minRemovals(vector<int>& nums, int target) {
        memo.resize(nums.size()); // Initialize memo table for N indices
        
        int y = pick_notpick(nums, 0, 0, target);
        
        if(y == INT_MAX) return -1;
        return y;
    }
};