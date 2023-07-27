#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int odd = 0;
    int even = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int t; cin>>t;
        if (t % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }

    if (even == 0){
        even++;
        odd-=2;
    }

    
    int pairs = min(even, odd);
    ans += pairs*2;
    even -= pairs;
    odd -= pairs;

    pairs = (odd/3);
    ans += pairs*2;
    odd-=pairs*3;
    if (odd >= 2){
        ans++;
    }
    if (even >= 1){
        ans++;
    }
    cout<<ans;
}