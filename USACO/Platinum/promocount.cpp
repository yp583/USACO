#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define f first
#define s second

int N;
vector<pi> vals;
vector<int> adj[10001];
int parents[10001];

//for dfs
bool visited[10001];
int heights[10001];
vector<int> leaves;

//ans
int ans[10001];

int timer = -1;
bool cmpv(pi a, pi b){
    return a.s < b.s;
}
bool cmpi(pi a, pi b){
    return a.f < b.f;
}

void dfs(int node, int height, int pnode){
    visited[node-1] = true;
    heights[node-1] = height;
    int children = 0;
    for (int n: adj[node-1])
    {
        if (!visited[n-1]){
            dfs(n, height+1, node);
            children++;
        }
    }
    if (children==0){
        leaves.push_back(node);
    }
}
void rdfs(int node){
    if (parents[node-1] != 0){
        rdfs(parents[node-1]);
    }
    
}
int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t; cin>>t;
        vals.push_back({i, t});
    }
    sort(vals.begin(), vals.end(), cmpv);
    for (int i = 0; i < N; i++)
    {
        vals[i].s = i;
    }
    sort(vals.begin(), vals.end(), cmpi);
    //for(auto v: vals) cout << v.s << " "; cout << "\n";
    for (int i = 1; i < N; i++)
    {
        int s_; cin >> s_;
        adj[s_-1].push_back(i+1);
        parents[i] = s_;
    }
    //for(int a: parents) cout << a << " "; cout << "\n";
    /*
    for (int i = 0; i < N; i++)
    {
        cout << i+1 << ": ";
        for(int a: adj[i]) cout << a << " "; cout << "\n";
    }
    */
    dfs(1, 0, -1);
    //for (int i = 0; i < leaves.size(); i++) cout << leaves[i] << " ";

    
    
}