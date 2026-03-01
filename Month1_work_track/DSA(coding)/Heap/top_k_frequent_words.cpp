// 692. Top K Frequent Words
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

// Example 1:

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:

// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

// Constraints:

// 1 <= words.length <= 500
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// k is in the range [1, The number of unique words[i]]
 

// Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
#include<iostream>
#include<unordered_map>
using namespace std;
bool cmp(pair<int,string>&p1,pair<int,string>&p2){
    if(p1.first!=p2.first) return p1.first>p2.first;
    return p1.second<=p2.second;
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>>ans;
        unordered_map<string,int>mp;
        for(auto word:words){
            mp[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> minHeap;
        for(auto ele:mp){
            minHeap.push({ele.second,ele.first});
            // if(minHeap.size()>k) minHeap.pop();
        }
        while(minHeap.size()){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<string>v;
        for(auto ele:ans){
            if(v.size()<k) v.push_back(ele.second);
            else break;
        }
        return v;
    }
};