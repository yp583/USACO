#include <iostream>
using namespace std;

int n;
string cowstr;
int cows[50001];
int pref[50002];
int ans = 0;

int main(){
    cin >> n;
    cin >> cowstr;
    pref[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (cowstr[i] == 'G'){
            cows[i] = 0;
        }
        else{
            cows[i] = 1;
        }
        pref[i+1] = pref[i] + cows[i];
    }
    for (int j = 3; j < n; j++)
    {
        for (int i = j; i < n; i++)
        {
            int h = pref[i-j]-pref[i];
            int g = (j) - (pref[i-j]-pref[i]);
            if (h < 2 || g < 2){
                ans++;
            }
        }
        
        
    }
    cout<<ans;
    
}