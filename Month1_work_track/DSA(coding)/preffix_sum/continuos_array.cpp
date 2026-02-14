// 525. Contiguous Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// Example 3:

// Input: nums = [0,1,1,1,1,1,0,0,0]
// Output: 6
// Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int diff=0;
        unordered_map<int,int>mp;
        mp[diff]=-1;
        int len=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) diff--;
            else diff++;
            if(mp.find(diff)!=mp.end()) len=max(len,i-mp[diff]);
            else{
                mp[diff]=i;
            }
        }
        return len;
    }
};
