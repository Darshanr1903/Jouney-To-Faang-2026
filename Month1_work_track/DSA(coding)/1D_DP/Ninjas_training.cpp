
// Geek's Training
// Difficulty: MediumAccuracy: 49.98%Submissions: 148K+Points: 4Average Time: 20m
// Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D matrix mat[][], where mat[i][0], mat[i][1], and mat[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

// Example:

// Input: mat[][]= [[1, 2, 5],
//                [3, 1, 1], 
//                [3, 3, 3]]
// Output: 11
// Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.
// Input: mat[][]= [[1, 1, 1],
//                [2, 2, 2],
//                [3, 3, 3]]
// Output: 6
// Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.
// Input: mat[][]= [[4, 2, 6]]
// Output: 6
// Explanation: Geek will learn a new move to make his merit points as 6.
// Constraint:
// 1 ≤ n ≤ 105   
// 1 ≤  arr[i][j] ≤ 100
#include<iostream>
using namespace std;
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        // prev stores results of the previous day
        vector<int> prev(3);

        // Initialize with Day 0
        prev[0] = mat[0][0];
        prev[1] = mat[0][1];
        prev[2] = mat[0][2];

        for (int day = 1; day < n; day++) {
            vector<int> curr(3);
            for (int task = 0; task < 3; task++) {
                int max_prev = 0;
                for (int prev_task = 0; prev_task < 3; prev_task++) {
                    if (prev_task != task) {
                        max_prev = max(max_prev, prev[prev_task]);
                    }
                }
                curr[task] = mat[day][task] + max_prev;
            }
            // Move to the next day
            prev = curr;
        }

        return max({prev[0], prev[1], prev[2]});
    }
};

