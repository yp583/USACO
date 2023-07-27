#include <bits/stdc++.h>
using namespace std;
int arr[11];
int bit[11] = {0};
int n; 
int maxV = 0;

int lsb(int pos) {
    return pos & -pos;
}

void update(int i, int val){
    if (i < maxV){
        bit[i] += val;
        update((i + lsb(i+1)), val);
    }
}
int sum(int i){
    if (i > 0){
        return bit[i-1]+sum(i-lsb(i));
    }
    else{
        return 0;
    }
}

int main(){
    cin >> n;
    int inversions = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]+1;
        if (maxV < arr[i]){
            maxV = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        update(arr[i]-1, 1);
        inversions += i+1 - sum(arr[i]);

    }
    cout << inversions << "\n";
    //for(auto b: bit) cout << b << " ";
}