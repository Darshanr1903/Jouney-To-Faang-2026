// 3900. Longest Balanced Substring After One Swap
// Solved
// Medium
// premium lock icon
// Companies
// Hint
// You are given a binary string s consisting only of characters '0' and '1'.

// A string is balanced if it contains an equal number of '0's and '1's.

// You can perform at most one swap between any two characters in s. Then, you select a balanced substring from s.

// Return an integer representing the maximum length of the balanced substring you can select.

 

// Example 1:

// Input: s = "100001"

// Output: 4

// Explanation:

// Swap "100001". The string becomes "101000".
// Select the substring "101000", which is balanced because it has two '0's and two '1's.
// Example 2:

// Input: s = "111"

// Output: 0

// Explanation:

// Choose not to perform any swaps.
// Select the empty substring, which is balanced because it has zero '0's and zero '1's.
 

// Constraints:

// 1 <= s.length <= 105
// s consists only of the characters '0' and '1'.
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestBalanced(string s) {
        int total_1 = 0;
        int total_0 = 0;
        int max_length = 0;
        for (auto ele : s) {
            if (ele == '1')
                total_1++;
            else
                total_0++;
        }
        int sum = 0;
        unordered_map<int, vector<int>> mp;
        mp[sum].push_back(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                sum += 1;
            else
                sum -= 1;
            if (mp[sum].size()) {
                max_length = max(max_length, i - mp[sum][0]);
            }
            int target_1 = sum - 2;
            if (mp[target_1].size()) {
                for (int j : mp[target_1]) {
                    int len = i - j;
                    int zeros = len / 2 - 1;
                    if (total_0 > zeros) {
                        max_length = max(max_length, len);
                        break;
                    }
                }
            }
            int target_0 = sum + 2;
            if (mp[target_0].size()) {
                for (int j : mp[target_0]) {
                    int len = i - j;
                    int ones = len / 2 - 1;
                    if (total_1 > ones) {
                        max_length = max(max_length, len);
                        break;
                    }
                }
            }
            mp[sum].push_back(i);
        }
         return max_length;
    }
};