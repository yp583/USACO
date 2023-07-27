#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
bool visited[10001] = {false};
vector<LL> adj[10001];

void dfs(int node){
    visited[node] = true;
    cout << adj[5].empty() << " ";
    if (adj[node].empty()){
        return;
    }
    for (int i = 1; i <= adj[node].size(); i++)
    {
        cout << node << "node";
         if(!visited[adj[node][i]]){
            dfs(adj[node][i]);
        }
    }
    /*
    for (auto u: adj[node]){
        cout << u << "  ";
        if(!visited[u]){
            dfs(u, adj);
        }
    }
    */
}

int main(){
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        int n, m; cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int fi, se; cin >> fi >> se;
            adj[fi].push_back(se);
        }
        dfs(4);
        
    }
    
}