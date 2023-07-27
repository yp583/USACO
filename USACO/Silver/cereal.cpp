#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main(){
    int n, m; cin >> n >> m;
    int eaten[n];
    int ans;
    vector<pair<pair<int, int>, int>> fav;
    for (int i = 0; i < n; i++)
    {
        eaten[i] = 0;
        int f, s; cin>>f>>s;
        fav.push_back({{f, s}, i});
    }
    sort(begin(fav),end(fav));

    for (int i = 0; i < n; i++)
    {
        if (eaten[fav[i].f.f] > 0){
            swap(fav[i].f.f, fav[i].f.s);
            if (eaten[fav[i].f.f] > 0){
                ans++;
            }
            else{
                eaten[fav[i].f.f]++;
            }
        }
        else{
            eaten[fav[i].f.f] ++ ;
        }
    }
    cout<<ans<<"\n";
    for (auto e: fav) cout << e.s+1 << "\n";
}