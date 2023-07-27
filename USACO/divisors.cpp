#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N; cin>>N;
    int primes[40] = {0};

    ll n = N;

    int d = 0;

    bool added = false;
    for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			primes[d]++;
			n /= i;
            added = true;
		}
        if (added){
            d++;
            added = false;
        }
	}
	if (n > 1){
        primes[d]++;
    }

    int ans = 0;
    int c = 1;

    for (int i = 0; i < 40; i++)
    {
        while (primes[i] > 0){
            primes[i] -= c;
            if (primes[i] >= 0){
                ans++;
                c++;
            }
        }
        c=1;
    }
    cout << ans;
    
    
}