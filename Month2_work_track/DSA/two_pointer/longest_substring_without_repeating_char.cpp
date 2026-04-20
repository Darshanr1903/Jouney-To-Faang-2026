// 3. Longest Substring Without Repeating Characters
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.
#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>m;
        int length=0;
        int last_idx=0;
        for(int i=0;i<s.length();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=i;
                length=max(length,i-last_idx+1);
            }
            else{
                int k=last_idx;
                last_idx=m[s[i]]+1;
                for(int j=k;j<last_idx;j++){
                    m.erase(s[j]);
                }
                m[s[i]]=i;
            }
        }
        return length;
    }
};