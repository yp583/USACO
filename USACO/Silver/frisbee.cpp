#include <iostream>
using namespace std;


int main(){
    int n; cin>>n;
    int cows[30001];
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        cin>>cows[i];
    }
    for (int i = 0; i < n; i++)
    {
        int min_ = n+1;
        for (int j = i+1; j < n; j++)
        {
            int shrt = min(cows[i], cows[j]);
            if (j-i == 0){
                ans++;
            }
            else{
                min_ = min(min_, cows[j-1]);
                if (min_ < shrt){
                    ans += j-i+1;
                }
            }
        }
        
    }
    cout<<ans;
    
}