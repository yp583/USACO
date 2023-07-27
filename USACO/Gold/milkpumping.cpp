#include <bits/stdc++.h>
using namespace std;


int main(){
	//freopen("pump.out", "w", stdout); freopen("pump.in", "r", stdin);
    int n, m; cin >> n >> m;
    int dp[n+1][3];
    dp[1][0] = 0; 
    dp[1][1] = 1e3 + 1;
    dp[1][2] = 0;
    int edges[m+1][4] = {0, 0, 0, 0};
    for (int i = 1; i < m+1; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2] >> edges[i][3];
        if (edges[i][0] > edges[i][1]){
            swap(edges[i][0], edges[i][1]); //edges[i][0] contains lower value
        }
    }
    //cout << "\n\n\n";
    //for (auto e: edges) cout << e[0] << ";" << e[1] << " "; cout << "\n";
    for (int i = 2; i < n+1; i++)
    {
        int best[3];
        best[0] = 1e6 + 1; //cost
        best[1] = 0; //flow
        best[2] = 0; //ratio
        for (int j = 1; j < m+1; j++)
        {
            auto e = edges[j];
            //cout << e[1];
            if (e[1] == i){ //if destination is the current node we are checking
                //cout << e[1] << " " << i << "\t";
                //cout << "dp: " << dp[edges[j][0]][0] << "; " << dp[edges[j][0]][1] << ", cost[j]: " << edges[j][3] << ", j: " << j << "\n";
                int ccost = (dp[e[0]][0] + e[2]);
                int cflow = min(dp[e[0]][1], e[3]);
                int cratio = floor((double(cflow)/ccost) * 1000000);
                if (cratio > best[2]){
                    best[0] = dp[e[0]][0] + e[2];
                    best[1] = min(dp[e[0]][1], e[3]);
                    best[2] = cratio;
                }
                /*
                if (((dp[e[0]][0] + e[2]) < best[0]) && (min(dp[e[0]][1], e[3]) >= best[1])){
                    best[0] = dp[e[0]][0] + e[2];
                    best[1] = min(dp[e[0]][1], e[3]);
                    //cout << "dp: " << dp[e[0]][0] << "; " << dp[e[0]][1] << ", cost[j]: " << e[3] << ", j: " << j << "\n";
                }
                */
            }
        }
        dp[i][0] = best[0]; //cost
        dp[i][1] = best[1]; //flow
        dp[i][2] = best[2]; //ratio
    }
    //cout << floor((double(dp[n][1])/(dp[n][0])) * 1000000);<< dp[i][0] << ":" << dp[i][1] << ":"
    for(int i = 1; i < n+1; i++) cout << dp[i][2] << " ";
}