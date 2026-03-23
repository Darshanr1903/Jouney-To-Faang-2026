// 260. Single Number III
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]
 

// Constraints:

// 2 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each integer in nums will appear twice, only two integers will appear once.
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()<=2) return nums;
        int x=0;
        for(int i=0;i<nums.size();i++){
            x=x^nums[i];
        }
        int bit_index=0;
        while(x){
            if(x%2!=0) break;
            x=x>>1;
            bit_index++;
        }
        int bucket_1=0;
        int bucket_2=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&(1<<bit_index))) bucket_1^=nums[i];
            else bucket_2^=nums[i];
        }
        return {bucket_1,bucket_2};
    }
};