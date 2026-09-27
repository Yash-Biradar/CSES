#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n;
    cin >> n;
 
    deque<int> d;
    map<int, int> mp;
 
    int ans = 1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
 
        if(mp[x]){
            ans = max(ans, (int) d.size());
            while(!d.empty() && d.front() != x){
                mp[d.front()] = 0;
                d.pop_front();
            }
            d.pop_front();
            mp[x] = 1;
        }
        else mp[x]++;
        d.push_back(x);
    }
 
    ans = max(ans, (int) d.size());
 
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
