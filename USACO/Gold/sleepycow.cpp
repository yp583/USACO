#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("sleepy.in", "r", stdin); freopen("sleepy.out", "w", stdout);
    int n; cin >> n;
    int cows[n+1];
    cows[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i+1];
    }
    int ans = 0;
    for (int i = n-1; i > 0; i--)
    {
        if (cows[i] > cows[i+1]){
            ans = i-1;
            break;
        }
    }
    cout << ans + 1 << "\n";
    for (int i = 1; i < ans+2; i++)
    {
        cout << cows[i] - cows[i-1] + ans - 1;
        if (i != ans+1){
            cout << " ";
        }
    }
}