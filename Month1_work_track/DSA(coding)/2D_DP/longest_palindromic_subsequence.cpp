// 516. Longest Palindromic Subsequence
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.
#include<iostream>
using namespace std;
class Solution {
public:
vector<vector<int>>dp;
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<int>prev(n,0);
        for(int i=n-1;i>=0;i--){
            vector<int>curr(n,0);
           for(int j=0;j<n;j++){
            if(i>j) curr[j]=0;
            else if(i==j) curr[j]=1;
            else{
                if(s[i]==s[j]){
                    curr[j]=2+prev[j-1];
                }
                else{
                    int move_left=prev[j];
                    int move_right=curr[j-1];
                    curr[j]=max(move_left,move_right);
                }
            }
           }
           prev=curr;
        }
        return prev[n-1];
    }
};