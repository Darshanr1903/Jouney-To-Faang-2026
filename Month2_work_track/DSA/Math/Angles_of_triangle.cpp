// 3899. Angles of a Triangle
// Solved
// Medium
// premium lock icon
// Companies
// Hint
// You are given a positive integer array sides of length 3.

// Determine if there exists a triangle with positive area whose three side lengths are given by the elements of sides.

// If such a triangle exists, return an array of three floating-point numbers representing its internal angles (in degrees), sorted in non-decreasing order. Otherwise, return an empty array.

// Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: sides = [3,4,5]

// Output: [36.86990,53.13010,90.00000]

// Explanation:

// You can form a right-angled triangle with side lengths 3, 4, and 5. The internal angles of this triangle are approximately 36.869897646, 53.130102354, and 90 degrees respectively.

// Example 2:

// Input: sides = [2,4,2]

// Output: []

// Explanation:

// You cannot form a triangle with positive area using side lengths 2, 4, and 2.

 

// Constraints:

// sides.length == 3
// 1 <= sides[i] <= 1000
#include<iostream>
using namespace std;
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double>ans;
        int a=sides[0];
        int b=sides[1];
        int c=sides[2];
        if(sides[0]<=0||sides[1]<=0||sides[2]<=0) return ans;
        if(a+b<=c||a+c<=b||b+c<=a) return ans;
        double A=acos((b*b+c*c-a*a)/(2.0*b*c));
        A*=(180/acos(-1.0));
        ans.push_back(A);
        double B=acos((a*a+c*c-b*b)/(2.0*a*c));
        B*=(180/acos(-1.0));
        ans.push_back(B);
        double C=acos((b*b+a*a-c*c)/(2.0*b*a));
        C*=(180/acos(-1.0));
        ans.push_back(C);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};