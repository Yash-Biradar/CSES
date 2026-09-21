#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> vis(n, vector<int> (m, 1));
 
    vector<vector<char>> mp(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
            if(mp[i][j] == '.') vis[i][j] = 0;
        }
    }
 
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
 
    auto bfs = [&](int i, int j){
        vis[i][j] = 1;
 
        queue<pair<int, int>> q;
        q.push({i, j});
 
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
 
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
 
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mp[nr][nc] == '.'){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    };
 
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == '.' && !vis[i][j]){
                bfs(i, j);
                cnt++;
            }
        }
    }
 
    cout << cnt;
 
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
