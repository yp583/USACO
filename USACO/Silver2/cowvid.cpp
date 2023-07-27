//solved!!

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int edges[n] = {0};
    edges[0] = 1;
    int ans = 0;
    //for(auto e: edges) cout << e << " ";
    int f, s; 
    for (int i = 0; i < n-1; i++)
    {
        cin >> f >> s;
        edges[f-1]++;
        edges[s-1]++;
    }
    //for(auto e: edges) cout << e << " ";
    for (int i = 0; i < n; i++)
    {
        edges[i]--;
        if (edges[i]!=0){
            ans += ceil(log2(edges[i]+1));
            ans += edges[i];
        }
    }

    cout << ans;
    


    
}