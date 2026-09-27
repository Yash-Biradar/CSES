#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n;
    cin >> n;
 
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    int mi = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
 
    auto check = [&](int x){
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum += abs(x - a[i]);
        }
 
        return sum;
    };
 
    int low = mi, high = mx;
    ll ans = 0;
    while(low < high){
        int mid = (high - low) / 2 + low;
        
        ll a = check(mid);
        ll b = check(mid + 1);
 
        if(a > b){
            low = mid + 1;
            ans = b;
        }
        else {
            high = mid;
            ans = a;
        }
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
