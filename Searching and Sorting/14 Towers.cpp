#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n;
    cin >> n;
 
    vector<int> temp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
 
        auto it = upper_bound(temp.begin(), temp.end(), x);
        if(it != temp.end()) {
            *it = x;
        }
        else temp.push_back(x);
    }
 
    cout << temp.size();
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
