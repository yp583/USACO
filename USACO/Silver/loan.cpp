#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;

int n;
vector<pair<ll, ll>> cowsx;
vector<pair<ll, ll>> cowsy;

bool bruteok(int M){
    for (int i = 0; i < n; i++)
    {
        int a = cowsx[i].f+1;
        for (int j = 0; j < n; j++)
        {
            int b = cowsy[j].f+1;
            
            
        }
        
    }
    
}
int bs(){
    int lo = 0;
    int hi = (n+4)/4;
    while (hi-lo > 1) {
		int mid = (lo + hi) / 2;
		if (bruteok(mid)) {
			lo = mid;
		} else { 
			hi = mid - 1;
		}
        
	}
    return lo;
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t[2];
        cin >> t[0] >> t[1];
        cowsx.push_back({t[0], t[1]}); //coords are (x, y)
        cowsy.push_back({t[1], t[0]}); //coords will now be (y, x)
    }
    sort(begin(cowsx), end(cowsx));
    sort(begin(cowsy), end(cowsy));
}