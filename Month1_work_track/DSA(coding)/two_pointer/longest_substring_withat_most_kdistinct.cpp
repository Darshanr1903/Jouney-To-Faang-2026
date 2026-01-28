// You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

// Note : If no such substring exists, return -1. 

// Examples:

// Input: s = "aabacbebebe", k = 3
// Output: 7
// Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
// Input: s = "aaaa", k = 2
// Output: -1
// Explanation: There's no substring with 2 distinct characters.
// Input: s = "aabaaab", k = 2
// Output: 7
// Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
// Constraints:
// 1 ≤ s.size() ≤ 105
// 1 ≤ k ≤ 26
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int max_len=0;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k) max_len=max(max_len,j-i+1);
            j++;
        }
        return max_len==0?-1:max_len;
    }
};