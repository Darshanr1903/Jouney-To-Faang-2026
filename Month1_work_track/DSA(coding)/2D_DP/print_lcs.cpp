//  Print Longest Common Subsequence
// Hard
// 120/120
// Contributed by
// 230 upvotes
// Asked in company
// Problem statement
// You are given two strings ‘s1’ and ‘s2’.



// Return the longest common subsequence of these strings.



// If there’s no such string, return an empty string. If there are multiple possible answers, return any such string.



// Note:
// Longest common subsequence of string ‘s1’ and ‘s2’ is the longest subsequence of ‘s1’ that is also a subsequence of ‘s2’. A ‘subsequence’ of ‘s1’ is a string that can be formed by deleting one or more (possibly zero) characters from ‘s1’.


// Example:
// Input: ‘s1’  = “abcab”, ‘s2’ = “cbab”

// Output: “bab”

// Explanation:
// “bab” is one valid longest subsequence present in both strings ‘s1’ , ‘s2’.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5 6
// ababa
// cbbcad


// Expected Answer:
// "bba"


// Output on console:
// 1


// Explanation of sample output 1:
// “bba” is only possible longest subsequence present in both s1 = “ababa” and s2 = “cbbcad”. '1' is printed if the returned string is equal to "bba". 


// Sample Input 2:
// 3 3
// xyz
// abc


// Expected Answer:
// ""


// Output on console:
// 1


// Explanation of sample output 2:
// There’s no subsequence of ‘s1’ that is also present in ‘s2’. Thus an empty string is returned and '1' is printed.


// Expected Time Complexity:
// Try to solve this in O(n*m). Where ‘n’ is the length of ‘s1’ and ‘m’ is the length of ‘s2’. 


// Constraints:
// 1 <= n, m <= 10^3

// Time Limit: 1 sec
#include<iostream>
using namespace std;
vector<vector<string>>dp;
string helper(string &s1, string &s2,int i,int j){
	if(i>=s1.length()||j>=s2.length()) return "";
	if(dp[i][j]!="-1") return dp[i][j];
	if(s1[i]==s2[j]){
		return dp[i][j]=s1[i]+helper(s1,s2,i+1,j+1);
	}
	else{
		string x=helper(s1,s2,i+1,j);
		string y=helper(s1,s2,i,j+1);
		if(x.length()>=y.length()) return dp[i][j]=x;
		return dp[i][j]=y;
	}
}
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	dp.resize(n,vector<string>(m,"-1"));	
	return helper(s1,s2,0,0);
}