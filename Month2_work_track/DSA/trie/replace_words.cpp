// 648. Replace Words
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

// Return the sentence after the replacement.

 

// Example 1:

// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Example 2:

// Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// Output: "a a b c"
 

// Constraints:

// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 100
// dictionary[i] consists of only lower-case letters.
// 1 <= sentence.length <= 106
// sentence consists of only lower-case letters and spaces.
// The number of words in sentence is in the range [1, 1000]
// The length of each word in sentence is in the range [1, 1000]
// Every two consecutive words in sentence will be separated by exactly one space.
// sentence does not have leading or trailing spaces.
#include<iostream>
using namespace std;
class Node {
public:
    unordered_map<char, Node*> mp;
    bool terminated;
    Node() { terminated = false; }
    bool isKey(char ch) { return mp.count(ch); }
    void insert(char ch) { mp[ch] = new Node(); }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        Node* root=new Node();
        for (auto word : dictionary) {
            Node* node = root;
            for (auto ch : word) {
                if (!node->isKey(ch)) {
                    node->insert(ch);
                }
                node = node->mp[ch];
            }
            node->terminated = true;
        }
        int i = 0;
        string ans = "";
        while (i < s.length()) {
            if (s[i] < 97 || s[i] > 122) {
                ans += " ";
                i++;
            }
            string word = "";
            Node* node = root;
            
            while (i < s.length() && s[i] >= 97 &&
                                     s[i] <= 122) {
                if (node->isKey(s[i])) {
                    word += s[i];
                    node=node->mp[s[i]];
                    if(node->terminated){
                        while (i < s.length() && s[i] >= 97 && s[i] <= 122) i++;
                    }
                    else i++;

                } else {
                    while (i < s.length() && s[i] >= 97 && s[i] <= 122) {
                        word += s[i];
                        i++;
                    }
                }
            }
            ans+=word;
        }
        return ans;
    }
};