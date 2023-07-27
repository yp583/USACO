#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int n;
bool grid[1000][1000];
int neighbors[1002][1002] = {0};
bool added[1002][1002] = {false};

vector<pair<int, int>> nswe = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int ans = 0;

void rec(int x, int y){
    grid[x][y] = true;
    for (int j = 0; j < 4; j++)
    {
            int nx = x + nswe[j].f + 1;
            int ny = y + nswe[j].s + 1;
            neighbors[nx][ny]++;
            //cout << neighbors[nx][ny] << " ";
            if (grid[nx-1][ny-1]){
                if (neighbors[nx][ny] == 3){
                    ans++;
                    added[nx][ny] = true;
                    rec(nx-1, ny-1);
                }
                else if(!added[nx][ny] && neighbors[nx][ny] == 4){
                    ans--;
                }
                cout << added[nx][ny];
            }
    }
    //cout << "\n";
}

int main(){
    cin >> n;
    int ansarr[n+1] = {0};
    for (int i = 1; i < n+1; i++)
    {
        int x, y; cin >> x >> y;
        //grid[x][y] = true;
        rec(x, y);
        ansarr[i] = ans;
    }
    for(auto a: ansarr) cout << a << "\n";
    /*
    for (int i = 0; i < 6; i++)
    {
         for (int j = 0; j < 6; j++)
        {
            cout << neighbors[i][j] << " ";
        }
        cout << "\n";
    }
    */
}