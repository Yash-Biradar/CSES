#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> vis(n, vector<int>(m, 1));
    vector<vector<char>> mp(n, vector<char> (m));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>> (m));
 
    int r = 0, c = 0;
    int br = 0, bc = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
            if(mp[i][j] == '.') vis[i][j] = 0;
            else if(mp[i][j] == 'A') {
                r = i; c = j;
                vis[i][j] = 0;
            }
            else if(mp[i][j] == 'B'){
                vis[i][j] = 0;
                br = i; bc = j;
            }
        }
    }
 
    string ans = "";
    bool found = false;
    
    vis[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
 
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
 
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
 
        for(int i = 0; i < 4; i++){
            int nr = a + dr[i];
            int nc = b + dc[i];
 
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mp[nr][nc] == '.'){
                q.push({nr, nc});
                vis[nr][nc] = 1;
                par[nr][nc] = {a, b};
            }
            else if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mp[nr][nc] == 'B'){
                cout << "YES" << endl;
                found = true;
                par[nr][nc] = {a, b};
                break;
            }
        }
        if(found) break;
    }
 
    if(!found){
        cout << "NO";
        return;
    }
 
    while(mp[br][bc] != 'A'){
        int pr = par[br][bc].first;
        int pc = par[br][bc].second;
 
        if(pr > br && pc == bc) ans.push_back('U');
        else if(pr < br && pc == bc) ans.push_back('D');
        else if(pr == br && pc < bc) ans.push_back('R');
        else ans.push_back('L');
 
        br = pr; bc = pc;
    }
 
    reverse(ans.begin(), ans.end());
 
    cout << ans.size() << endl << ans;
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
