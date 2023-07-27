#include <iostream>
using namespace std;
int n, m, k;
int rules[101][2];
int cows[10001];

int main(){
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cows[i] = i+1; //1 indexed
    }
    for (int i = 0; i < m; i++)
    {
        cin >> rules[i][0] >> rules[i][1];
        rules[i][0] --;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int len = rules[j][1] - rules[j][0];
            int temp[10001];
            for (int l = len-1; l >= 0; l--)
            {
                temp[l] = cows[rules[j][0]+(len-1-l)];
            }
            for (int l = 0; l < len; l++)
            {
                cows[rules[j][0]+l] = temp[l];
            }          
        }    
    }

    //output
    for (int i = 0; i < n-1; i++)
    {
        cout << cows[i];
        cout << '\n';
    }
    cout << cows[n-1];
}