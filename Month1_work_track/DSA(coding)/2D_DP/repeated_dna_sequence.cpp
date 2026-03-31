// 187. Repeated DNA Sequences
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

// For example, "ACGAATTCCG" is a DNA sequence.
// When studying DNA, it is useful to identify repeated sequences within the DNA.

// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

// Example 1:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC","CCCCCAAAAA"]
// Example 2:

// Input: s = "AAAAAAAAAAAAA"
// Output: ["AAAAAAAAAA"]
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is either 'A', 'C', 'G', or 'T'.
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>v;
        if(s.length()<=10) return v;
        //int i=0;
        int j=0,i=0;
        long long ans=0;
        unordered_map<char,int>mp;
        mp['A']=0;
        mp['C']=1;
        mp['G']=2;
        mp['T']=3;
        unordered_map<int,int>st;
        int power=pow(4,9);
        for(j=0;j<10;j++){
            ans*=4;
            ans+=mp[s[j]];

        }
        st[ans]=1;
        while(j<s.length()){
            ans-=(mp[s[i]]*power);
            ans*=4;
            i++;
            ans+=mp[s[j]];
            if(st.find(ans)!=st.end()&&st[ans]==1){
                v.push_back(s.substr(i,10));
            }
            st[ans]+=1;
            j++;
        }
        return v;

    }
};