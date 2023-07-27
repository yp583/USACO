#include <bits/stdc++.h>
using namespace std;


typedef long long LL;
vector<LL> hay;
int n;
int bs(int val){
    int lo = 0;
    int hi = n;
    while (hi-lo!=1) {
		int mid = (lo + hi) / 2;
        if (hay[mid] == val){
            return mid;
        }
		else if (hay[mid] < val) {
			lo = mid;
		} else { 
			hi = mid - 1;
		}
	}
    if (hay[lo] == val){
        return lo;
    }
    else{
        return hi;
    }
}
bool ok(float r){
    int st = bs((hay[n] - hay[0])/2);
    int curr = hay[st];
    float cr = r;
    int furthest = 0;
    bool works = false;
    for (int i = st+1; i < n; i++)
    {
        if (hay[i] <= curr + cr){
            furthest=hay[i];
            works = true;
        }
        else{
            if (works == false){
                return false;
            }
            curr = furthest;
            cr--;
            works = false;
        }
    }
    cr = r;
    curr = hay[st];
    furthest = 0;
    works = false;
    for (int i = st-1; i >= 0; i--)
    {
        if (hay[i] >= curr - cr){
            furthest=hay[i];
            works = true;
        }
        else{
            if (works == false){
                return false;
            }
            curr = furthest;
            cr--;
            works = false;
        }
    }
    return true;
}
int binarysearch(){
    float lo = hay[0];
    float hi = hay[n];
    while (hi-lo > 1) {
		int mid = (lo + hi) / 2.0f;
		if (!ok(mid)) {
			lo = mid+1;
		} else { 
			hi = mid;
		}
        
	}
    if (ok(lo)){
        return lo;
    }
    else{
        return hi;
    }
}

int main(){
    freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int t; cin>>t;
        hay.push_back(t);
    }
    sort(begin(hay), end(hay));
    int st = (hay[n-1] - hay[0])/2;
    hay.push_back(st);
    sort(begin(hay), end(hay));

    float ans = binarysearch();
    cout << fixed << setprecision(1) << ans;
    
    
}