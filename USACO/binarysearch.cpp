#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef long long LL;
#define INF 2000000000

int n, m;
vector<pair<LL, LL>> grass;
bool ok(LL d) {
    LL prev = -1LL * INF * INF;
    
    int cnt = 0;
    for (auto& i : grass) {
        while (max(prev + d, i.f) <= i.s) {
            prev = max(prev + d, i.f);
            cnt++;
            if (cnt >= n) break;
        }
        if (cnt >= n) break;
    }
 
    return (cnt >= n);
}

int binarysearch(){
    int lo = 1;
    int hi = grass[m-1].s;
    while (hi-lo > 1) {
		int mid = (lo + hi) / 2;
		if (ok(mid)) {
			lo = mid;
		} else { 
			hi = mid - 1;
		}
        
	}
    return lo;
}

int main(){
    //freopen("socdist.in", "r", stdin);
	//freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    int ans;
    for (int i = 0; i < m; i++)
    {
        int fi, se; cin>>fi>>se;
        grass.push_back({fi, se});
    }
    sort(begin(grass),end(grass));
    ans = binarysearch();
    cout<<ans;
    //fclose (stdout);
    
}