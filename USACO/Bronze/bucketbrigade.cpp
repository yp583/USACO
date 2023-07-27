#include <iostream>
using namespace std;
int n = 0;
char farm[10][10];
int b[2], r[2], l[2];
int ans = 0;
//largest substring that appears twice
int main() {
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> farm[i][j];
            if (farm[i][j] == 'L'){
                l[0] = i;
                l[1] = j;
            }
            else if (farm[i][j] == 'R'){
                r[0] = i;
                r[1] = j;
            }
            else if (farm[i][j] == 'B'){
                b[0] = i;
                b[1] = j;
            }
        }
    }
    ans = abs(b[0]-l[0]) + abs(b[1] - l[1])-1;
    if (b[0] == l[0] || b[1] == l[1]){
        ans += 2;
    }
    cout<<ans;
    


    
    
}