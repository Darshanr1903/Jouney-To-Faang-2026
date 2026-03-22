// 78. Subsets
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=1<<(nums.size());
        vector<vector<int>>ans;
        for(int num=0;num<n;num++){
            vector<int>v;
            for(int i=0;i<nums.size();i++){
                if(num&(1<<i)) v.push_back(nums[i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};