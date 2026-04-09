// 845. Longest Mountain in Array
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You may recall that an array arr is a mountain array if and only if:

// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

 

// Example 1:

// Input: arr = [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
// Example 2:

// Input: arr = [2,2,2]
// Output: 0
// Explanation: There is no mountain.
 

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 104
 

// Follow up:

// Can you solve it using only one pass?
// Can you solve it in O(1) space?
#include<iostream>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3) return 0;
        int n=arr.size();
        vector<int>preffix(n,1);
        vector<int>suffix(n,1);
        int max_length=0;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1]) preffix[i]+=preffix[i-1];
            
            if(arr[n-1-i]>arr[n-i]) suffix[n-1-i]+=suffix[n-i];
        }
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]) max_length=max(max_length,preffix[i]+suffix[i]);
        }
        return max_length-1>1?max_length-1:0;
        
    }
};