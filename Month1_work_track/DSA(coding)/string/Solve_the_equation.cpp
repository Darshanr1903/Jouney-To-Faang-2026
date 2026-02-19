// 640. Solve the Equation
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.

// If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.

 

// Example 1:

// Input: equation = "x+5-3+x=6+x-2"
// Output: "x=2"
// Example 2:

// Input: equation = "x=x"
// Output: "Infinite solutions"
// Example 3:

// Input: equation = "2x=x"
// Output: "x=0"
 

// Constraints:

// 3 <= equation.length <= 1000
// equation has exactly one '='.
// equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
// The input is generated that if there is a single solution, it will be an integer.
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string solveEquation(string equation) {
        bool equal = false;
        int left_x = 0;
        int right_x = 0;
        int left_sum = 0;
        int right_sum = 0;
        int i = 0;
        int sign = 1;
        while (i < equation.length()) {
            if(equation[i]=='='){
                equal=true;
                sign=1;
                i++;
            }
            if (equation[i] == '+') {
                sign = 1;
                i++;
            }
            if (equation[i] == '-') {
                sign = -1;
                i++;
            }
            string digit = "";
            while (i < equation.length() && isdigit(equation[i])) {
                digit += equation[i];
                i++;
            }
            
            if (i < equation.length() && equation[i] == 'x') {
                if (!equal) {
                    if (digit.empty()) {
                        left_x = left_x + sign * 1;
                    } else {
                        left_x += sign * stoi(digit);
                    }
                } else {
                    if (digit.empty()) {
                        right_x = right_x + sign * 1;
                    } else {
                        right_x += sign * stoi(digit);
                    }
                }
            } else {
                if (!equal) {
                    if (digit.empty()) {
                        left_sum = left_sum + sign * 1;
                    } else {
                        left_sum += sign * stoi(digit);
                    }
                } else {
                    if (digit.empty()) {
                        right_sum = right_sum + sign * 1;
                    } else {
                        right_sum += sign * stoi(digit);
                    }
                }
            }
            if(equation[i]!='-'&&equation[i]!='+'&&equation[i]!='=') i++;
        }
        int remain_x=left_x-right_x;
        int remain_sum=right_sum-left_sum;
        if(remain_x==0&&remain_sum==0){
            return "Infinite solutions";
        }
        if(remain_sum==0){
            return "x=0";
        }
        if(remain_x==0) return "No solution";
        else{
            string ans="x=";
            int digit=remain_sum/remain_x;
            ans+=to_string(digit);
            return ans;
        }

        
    }
};