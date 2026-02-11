// 1081. Smallest Subsequence of Distinct Characters
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

 

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.
#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>mp;
        unordered_set<char>set;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        stack<char>st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(set.find(s[i])!=set.end()) continue;
            if(st.empty()||st.top()<s[i]){
                st.push(s[i]);
                
            }
            else{
                while(!st.empty()&&st.top()>s[i]&&mp[st.top()]>i){
                    set.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
            set.insert(s[i]);
        }
        while(st.size()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};