// Minimum number of deletions and insertions
// Difficulty: MediumAccuracy: 65.29%Submissions: 79K+Points: 4
// Given two strings s1 and s2. The task is to remove or insert the minimum number of characters from/in s1 to transform it into s2. It could be possible that the same character needs to be removed from one point of s1 and inserted into another point.

// Examples :

// Input: s1 = "heap", s2 = "pea"
// Output: 3
// Explanation: 'p' and 'h' deleted from heap. Then, 'p' is inserted at the beginning.
// Input : s1 = "geeksforgeeks", s2 = "geeks"
// Output: 8
// Explanation: 8 deletions, i.e. remove all characters of the string "forgeeks".
// Constraints:
// 1 ≤ s1.size(), s2.size() ≤ 1000
// All the characters are lowercase English alphabets.

#include<iostream>
using namespace std;
class Solution {

  public:
  vector<vector<int>>dp;
  int helper(string &s1, string &s2,int i,int j){
      if(i>=s1.length()&&j>=s2.length()) return 0;
      if(i>=s1.length()||j>=s2.length()){
          if(i>=s1.length()) return s2.length()-j;
          else return s1.length()-i;
          
      }
      if(dp[i][j]!=-1) return dp[i][j];
      if(s1[i]==s2[j]) return dp[i][j]=helper(s1,s2,i+1,j+1);
      else{
          int del=1+helper(s1,s2,i+1,j);
          int insert=1+helper(s1,s2,i,j+1);
          return dp[i][j]=min(del,insert);
      }
  }
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        dp.resize(s1.length(),vector<int>(s2.length(),-1));
        return helper(s1,s2,0,0);
    }
};