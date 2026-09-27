#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n;
    cin >> n;
 
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    set<int> s;
    ll ans = 0;
    int left = 0;
 
    for(int right = 0; right < n; right++){
        while(s.count(a[right])){
            s.erase(a[left]);
            left++;
        }
 
        s.insert(a[right]);
 
        ans += (right - left + 1);
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
