// Maximize Number of 1's
// Difficulty: MediumAccuracy: 39.46%Submissions: 76K+Points: 4Average Time: 20m
// Given a binary array arr[] containing only 0s and 1s and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.

// Examples:

// Input: arr[] = [1, 0, 1], k = 1
// Output: 3
// Explanation: By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1’s.
// Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
// Output: 5
// Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.
// Input: arr[] = [1, 1], k = 2
// Output: 2
// Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ k ≤ arr.size()
// 0 ≤ arr[i] ≤ 1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int count1=0;
        int count0=0;
        int len=0;
        int i=0,j=0;
        while(j<arr.size()){
            if(arr[j]==1){
                count1++;
            }
            else count0++;
            if(j-i+1-count1>k){
                while(j-i+1-count1>k&&i<=j){
                    if(arr[i]==1) count1--;
                    else count0--;
                    i++;
                }
            }
            else{
                len=max(len,j-i+1);
            }
            j++;
        }
        return len;
    }
};