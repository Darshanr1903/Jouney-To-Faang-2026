// 923. 3Sum With Multiplicity

// Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

// As the answer can be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
// Output: 20
// Explanation: 
// Enumerating by the values (arr[i], arr[j], arr[k]):
// (1, 2, 5) occurs 8 times;
// (1, 3, 4) occurs 8 times;
// (2, 2, 4) occurs 2 times;
// (2, 3, 3) occurs 2 times.
// Example 2:

// Input: arr = [1,1,2,2,2,2], target = 5
// Output: 12
// Explanation: 
// arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
// We choose one 1 from [1,1] in 2 ways,
// and two 2s from [2,2,2,2] in 6 ways.
// Example 3:

// Input: arr = [2,1,3], target = 6
// Output: 1
// Explanation: (1, 2, 3) occured one time in the array so we return 1.
 

// Constraints:

// 3 <= arr.length <= 3000
// 0 <= arr[i] <= 100
// 0 <= target <= 300
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int M = 1e9 + 7;
        unordered_map<int, int> mp;
        for (auto ele : nums) {
            mp[ele]++;
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    if (nums[i] != nums[j] && nums[j] != nums[k]) {
                        // Cast to long long to prevent overflow during multiplication
                        count = (count + (1LL * mp[nums[i]] * mp[nums[j]] * mp[nums[k]])) % M;
                    }
                    else if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        long long n = mp[nums[i]]; // Changed n to long long locally
                        count = (count + (n * (n - 1) * (n - 2) / 6)) % M;
                    }
                    else {
                        if (nums[i] == nums[j]) {
                            long long n = mp[nums[i]]; // Changed n to long long locally
                            long long res = (n * (n - 1)) / 2;
                            count = (count + (res * mp[nums[k]])) % M;
                        }
                        else {
                            long long n = mp[nums[j]]; // Changed n to long long locally
                            long long res = (n * (n - 1)) / 2;
                            count = (count + (res * mp[nums[i]])) % M;
                        }
                    }
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if (sum > target) {
                    k--;
                }
                else j++;
            }
        }
        return count % M;
    }
};
