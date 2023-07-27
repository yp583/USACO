#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("haircut.out", "r", stdin);
    int arr[100001];
    for (int i = 0; i < 99999; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 99999; i++)
    {
        int t; cin >> t;
        if (t != arr[i]){
            cout << i << " ";
        }
    }

    
}