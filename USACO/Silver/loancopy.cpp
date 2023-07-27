#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;
int prefx[100001];
int prefy[100001];
int n;
vector<pair<ll, ll>> cows;
bool ok(int m){
    int q1 =0; int q2=0; int q3=0; int q4 = 0;
    //cout << n;
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            q1 = min(prefx[a], prefy[b]);
            q2 = prefx[a]-q1;
            q3 = prefy[b]-q1;
            q4 = n-(q1+q2+q3);
            if (max(max(max(q1, q2), q3), q4) <= m){
                return true;                
            }
        }
    }
    return false;
    
}
int bs(){
    int lo = 0;
    int hi = n;
    while (hi-lo > 1) {
		int mid = (lo + hi) / 2;
        //cout << lo << " " << mid << " " << hi << "\n";
		if (ok(mid)) {
			hi = mid;
		} else { 
			lo = mid + 1;
		}
        
	}
    if (ok(lo)){
        return lo;
    }
    else{
        return hi;
    }
}
bool ycmp(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.y<b.y;
}

int main(){
    freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t[2];
        cin >> t[0] >> t[1];
        cows.push_back({t[0], t[1]}); //coords are (x, y)
    }
    int c = -1;
    sort(begin(cows), end(cows), ycmp);
    int prev = -1;
    for (int i = 0; i < n; i++)
    {   
        if (i == 0 || cows[i].y != prev){
            c++;
        }
        prev = cows[i].y;
        cows[i].y = c;
    }
    sort(begin(cows), end(cows));
    c=-1;
    prev = -1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || cows[i].x != prev){
            c++;
        }
        prev = cows[i].x;
        cows[i].x = c;
    }
    for(auto c: cows) cout << c.x << " " << c.y << "\n";
    prefx[0] = 0;
    prefy[0] = 0;
    c=0;
    sort(begin(cows), end(cows), ycmp);
    for (int i = 1; i <= n; i++)
    {
        prefy[i] = prefy[i-1];
        while (i == cows[c].y+1){
            prefy[i]++;
            c++;
        }
        
    }
    c = 0;
    sort(begin(cows), end(cows));
    for (int i = 1; i <= n; i++)
    {
        prefx[i] = prefx[i-1];
        while (i == cows[c].x+1){
            prefx[i]++;
            c++;
        }
        
    }
    //for (int i = 0; i < n; i++) cout << prefy[i+1] << " ";
    //cout << "\t";
    //for (int i = 0; i < n; i++) cout << prefx[i+1] << " ";
    //cout << "\t";
    cout << bs();
}