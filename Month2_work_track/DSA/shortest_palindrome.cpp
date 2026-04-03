// # 214. Shortest Palindrome
// # Solved
// # Hard
// # Topics
// # premium lock icon
// # Companies
// # You are given a string s. You can convert s to a palindrome by adding characters in front of it.

// # Return the shortest palindrome you can find by performing this transformation.

 

// # Example 1:

// # Input: s = "aacecaaa"
// # Output: "aaacecaaa"
// # Example 2:

// # Input: s = "abcd"
// # Output: "dcbabcd"
 

// # Constraints:

// # 0 <= s.length <= 5 * 104
// # s consists of lowercase English letter
#include<iostream>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length()==0) return s;
        int n=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string ans=s+'#'+rev;
        vector<int>lcs(2*n+1,0);
        int i=1;
        int prelcs=0;
        while(i<2*n+1){
            if(ans[i]==ans[prelcs]){
                lcs[i]=prelcs+1;
                prelcs++;
                i++;
            }
            else if(prelcs==0){
                lcs[i]=0;
                i++;
            }
            else{
                prelcs=lcs[prelcs-1];
            }
        }
        string final_ans="";
        for(int i=n-1;i>=lcs[2*n];i--){
            final_ans+=s[i];
        }
        final_ans+=s;
        return final_ans;
        
    }
};


