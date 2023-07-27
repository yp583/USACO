#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int times[n];
    int edges[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        int f, s; cin >> f >> s;
        edges[f-1]++;
        edges[s-1]++;
    }

    for (int i = 0; i < n; i++)
    {
        (edges[i] + times[i] == 12){
            
        }
    }
    
    //possible for every start node if num edges is 12 - value at node.
    //for (auto e: edges) cout << e << " ";
}