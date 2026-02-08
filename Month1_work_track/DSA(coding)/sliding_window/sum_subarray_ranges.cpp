// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0 
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
// Example 2:

// Input: nums = [1,3,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0
// [3], range = 3 - 3 = 0
// [3], range = 3 - 3 = 0
// [1,3], range = 3 - 1 = 2
// [3,3], range = 3 - 3 = 0
// [1,3,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
// Example 3:

// Input: nums = [4,-2,-3,4,1]
// Output: 59
// Explanation: The sum of all subarray ranges of nums is 59.
 

// Constraints:

// 1 <= nums.length <= 1000
// -109 <= nums[i] <= 109
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
long long sub_min(vector<int>& nums){
    int n=nums.size();
    vector<int>pse(n,-1);
    vector<int>nse(n,n);
    stack<int>st;
    long long min1=0;
    for(int i=0;i<n;i++){
        while(!st.empty()&&nums[st.top()]>=nums[i]) st.pop();
        if(!st.empty()) pse[i]=st.top();
        st.push(i);
    }
    while(st.size()){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&nums[st.top()]>nums[i]) st.pop();
        if(!st.empty()) nse[i]=st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++){
        int x=i-pse[i];
        int y=nse[i]-i;
        min1+=(1LL*x*y)*nums[i];
    }
    return min1;
}
long long sub_max(vector<int>& nums){
    int n=nums.size();
    vector<int>pge(n,-1);
    vector<int>nge(n,n);
    stack<int>st;
    long long max1=0;
    for(int i=0;i<n;i++){
        while(!st.empty()&&nums[st.top()]<=nums[i]) st.pop();
        if(!st.empty()) pge[i]=st.top();
        st.push(i);
    }
    while(st.size()){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&nums[st.top()]<nums[i]) st.pop();
        if(!st.empty()) nge[i]=st.top();
        st.push(i);
    }
    for(int i=0;i<n;i++){
        int x=i-pge[i];
        int y=nge[i]-i;
        max1+=(1LL*x*y)*nums[i];
    }
    return max1;
}
    long long subArrayRanges(vector<int>& nums) {
        return sub_max(nums)-sub_min(nums);
    }
};