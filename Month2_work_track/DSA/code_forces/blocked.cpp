// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    // Fast I/O (Highly recommended for Codeforces)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        
        // Sorting in descending order using built-in reverse iterators
        sort(v.rbegin(), v.rend());
        
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(v[i] == v[i-1]){
                flag = false;
                break;
            }
        }
        
        if(!flag) {
            cout << -1 << "\n";
        } else {
            for(int i = 0; i < n; i++){
                cout << v[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}