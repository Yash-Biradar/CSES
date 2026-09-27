#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n;
    cin >> n;
 
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    ll ans = -1e18, sum = 0;
    for(int i = 0; i < n; i++){
        if(sum < 0) sum = a[i];
        else sum += a[i];
 
        ans = max(ans, sum);
    }
 
    cout << ans;
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
