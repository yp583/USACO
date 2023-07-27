//solved!!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define c first
#define w second

bool cmp(pair<int, bool> a, pair<int, bool> b){
    return a.c > b.c;
}

int main(){
    int n, k; cin >> n >> k;
    k--;
    vector<pair<ll, bool>> cows;
    vector<pair<ll, bool>> jumps;
    int ans;
    for (int i = 0; i < n; i++)
    {
        ll t; cin >> t;
        bool div = (t%12==0);
        t = ceil((t)/12.0);
        cows.push_back({t, div});
    }
    sort(begin(cows), end(cows), cmp);
    if (!cows[0].w){
        cows.insert(cows.begin(), {cows[0].c, true});
        n++;
    }
    if (!cows[n-1].w){
        cows.push_back({cows[n-1].c-1, true});
        n++;
    }
    //for (auto c: cows) cout << c.c << " ";
    for (int i = 1; i < n+1; i++)
    {
        ll dif = 0;
        if (i == n){
            dif = cows[i-1].c;
        }
        else{
            dif = cows[i-1].c - cows[i].c;
        }
        if (dif >= 2){
            jumps.push_back({dif, cows[i-1].w});
        }
    }
    ans = cows[0].c;

    //cout << ans;
    sort(begin(jumps), end(jumps), cmp);
    //cout << ans;
    //for (auto c: jumps) cout << c.c << " ";
    for (int i = 0; i < k; i++)
    {   
        ans-=(jumps[i].c);
        if (!jumps[i].w){
            ans+=1;
        }
        
    }

    cout << (ans)*12;

    
}