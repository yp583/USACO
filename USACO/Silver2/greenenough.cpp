#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int grid[500][500];

    int xl = n+1;
    int yl = n+1;
    int xm = 0;
    int ym = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int proc = 0;
            int t; cin >> t;
            if (t < 100){
                grid[i][j] = 0;
            }
            else if (t > 100){
                grid[i][j] = 1;
                xl = min(xl, i);
                yl = min(yl, j);
                xm = max(xm, i);
                ym = max(ym, j);
            }
            else{
                grid[i][j] = 2;
            }
        } 
    }
    int xs = xm - xl + 1;
    int ys = ym - yl + 1;
    


    
    

    /*
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    */
}