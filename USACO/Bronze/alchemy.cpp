#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi adj[101];
int metals[101];
int n, k;

bool visited[101] = {false};
//int ans[101];

int dfs(int node){
    visited[node] = true;
    int min_ = 1000000000;
    bool leaf = true;
    for (int ne: adj[node])
    {
        if(!visited[ne]){
            leaf = false;
            int v = dfs(ne);
            min_ = min(min_, v);
        }
    }
    if (leaf){
        //cout << metals[node] << "\n";
        return metals[node];
    }
    else{
        //cout << min_ << "\n";
        return min_ + metals[node];
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> metals[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l, m; cin >> l >> m;
        for (int j = 0; j < m; j++)
        {
            int t; cin >> t;
            adj[l-1].push_back(t-1);
        }
    }
    /*
    for (int i = 0; i <= k; i++)
    {
        cout << i+1 << ": ";
        for(int ad: adj[i]) cout << ad << " ";
        cout << "\n";
    }
    */
    //for(int ad: adj[99]) cout << ad << " ";
    cout << dfs(n-1);
    
}