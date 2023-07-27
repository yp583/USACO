#include <iostream>
using namespace std;
int solve(int p1, int p2){
    int ans = 0;
    while (p1 > p2){//if greater
        if (p1 % 2 == 1){//if odd
            p1++;
            ans++;
        }
        else{
            p1/=2;
            ans++;
        }
    }
    if (ans > 0){
        while (p1 < p2){
            p1++;
            ans++;
        }
    }
    else{
        while (p1 < p2){
            if (2*p1 <= p2){
                p1*=2;
                ans++;
            }
            else{
                p1++;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int n; cin >> n;
    int ans[10];
    for (int i = 0; i < n; i++)
    {
        int pair[2];
        cin >> pair[0] >> pair[1];
        ans[i] = solve(pair[0], pair[1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<'\n';
    }
    
    
}