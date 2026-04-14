// 3892. Minimum Operations to Achieve At Least K Peaks
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given a ​​​​​​​circular integer array​​​​​​​ nums of length n.

// An index i is a peak if its value is strictly greater than its neighbors:

// The previous neighbor of i is nums[i - 1] if i > 0, otherwise nums[n - 1].
// The next neighbor of i is nums[i + 1] if i < n - 1, otherwise nums[0].
// You are allowed to perform the following operation any number of times:

// Choose any index i and increase nums[i] by 1.
// Return an integer denoting the minimum number of operations required to make the array contain at least k peaks. If it is impossible, return -1.

 

// Example 1:

// Input: nums = [2,1,2], k = 1

// Output: 1

// Explanation:

// To achieve at least k = 1 peak, we can increase nums[2] = 2 to 3.
// After this operation, nums[2] = 3 is strictly greater than its neighbors nums[0] = 2 and nums[1] = 1.
// Therefore, the minimum number of operations required is 1.
// Example 2:

// Input: nums = [4,5,3,6], k = 2

// Output: 0

// Explanation:

// The array already contains at least k = 2 peaks with zero operations.
// Index 1: nums[1] = 5 is strictly greater than its neighbors nums[0] = 4 and nums[2] = 3.
// Index 3: nums[3] = 6 is strictly greater than its neighbors nums[2] = 3 and nums[0] = 4.
// Therefore, the minimum number of operations required is 0.
// Example 3:

// Input: nums = [3,7,3], k = 2

// Output: -1

// Explanation:

// It is impossible to have at least k = 2 peaks in this array. Therefore, the answer is -1.

 

// Constraints:

// 2 <= n == nums.length <= 5000
// -105 <= nums[i] <= 105
// 0 <= k <= n​​​​​​​
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;

    int helper(vector<int>& nums, int idx, int k) {
        if (k == 0) return 0;
        if (idx >= nums.size() - 1) return 1e9; 
        
        if (dp[idx][k] != -1) return dp[idx][k];
        
        int operation = max(0, max(nums[idx-1], nums[idx+1]) + 1 - nums[idx]);
        int take=operation+helper(nums,idx+2,k-1);
        
        int leave = helper(nums, idx + 1, k);
        return dp[idx][k]= min(take, leave);
    }

    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n / 2) return -1;
        dp.assign(n+1,vector<int>(k+1,-1));
        
        vector<int>v1;
        vector<int>v2;
        v1.push_back(nums[n-1]);
        for (int ele:nums) {
            v1.push_back(ele);
            v2.push_back(ele);
        }
        v2.push_back(nums[0]);
        int x=helper(v1,1,k);
        dp.assign(n+1,vector<int>(k+1,-1));
        int y=helper(v2,1,k);
        
        return min(x,y);
    }
};
