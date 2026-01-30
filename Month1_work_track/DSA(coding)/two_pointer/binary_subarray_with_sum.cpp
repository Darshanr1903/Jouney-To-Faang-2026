// 930. Binary Subarrays With Sum
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// nums[i] is either 0 or 1.
// 0 <= goal <= nums.length
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0,i=0,j=0;
        int count=0;
        int idx1=-1;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>goal){
                count+=j-max(idx1,i);
                sum-=nums[i];
                i++;
            }
            if(nums[j]==1) idx1=j;
            j++;
        }
        while(sum>=goal&&i<nums.size()){
            count+=j-max(idx1,i);
            sum-=nums[i];
            i++;
        }
        return count;

    }
};
