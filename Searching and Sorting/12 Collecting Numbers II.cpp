#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<int> pos(n), num(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pos[x - 1] = i;
        num[i] = x - 1;
    }
 
    int cnt = 1;
    for(int i = 0; i < n - 1; i++){
        if(pos[i] > pos[i + 1]) cnt++; 
    }
 
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        
        int valA = num[a];
        int valB = num[b];
 
        // Use a set to store unique pairs of (value, value+1) to avoid double counting
        set<pair<int, int>> pairs_to_check;
        if (valA > 0) pairs_to_check.insert({valA - 1, valA});
        if (valA < n - 1) pairs_to_check.insert({valA, valA + 1});
        if (valB > 0) pairs_to_check.insert({valB - 1, valB});
        if (valB < n - 1) pairs_to_check.insert({valB, valB + 1});
 
        // Subtract the contribution of these pairs BEFORE the swap
        for (auto p : pairs_to_check) {
            if (pos[p.first] > pos[p.second]) {
                cnt--;
            }
        }
 
        // Perform the swap in BOTH arrays
        swap(pos[valA], pos[valB]);
        swap(num[a], num[b]);
 
        // Add the contribution of these pairs AFTER the swap
        for (auto p : pairs_to_check) {
            if (pos[p.first] > pos[p.second]) {
                cnt++;
            }
        }
 
        cout << cnt << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
        if(t != 0) cout << '\n';
    }
}
