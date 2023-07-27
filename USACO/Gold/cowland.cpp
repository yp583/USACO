#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//reading inputs
int n, q;
ll enjoy[100001];
vector<int> adj[100001];

//for dfs
bool visited[100001] = {false};
int heights[100001] = {-1};
ll cumxor[100001];

int st[100001];
int en[100001];
int bit[100001];

//euler tour
int euler[200001];
int first[100001];
//lca stuff;
int mintable[18][200002];

int timer = -1;
int lsb(int pos) {
    return pos & -pos;
}
void dfs(int node, int height, int pnode){

    visited[node-1] = true;
    heights[node-1] = height;
    euler[++timer] = node;
    first[node-1] = timer;
    st[node-1] = timer;
    if (pnode != -1){
        cumxor[node-1] = cumxor[pnode-1] ^ enjoy[node-1];
    }
    else{
        cumxor[node-1] = enjoy[node-1];
    }
    //cout << node <<  " ";
    for (int neighbor: adj[node-1])
    {
        if (!visited[neighbor-1]){
            dfs(neighbor, height+1, node);
        }
    }
    if (pnode != -1){
        euler[timer] = pnode;
        en[node-1] = timer;
    }
    else{
        en[node-1] = timer;
    }
}

void build(){
    int len = floor(log2(timer));
    for (int k = 0; k <= len; k++)
    {
        for (int i = 0; i+(1<<k) <= timer; i++)
        {
            if (k == 0){
                mintable[0][i] = euler[i];
            }
            else{
                if (heights[mintable[k-1][i]-1] < heights[mintable[k-1][i+(1<<(k-1))]-1]){
                    mintable[k][i] = mintable[k-1][i];
                }
                else{
                    mintable[k][i] = mintable[k-1][i+(1<<(k-1))];
                }
            }
        }
        
    }
    
}

int lca(int a, int b){
    int fa = first[a-1];
    int fb = first[b-1];
    if (fa > fb){
        swap(fa, fb);
    }
    int length = fb - fa;
    int len = 0;
    if (length != 0){
        len = floor(log2(length));
    }
    int ma = mintable[len][fa];
    int mb = mintable[len][fb-(1<<len)];
    if (heights[ma-1] < heights[mb-1]){
        return ma;
    }
    else{
        return mb;
    }
    
}


void updatebit(int i, int val){
    if (i <= timer){
        cout << "bit: " << i << "\n";
        bit[i] ^= val;
        updatebit((i + lsb(i+1)), val);
    }
}
int querybit(int i){
    if (i > 0){
        return bit[i-1]+querybit(i-lsb(i));
    }
    else{
        return 0;
    }
}
void update(int node, int newval){
    node--;
    updatebit(st[node], enjoy[node]);
    updatebit(en[node], enjoy[node]);
    enjoy[node] = newval;
    updatebit(st[node], enjoy[node]);
    updatebit(en[node], enjoy[node]);
}
int query(int a, int b){
    return querybit(st[a]) ^ querybit(st[b]) ^ enjoy[lca(a, b) - 1];
}
int main(){
    freopen("cowland.out", "w", stdout); freopen("cowland.in", "r", stdin);
    
    cin >> n >> q;

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> enjoy[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        int f; int s; cin >> f >> s;
        adj[f-1].push_back(s);
        adj[s-1].push_back(f);
    }
    //for (int i = 0; i < n; i++) { cout << i << ": "; for(int a: adj[i]) cout << a << " "; cout << "\n";}
    
    dfs(1, 0, -1);
    build();
    /*
    for (int i = 0; i < n; i++)
    {
        cout << st[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << en[i] << " ";
    }
    cout << "\n";
    */
    for (int i = 0; i < n; i++)
    {
        updatebit(st[i], enjoy[i]);
        updatebit(en[i], enjoy[i]);
    }
    for (int i = 0; i <= 12; i++)
    {
        cout << bit[i] << " ";
    }
    cout << "\n" << querybit(9) << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << st[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << en[i] << " ";
    }

    cout << "\n";
    for (int i = 0; i < q; i++)
    {
        int t, a, b; cin >> t >> a >> b;
        if (t == 2){
            ans.push_back(query(a, b));
        }
        else{
            update(a, b);
        }
    }
    for (int a: ans) cout << a << "\n";
    //aszcout << heights[528];
    //cout << query(4508, 1379) << "\n";
    
    //cout << "lca: " << lca(1804, 2532) << "\n";
    //for(int i=0; i < timer; i++) cout << euler[i] << " "; cout << "\n";
    //for(int i=0; i < timer; i++) cout << heights[euler[i]-1] << " ";
    //cout << first[1378] << " " << first[4507];
    /*
    for (int i = 0; i < n; i++)
    {
        cout << first[i] << " ";
    }
    */
    //cout << "\n" << lca(8, 7);
    //cout << "\n" << timer;
}