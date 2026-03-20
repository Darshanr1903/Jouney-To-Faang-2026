// 416. Partition Equal Subset Sum
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
#include<iostream>
using namespace std;
class Solution {
public:
int sum;
bool helper(vector<int>& nums,int idx,int sum){
    if(idx==0) return sum==nums[idx];
    bool leave=helper(nums,idx-1,sum);
    bool take=helper(nums,idx+1,sum-nums[idx]);
    return take||leave;
}
    bool canPartition(vector<int>& nums) {
        sum=0;
        for(auto ele:nums) sum+=ele;
        if(sum%2!=0) return false;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum/2+1,0));
        if(nums[0]<=sum/2) dp[0][nums[0]]=1;
        else return false;
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum/2;target++){
                if(nums[i]>sum/2) return false;
                bool leave=dp[i-1][target];
                bool take=false;
                if(nums[i]<=target) take=dp[i-1][target-nums[i]];
                dp[i][target]=take||leave;
            }
        }

        return dp[n-1][sum/2];
    }
};