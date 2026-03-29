// 321. Create Maximum Number
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.

// Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.

// Return an array of the k digits representing the answer.

 

// Example 1:

// Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
// Output: [9,8,6,5,3]
// Example 2:

// Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
// Output: [6,7,6,0,4]
// Example 3:

// Input: nums1 = [3,9], nums2 = [8,9], k = 3
// Output: [9,8,9]
 

// Constraints:

// m == nums1.length
// n == nums2.length
// 1 <= m, n <= 500
// 0 <= nums1[i], nums2[i] <= 9
// 1 <= k <= m + n
// nums1 and nums2 do not have leading zeros.
#include<iostream>
using namespace std;
class Solution {
public:
bool compare_vector(vector<int>&v1,int i,vector<int>&v2,int j){
    while(i<v1.size()||j<v2.size()){
        if(i>=v1.size()) return false;
        if(j>=v2.size()) return true;
        if(v1[i]>v2[j]) return true;
        if(v1[i]<v2[j]) return false;
        else{
            i++;
            j++;
        }
    
    }
    return true;
    
}
vector<int> max_subarray(vector<int>& num,int k){
    vector<int>st;
    int to_drop=num.size()-k;
    for(int i=0;i<num.size();i++){
        while(!st.empty()&&to_drop>0&&num[i]>st.back()){
            st.pop_back();
            to_drop--;
        }
        st.push_back(num[i]);
    }
    st.resize(k);
    return st;
}
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>best;
        for(int i=0;i<=k;i++){
            int j=k-i;
            if(i>nums1.size()||j>nums2.size()) continue;
            vector<int>max1=max_subarray(nums1,i);
            vector<int>max2=max_subarray(nums2,j);
            vector<int>merge;
            int a=0,b=0;
            while(a<max1.size()||b<max2.size()){
                if(a>=max1.size()){
                    merge.push_back(max2[b++]);
                }
                else if(b>=max2.size()){
                    merge.push_back(max1[a++]);
                }
                else if(max1[a]<max2[b]){
                    merge.push_back(max2[b++]);
                }
                else if(max1[a]>max2[b]){
                    merge.push_back(max1[a++]);
                }
                else{
                    if(compare_vector(max1,a,max2,b)){
                        merge.push_back(max1[a++]);
                    }
                    else{
                        merge.push_back(max2[b++]);
                    }
                }
            }
            if(merge>best){
                best=merge;
            }
        }
        return best;
    }
};