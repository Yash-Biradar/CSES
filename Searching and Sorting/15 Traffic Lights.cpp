#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int x, n;
    cin >> x >> n;
 
    vector<int> p;
    set<int> s;
    multiset<int> gap;
    
    s.insert(0);
    s.insert(x);
    gap.insert(x);
 
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
 
        auto it1 = s.upper_bound(x);
        auto it2 = it1;
        it2--;
 
        int g0 = *it1 - *it2;
        int left = x - *it2;
        int right = *it1 - x;
 
        gap.erase(gap.find(g0));
        gap.insert(left);
        gap.insert(right);
        s.insert(x);
        cout << *gap.rbegin() << ' ';
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
