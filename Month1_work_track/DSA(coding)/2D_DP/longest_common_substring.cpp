
// Longest Common Substring
// Difficulty: MediumAccuracy: 42.69%Submissions: 325K+Points: 4
// You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

// Examples:

// Input: s1 = "ABCDGH", s2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring is "CDGH" with a length of 4.
// Input: s1 = "abc", s2 = "acb"
// Output: 1
// Explanation: The longest common substrings are "a", "b", "c" all having length 1.
// Input: s1 = "YZ", s2 = "yz"
// Output: 0
// Constraints:
// 1 <= s1.size(), s2.size() <= 103
// Both strings may contain upper and lower case alphabets.
#include<iostream>
using namespace std;
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int max_length=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    max_length=max(max_length,dp[i][j]);
                }
            }
        }
        return max_length;
        
    }
};