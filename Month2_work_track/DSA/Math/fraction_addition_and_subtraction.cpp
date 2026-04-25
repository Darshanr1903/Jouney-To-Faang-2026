// 592. Fraction Addition and Subtraction
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

// The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

 

// Example 1:

// Input: expression = "-1/2+1/2"
// Output: "0/1"
// Example 2:

// Input: expression = "-1/2+1/2+1/3"
// Output: "1/3"
// Example 3:

// Input: expression = "1/3-1/2"
// Output: "-1/6"
 

// Constraints:

// The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
// Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
// The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
// The number of given fractions will be in the range [1, 10].
// The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
#include<iostream>
using namespace std;
class Solution {
public:
    string fractionAddition(string s) {
        int num1=1;
        int den1=1;
        int i=0;
        if(s[i]=='-'){
            num1=-1;
            i++;
        }
        string numerator="";
        while(i<s.length()&&isdigit(s[i])){
            numerator+=s[i];
            i++;
        }
        num1*=stoi(numerator);
        if(i<s.length()&&s[i]=='/') i++;
        string denominator="";
        while(i<s.length()&&isdigit(s[i])){
            denominator+=s[i];
            i++;
        }
        den1*=stoi(denominator);
        int sign=1;
        while(i<s.size()){
            if(s[i]=='+'||s[i]=='-'){
                if(s[i]=='-') sign=-1;
                else sign=1;
                i++;
            }
            string numerator1="";
            string denominator1="";
            while(i<s.length()&&isdigit(s[i])){
                numerator1+=s[i];
                i++;
            }
            if(i<s.length()&&s[i]=='/') i++;
            while(i<s.length()&&isdigit(s[i])){
                denominator1+=s[i];
                i++;
            }
            //solving
            num1=(num1*stoi(denominator1))+(sign*stoi(numerator1)*den1);
            den1=den1*stoi(denominator1);
            if(num1==0) den1=1;
            else{
                int num=9;
                while(num>1){
                    while(num1%num==0&&den1%num==0){
                        num1=num1/num;
                        den1=den1/num;
                    }
                    num--;
                }
            }
        }
        string ans="";
        ans+=to_string(num1)+"/"+to_string(den1);
        return ans;
    }
};