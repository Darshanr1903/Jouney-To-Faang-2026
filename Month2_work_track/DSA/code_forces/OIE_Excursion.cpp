#include <iostream>
#include <vector>
#include <set> // Changed from unordered_set

using namespace std;

int main(){
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if(cin >> t) {
        while(t--){
            int n, m;
            cin >> n >> m;
            
            vector<int> v(n);
            for(int i = 0; i < n; i++){
               cin >> v[i];
            }
            
            // Use std::set with greater<int> to keep elements sorted descendingly
            set<int, greater<int>> s; 
            s.insert(1);
            
            int i = 0;
            int j = 0;
            
            while(j < n){
                if(v[j] == v[i]){
                    j++;
                }
                else{
                    s.insert(j - i); // Insert the length of the chunk
                    i = j;           // Start new chunk
                    j++;
                }
            }
            
            // CRITICAL: Insert the length of the final chunk!
            s.insert(j - i);
            
            // Now *s.begin() safely grabs the absolute maximum element
            int grater = *s.begin();
            
            if(grater >= m) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}