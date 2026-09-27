#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> road(n + 1);
    vector<int> vis(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        road[u].push_back(v);
        road[v].push_back(u);
    }
 
    auto bfs = [&](int i){
        queue<int> q;
        q.push(i);
 
        while(!q.empty()){
            int node = q.front();
            q.pop();
 
            for(int next : road[node]){
                if(!vis[next]){
                    q.push(next);
                    vis[next] = 1;
                }
            }
        }
    };
 
    vector<int> city;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            bfs(i);
            city.push_back(i);
        }
    }
 
    cout << city.size() - 1 << endl;
    for(int i = 1; i < city.size(); i++){
        cout << city[i - 1] << ' ' << city[i] << endl;
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
