#include <bits/stdc++.h>
using namespace std;

int grid[251][251];
bool visited[251][251] = {false};
bool visited2[251][251] = {false};
int n;
int nswe[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int areas[251];
int twoareas[251][251];

int floodfill(int x, int y, vector<int> val){
    int area = 1;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int xn = x+nswe[i][0]; int yn = y+nswe[i][1];
        if (!(xn < 0 || yn < 0 || xn > n-1 || yn > n-1)){
            //cout << grid[xn][yn] << " ";
            if (!visited[xn][yn]){
                if (grid[xn][yn] == val[0]){
                    area += floodfill(xn, yn, val);
                }
                if (val.size() == 2 && grid[xn][yn] == val[1]){
                    area += floodfill(xn, yn, val);
                }
                //cout << val.size();
            }
        }
    }
    return area;
}

int combinefloodfill(int x, int y){
    int val = grid[x][y];


}

int main(){
    int maxonearea=0;
    int maxtwoarea = 0;
    //freopen("multimoo.in", "r", stdin); freopen("multimoo.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];           
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j]){
                int a = floodfill(i, j, {grid[i][j]});
                cout << a << " " << grid[i][j];
                areas[grid[i][j]] = a;
                if (a > maxonearea){
                    maxonearea = a;
                }

            }
        }
    }
    //for(auto a: areas) cout << a << " ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int xn = i+nswe[k][0]; int yn = j+nswe[k][1];
                if (!(xn < 0 || yn < 0 || xn > n-1 || yn > n-1) && grid[i][j] != grid[xn][yn]){
                    int a = areas[grid[i][j]] + areas[grid[xn][yn]];
                    if (a > maxtwoarea){
                        maxtwoarea = a;
                    }
                }
            }
        }
    }
    cout << maxonearea << "\n" << max(maxtwoarea, maxonearea);
    
}