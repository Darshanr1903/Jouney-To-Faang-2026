#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int count = 0;
    stack<int> st;

    for(int i = 0; i < n; i++) {
        // Keep popping until we find v[i] - 1 or the stack is empty
        while(!st.empty() && st.top() != v[i] - 1) {
            st.pop();
        }

        // If the stack is empty, this element MUST start a new sequence
        if(st.empty()) {
            count++;
            st.push(v[i]);
        } 
        // If we found the parent (st.top() == v[i] - 1)
        else {
            // Push the child to make it the new active top
            st.push(v[i]);
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O for large test cases
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}