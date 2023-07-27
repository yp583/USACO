#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;
map<int, int> n2v; //node to value

vector<int> dfs(int node){
    vector<int> val = {n2v[node]};
    for (int i = 0; i < adj[node].size(); i++)
    {
        val.push_back(dfs(adj[node][i+1]));
    }
    return val;
}

int main(){
    int n; cin >> n;
    int c[n];

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        n2v[i+1] = c[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        int f, s; cin >> f >> s;
        adj[f].push_back(s);
    }
    cout << dfs(1);
    /*
    for (int i = 0; i < n; i++)
    {
        cout << i+1 << " : ";
        for(auto v: adj[i+1]) cout << v << " "; cout << "\n";
    }
    */
    

}