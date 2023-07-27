#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int binarysearch(){
    int lo = 1;
    ll hi = 1000000000000;
    while (hi-lo > 1) {
		int mid = (lo + hi) / 2;
        int three = mid/3;
        int five = mid/5;
        int fifteen = mid/15;
        int num = mid - (five + three);
        num += fifteen;
		if (num < n) {
			lo = mid;
		} else { 
			hi = mid;
		}
        
	}
    return hi;
}

int main(){
    freopen("moobuzz.in", "r", stdin); freopen("moobuzz.out", "w", stdout);
    cin >> n;
    cout << binarysearch();
}