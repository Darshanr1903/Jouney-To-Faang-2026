// 1312. Minimum Insertion Steps to Make a String Palindrome
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

 

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.
// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.
#include<iostream>
using namespace std;
class Solution {
public:
vector<vector<int>>dp;
int helper(string& s,int i,int j){
    if(i>j) return 0;
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]){
        return dp[i][j]=helper(s,i+1,j-1);
    }
    else{
        int replace_front=1+helper(s,i,j-1);
        int replace_back=1+helper(s,i+1,j);
        return dp[i][j]=min(replace_front,replace_back);
    }
}
    int minInsertions(string s) {
        int n=s.length();
        dp.resize(n,vector<int>(n,-1));
        return helper(s,0,n-1);
    }
};