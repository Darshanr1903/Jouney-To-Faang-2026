// 539. Minimum Time Difference
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

// Example 1:

// Input: timePoints = ["23:59","00:00"]
// Output: 1
// Example 2:

// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0
 

// Constraints:

// 2 <= timePoints.length <= 2 * 104
// timePoints[i] is in the format "HH:MM".
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes;
        
        // 1. Convert all times to minutes
        for (const string& t : timePoints) {
            int h = stoi(t.substr(0, 2));
            int m = stoi(t.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }
        
        // 2. Sort the times
        sort(minutes.begin(), minutes.end());
        
        // 3. Find minimum difference between adjacent times
        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i-1]);
        }
        
        // 4. Handle the circular case (last element to first element)
        // 1440 is the total minutes in a day
        int circularDiff = (1440 - minutes.back() + minutes[0]);
        minDiff = min(minDiff, circularDiff);
        
        return minDiff;
    }
};
