#include <bits/stdc++.h>
using namespace std;

int lsb(int pos) {
    return pos & -pos;
}
int main(){
    int t; cin>>t;
    cout << lsb(t);
}