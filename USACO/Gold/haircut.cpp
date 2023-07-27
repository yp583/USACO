#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[100001];
ll bit[100010] = {0};
int n; 

ll lsb(ll pos) {
    return pos & -pos;
}

void update(ll i, ll val){
    if (i < n){
        bit[i] += val;
        update((i + lsb(i+1)), val);
    }
}
ll sum(ll i){
    if (i > 0){
        return bit[i-1]+sum(i-lsb(i));
    }
    else{
        return 0;
    }
}

int main(){
    freopen("haircut.out", "w", stdout); freopen("haircut.in", "r", stdin);
    cin >> n;
    ll inversions[100010] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]++;
    }
    for (int i = 0; i < n; i++)
    {
        update(arr[i]-1, 1);
        inversions[arr[i]] += i+1 - sum(arr[i]);

    }
    ll prev = 0;
    for (int i = 0; i < n; i++)
    {
        prev += inversions[i];
        cout << prev << "\n";
    }
    
    //cout << inversions << "\n";
    //for(auto i: inversions) cout << i << " ";
}