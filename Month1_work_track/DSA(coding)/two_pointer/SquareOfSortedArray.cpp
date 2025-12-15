// 977. Squares of a Sorted Array
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.
 

// Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int idx=0;
        vector<int>ans;
        while(idx<nums.size()&&nums[idx]<0){
            idx++;
        }
        int i=idx-1;
        int j=idx;
        while(i>=0||j<nums.size()){
            if(i>=0&&j<nums.size()){
                int x=nums[i]*nums[i];
                int y=nums[j]*nums[j];
                if(x<=y){
                    ans.push_back(x);
                    i--;
                }
                else{
                    ans.push_back(y);
                    j++;
                }
            }
            else if(i>=0){
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else{
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        return ans;
    }
};