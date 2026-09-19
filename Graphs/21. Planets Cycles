#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve(){
    int n;
    cin >> n;
    
    vector<int> g(n + 1), indeg(n + 1), comp(n + 1);
    vector<vector<int>> t(n + 1);
    vector<vector<int>> up(n + 1, vector<int> (20));
    for(int i = 1; i <= n; i++){
        cin >> g[i];
        indeg[g[i]]++;
        t[g[i]].push_back(i);
        up[i][0] = g[i];
    }

    queue<int> qu;
    for(int i = 1; i <= n; i++){
        if(!indeg[i]) qu.push(i);
    }

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();

        if(--indeg[g[u]] == 0) qu.push(g[u]);
    }

    int cnt = 0;
    vector<int> dc(n + 1), cycle_len(n + 1);
    
    for(int i = 1; i <= n; i++){
        if(indeg[i] && comp[i] == 0){
            cnt++;
            
            int node = i, pos = 0;
            do{
                comp[node] = cnt;
                dc[node] = pos++;
                node = g[node];
            }while(node != i);

            cycle_len[comp[node]] = pos;
        }
    }

    for(int i = 1; i <= n; i++){
        if(indeg[i]) qu.push(i);
    }

    vector<int> d(n + 1);
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        
        for(int &v : t[u]){
            if(!indeg[v]){
                comp[v] = comp[u];
                d[v] = d[u] + 1;
                qu.push(v);
            }
        }
    }

    for(int a = 1; a <= n; a++){
        int ans = d[a];
        cout << d[a] + cycle_len[comp[a]] << ' ';
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
