// 535. Encode and Decode TinyURL
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Note: This is a companion problem to the System Design problem: Design TinyURL.
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

// There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

// Implement the Solution class:

// Solution() Initializes the object of the system.
// String encode(String longUrl) Returns a tiny URL for the given longUrl.
// String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was encoded by the same object.
 

// Example 1:

// Input: url = "https://leetcode.com/problems/design-tinyurl"
// Output: "https://leetcode.com/problems/design-tinyurl"

// Explanation:
// Solution obj = new Solution();
// string tiny = obj.encode(url); // returns the encoded tiny url.
// string ans = obj.decode(tiny); // returns the original url after decoding it.
 

// Constraints:

// 1 <= url.length <= 104
// url is guranteed to be a valid URL.
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int count=0;
    unordered_map<int,string>mp;
    string base62_alphabet="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        count++;
        int num=count;
        mp[num]=longUrl;
        string ans="";
        while(num){
            ans+=base62_alphabet[num%62];
            num=num/62;

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int num=0;
        for(char ch:shortUrl){
            num=num*62+base62_alphabet.find(ch);
        }
        string ans=mp[num];
        mp.clear();
        return ans;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));