#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n;
    cin >> n;
 
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pos[x - 1] = i;
    }
 
    int cnt = 1;
    for(int i = 0; i < n - 1; i++){
        if(pos[i] > pos[i + 1]) cnt++; 
    }
 
    cout << cnt;
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
