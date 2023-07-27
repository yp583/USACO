#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q; 
ll e[100001];
vector<int> euler[2]; //first row is node id, second is node height
int first[100001];
//vector<int> lca[20];
bool visited[100001] = {false};
map<int, vector<int>> adj;
int parents[100002] = {-1};
int root = 1;

int heights[100002];

//sparse table
int mintable[200020][20];

//length n;
ll cumxor[100001];


void update(int index, int val){
    e[index-1] = val;
}

int query(int a, int b){
    int l = abs(first[a-1] - first[b-1]);
    //cout << l << " ";
    int fa = first[a-1];
    int fb = first[b-1];
    if (l > 0){
        l = floor(log2(l));
    }
    int lca = mintable[(fb-(1<<l))][l];
    if (heights[mintable[fa][l]-1] < heights[mintable[fb-(1<<l)][l]-1]){
        lca = mintable[fa][l];
    }
    cout << lca;
    return cumxor[a-1] ^ cumxor[b-1] ^ e[lca-1];
}

void dfs(int node, int height, int prevxor, int parent = -1){
    visited[node] = true;
    euler[0].push_back(node);
    euler[1].push_back(height);
    first[node-1] = euler[0].size()-1;
    heights[node-1] = height;
    cumxor[node-1] = prevxor ^ e[node-1];
    //euler[2].push_back(e[node-1]);
    int s = adj[node].size();
    //cout << s;
    //cout << node << "\t";
    for (int ne = 0; ne < s; ne++){
        if (!visited[adj[node][ne]]){
            dfs(adj[node][ne], height+1, cumxor[node-1], node);
        }
    }
    if (parent != -1){
        euler[0].push_back(parent);
        euler[1].push_back(height - 1);
    }
}

void buildsparsetableiter(){
    int size = euler[1].size();
    int len = floor(log2(size));
    for (int j = 0; j <= len; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (j == 0){
                mintable[i][j] = euler[0][i];
                //lca[i][j] = euler[0][i];
            }
            else{
                int h1 = heights[mintable[i][j-1]];
                int h2 = heights[mintable[i+(1<<(j-1))][j-1]];
                if (h2 > h1){
                    mintable[i][j] = mintable[i][j-1];
                }
                else{
                    mintable[i][j] = mintable[i+(1<<(j-1))][j-1];
                }
            }
        }
    }
}

int main(){
    freopen("cowland.out", "w", stdout); freopen("cowland.in", "r", stdin);
    cin >> n >> q;
    vector<int> ans;
    //enjoyment values
    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
    }
    //edges
    for (int i = 0; i < n-1; i++)
    {
        int f, s; cin >> f >> s;
        //if (f > s) swap(f, s);
        //cout << f << ":" << s << " ";
        adj[f].push_back(s);
    }
    //cout << "\n"; for (int i = 0; i < n; i++)cout << parents[i] << " ";cout << "\n";
    dfs(1, 0, 0);
    buildsparsetableiter();
    //for (int i = 0; i < n; i++) cout << heights[i] << " "; cout << " \n";
    
    int size = euler[1].size();
    int len = floor(log2(size));
    
    for (int j = 0; j <= len; j++)
    {
        for (int i = 0; i < 100; i++)
        {
            cout << mintable[i][j] << " ";
        }
        cout << " \n";
    }
    
    for (int i = 0; i < 1; i++)
    {
        int t, a, b; cin >> t >> a >> b;
        if (t == 2){
            //cout << cumxor[a-1] << ":";
            //cout << cumxor[b-1] << "\n";
            //cout << e[1058] << " ";
            ans.push_back(query(a, b));
        }
        //else{
            //update(a, b);
        //}
    }
    for (int a: ans) cout << "answer" << a << "\n";
    



    
    //for(auto es: euler[0]) cout << es << " "; cout << "\n"; for(auto es: euler[1]) cout << es << " "; //cout << "\n"; for(auto es: euler[2]) cout << es << " ";
    /*
    for (int i = 0; i < euler[1].size(); i++)
    {
        buildsegtree(euler[1][i], i, i);
    }
    */

}