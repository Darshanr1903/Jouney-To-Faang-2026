// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

// Example 1:

// Input: nums = [8,2,4,7], limit = 4
// Output: 2 
// Explanation: All subarrays are: 
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4. 
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4. 
// Therefore, the size of the longest subarray is 2.
// Example 2:

// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4 
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
// Example 3:

// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= limit <= 109
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<int>max_heap;
        priority_queue<int,vector<int>,greater<int>>min_heap;
        int i=0,j=0,len=0;
        while(j<nums.size()){
            if(!min_heap.size()||nums[j]>=min_heap.top()) min_heap.push(nums[j]);
            else{
                while(min_heap.size()){
                    min_heap.pop();
                }
                min_heap.push(nums[j]);
            }
            if(!max_heap.size()||nums[j]<=max_heap.top()) max_heap.push(nums[j]);
            else{
                while(max_heap.size()){
                    max_heap.pop();
                }
                max_heap.push(nums[j]);
            }
            if(max_heap.top()-min_heap.top()<=limit){
                len=max(len,j-i+1);
            }
            else{
                while(i<j&&max_heap.top()-min_heap.top()>limit){
                    if(max_heap.size()&&max_heap.top()==nums[i]){
                      max_heap.pop();
                    }
                    else if(min_heap.size()&&min_heap.top()==nums[i]){
                      min_heap.pop();
                    }
                    i++;
                }
                
            }
            j++;
        }
        return len;
    }
};
