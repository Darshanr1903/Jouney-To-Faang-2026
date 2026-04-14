// 93. Restore IP Addresses
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:

// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

// Constraints:

// 1 <= s.length <= 20
// s consists of digits only.
#include<iostream>
using namespace std;
class Solution {
public:
vector<string>v;
void helper(string& s,int idx,string ans,int count_dot){
    if(count_dot==3){
        if(s.length()-idx>3||s.length()==idx) return;
        string check=s.substr(idx);
        if(check[0]=='0'&&check.length()>1) return;
        if(stoi(check)>255) return;
        string dup=ans+check;
        v.push_back(dup);
        return;
    }
    string check="";
    for(int i=idx;i<idx+3&&i<s.length();i++){
        check+=s[i];
        if(stoi(check)>255) break;
        ans=ans+s[i]+'.';
        helper(s,i+1,ans,count_dot+1);
        ans.pop_back();
        if(i==idx&&s[i]=='0') break;
    }
}
    vector<string> restoreIpAddresses(string s) {
        string ans="";
        v.clear();
        helper(s,0,ans,0);
        return v;
    }
};