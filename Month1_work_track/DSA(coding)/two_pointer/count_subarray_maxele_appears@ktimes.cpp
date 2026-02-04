// 2962. Count Subarrays Where Max Element Appears at Least K Times
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array nums and a positive integer k.

// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

// A subarray is a contiguous sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,3,2,3,3], k = 2
// Output: 6
// Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
// Example 2:

// Input: nums = [1,4,2,1], k = 3
// Output: 0
// Explanation: No subarray contains the element 4 at least 3 times.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= k <= 105
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
long long count_sub(vector<int>& nums,int max1, int k){
    long long count=0;
    int i=0,j=0;
    long long max_count=0;
    while(j<nums.size()){
        if(nums[j]==max1) max_count++;
        while(max_count>k){
            if(nums[i]==max1) max_count--;
            i++;
        }
        count+=(j-i+1);
        j++;
    }
    return count;
}
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long total_subarray=((long long) n*(n+1))/2;
        int max1=INT_MIN;
        for(auto ele:nums){
            max1=max(max1,ele);
        }
        long long count=count_sub(nums,max1,k-1);
        return total_subarray-count;
    }
};
