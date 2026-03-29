// 0 - 1 Knapsack Problem
// Difficulty: MediumAccuracy: 31.76%Submissions: 568K+Points: 4
// Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, and an integer W representing the maximum capacity of the knapsack (the total weight it can hold).

// The task is to put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.

// Note: You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.

// Examples :

// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
// Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).
// Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
// Output: 80
// Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
// Constraints:
// 1 ≤ val.size() = wt.size() ≤ 103
// 1 ≤ W ≤ 103
// 1 ≤ val[i] ≤ 103
// 1 ≤ wt[i] ≤ 103

#include<iostream>
using namespace std;
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<int>prev(W+1,0);
        for(int j=0;j<=W;j++){
            if(j>=wt[n-1]) prev[j]=val[n-1];
        }
        
        for(int i=n-2;i>=0;i--){
            vector<int>curr(W+1,0);
            for(int j=0;j<=W;j++){
                int leave=prev[j];
                int take=0;
                if(j-wt[i]>=0) take=val[i]+prev[j-wt[i]];
                curr[j]=max(take,leave);
            }
            prev=curr;
        }
        return prev[W];
    }
};