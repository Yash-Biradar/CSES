#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1), rev_g(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        rev_g[v].push_back(u);
    }

    vector<int> d(n + 1, 1e9);
    
    vector<int> vis(n + 1);
    queue<int> q;
    q.push(1);
    d[0] = d[1] = 0;

    while(!q.empty()){
        int u = q.front();
        vis[u] = 1;
        q.pop();

        for(int &v : g[u]){
            if(!vis[v]){
                d[v] = 0;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(d[i] != d[1]){
            cout << "NO" << endl << 1 << ' ' << i;
            return;
        }
    }

    q.push(1);
    d[1] = 1;
    while(!q.empty()){
        int u = q.front();
        vis[u] = 2;
        q.pop();

        for(int &v : rev_g[u]){
            if(vis[v] != 2){
                d[v] = 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(d[i] != d[1]){
            cout << "NO" << endl << i << ' ' << 1;
            return;
        }
    }

    cout << "YES";
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
