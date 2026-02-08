// 76. Minimum Window Substring
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<t.length();i++){
            mp[t[i]]++;

        }
        int min_len=INT_MAX;
        int start_idx=-1;
        int count=0,i=0,j=0;
        while(j<s.length()){
            if(mp[s[j]]>0) count++;
            mp[s[j]]--;
            while(count==t.length()){
                if(j-i+1<min_len){
                    min_len=j-i+1;
                    start_idx=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) count--;
                i++;
            }
            j++;
        }
        return (start_idx==-1)?"":s.substr(start_idx,min_len);
    }
};
