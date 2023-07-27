#include <bits/stdc++.h>
using namespace std;

int grid[251][251];
bool visited[251][251] = {false};
int n;
int nswe[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

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

int main(){
    int maxonearea=0;
    int maxtwoarea = 0;
    vector<int> ids;
    //freopen("multimoo.in", "r", stdin); freopen("multimoo.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            bool add = true;
            for (int k = 0; k < ids.size(); k++)
            {
                if (ids[k] == grid[i][j]){
                    add = false;
                }
            }
            if (add){
                ids.push_back(grid[i][j]);
            }
            
        }
    }
    //for(auto id : ids) cout << id << " ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j]){
                int a = floodfill(i, j, {grid[i][j]});
                if (a > maxonearea){
                    maxonearea = a;
                }
            }
        }
    }
    for (int k = 0; k < ids.size(); k++)
    {
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (!visited[i][j]){
                    if (grid[i][j] != ids[k]){
                        int a = floodfill(i, j, {grid[i][j], ids[k]});
                        if (a > maxtwoarea){
                            maxtwoarea = a;
                        }
                    }
                }
            }
        }
    }
    cout << maxonearea << "\n" << max(maxtwoarea, maxonearea);
    
}