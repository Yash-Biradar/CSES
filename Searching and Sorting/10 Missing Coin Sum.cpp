#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n;
    cin >> n;
 
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    sort(a.begin(), a.end());
 
    ll res = 1;
    for(int i = 0; i < n; i++){
        if(res < a[i]) break;
        else{
            res += a[i];
        }
    }
 
    cout << res;
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
