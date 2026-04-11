#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), a(n);
    vector<int> pos(n + 1);

    for(int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i; // Save original index
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool possible = true;
    
    // Check if the mapped origins are strictly non-decreasing
    for(int i = 0; i < n - 1; i++) {
        if(pos[a[i]] > pos[a[i+1]]) {
            possible = false;
            break;
        }
    }

    if(possible) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}