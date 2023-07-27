#include <bits/stdc++.h>
using namespace std;

vector<int> cows;

int main(){
    int n, m, c;
    freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
    cin>>n>>m>>c;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        cows.push_back(t);
    }
    int ans = 0;
    sort(begin(cows), end(cows));
    for (int i = 0; i < n; i+=(c))
    {
        int wait = cows[min(i+c-1, n-1)] - cows[i];
        if (wait > ans){
            ans = wait;
        }
    }
    cout << ans << endl;
}