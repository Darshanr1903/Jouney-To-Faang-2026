// 239. Sliding Window Maximum
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int max1=INT_MIN;
        for(int i=0;i<k;i++){
            max1=max(max1,nums[i]);
            while(!dq.empty()&&dq.back()<nums[i]){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        int j=k;
        int i=0;
        vector<int>ans;
        ans.push_back(max1);
        while(j<nums.size()){
            if(nums[i]==dq.front()){
                dq.pop_front();
                if(dq.size()) max1=dq.front();
                else max1=INT_MIN;
            }
            i++;
            max1=max(max1,nums[j]);
            while(!dq.empty()&&dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            ans.push_back(max1);
            j++;

        }
        return ans;
    }
};
