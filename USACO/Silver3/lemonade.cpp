#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lemonade.in", "r", stdin); freopen("lemonade.out", "w", stdout);
    int n; cin >> n;
    int cows[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }
    sort(cows, cows+n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        if(cows[i] < i){
            ans = i;
            break;
        }
    }
    cout << ans;
    
}