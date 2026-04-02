// 468. Validate IP Address
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.

// A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.

// A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

// 1 <= xi.length <= 4
// xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
// Leading zeros are allowed in xi.
// For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

 

// Example 1:

// Input: queryIP = "172.16.254.1"
// Output: "IPv4"
// Explanation: This is a valid IPv4 address, return "IPv4".
// Example 2:

// Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
// Output: "IPv6"
// Explanation: This is a valid IPv6 address, return "IPv6".
// Example 3:

// Input: queryIP = "256.256.256.256"
// Output: "Neither"
// Explanation: This is neither a IPv4 address nor a IPv6 address.
 

// Constraints:

// queryIP consists only of English letters, digits and the characters '.' and ':'.
#include<iostream>
using namespace std;
class Solution {
public:
    string validIPAddress(string queryIP) {
        if(queryIP.length()<7||queryIP.length()>=40) return "Neither";
        if(queryIP=="0.0.0.0") return "IPv4";
        int i=0;
        bool ip4=true;
        bool ip6=true;
        int count_4=0;
        int count_6=0;
        while(i<queryIP.length()){
            if(queryIP[i]=='.'||queryIP[i]==':') return "Neither";
            string id="";
            while(i<queryIP.length()&&(queryIP[i]!='.'&&queryIP[i]!=':')){
                id+=queryIP[i];
                i++;
            }
            if(i<queryIP.length()&&queryIP[i]=='.') count_4++;
            if(i<queryIP.length()&&queryIP[i]==':') count_6++;
            if(i<queryIP.length()&&queryIP[i]=='.'){
                //cant be ip6 so check for ip4;
                if(id.length()==0||id.length()>3) return "Neither"; 
                if(id[0]=='0'&&id.length()!=1) return "Neither";
                ip6=false;
                for(int j=0;j<id.length();j++){
                     if(isdigit(id[j])){
                        continue;
                     }
                     else{
                        return "Neither";
                     }
                }
                if(stoi(id)>255) return "Neither";
            }
            else if(i<queryIP.length()&&queryIP[i]==':'){
                if(id.length()==0||id.length()>4) return "Neither";
                ip4=false;
                for(int j=0;j<id.length();j++){
                    if(isdigit(id[j])||(id[j]>=65&&id[j]<=70)||(id[j]>=97&&id[j]<=102)) continue;
                    else return "Neither";
                }
            }
            else{
                if(ip4){
                   if(id.length()==0||id.length()>3) return "Neither";
                   if(id[0]=='0') return "Neither";
                    ip6=false;
                    for(int j=0;j<id.length();j++){
                        if(isdigit(id[j])){
                            continue;
                        }
                        else{
                            return "Neither";
                        }
                    }
                    if(stoi(id)>255) return "Neither";
                }
                else if(ip6){
                    if(id.length()==0||id.length()>4) return "Neither";
                    ip4=false;
                    for(int j=0;j<id.length();j++){
                        if(isdigit(id[j])||(id[j]>=65&&id[j]<=70)||(id[j]>=97&&id[j]<=102)) continue;
                        else return "Neither";
                    }
                }
                else return "Neither";
            }
            if(i<queryIP.length()&&(queryIP[i]=='.'||queryIP[i]==':')){
                if(i+1==queryIP.length()) return "Neither";
            }
            i++;
        }
        if(ip4){
            if(queryIP.length()>17||(count_4!=3)) return "Neither";
            return "IPv4";
        }
        else if(ip6){
            if(queryIP.length()<15||count_6!=7) return "Neither";
            return "IPv6";
        }
        else return "Neither";
  

        
    }
};