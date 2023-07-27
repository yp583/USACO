#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
    map<int, vector<int>> origindex;
    int n; cin>>n; 
    int arr[n];
    int org[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        origindex[arr[i]].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        for(auto i: origindex[arr[i]]) cout << i << " "; cout << "\t";
    }
    

    sort(arr, arr+n);
    int maxdist = 0;
    //cout << arr[1];
    for (int i = 0; i < n; i++)
    {
        int dist = 0;
        if (i == 1){
            cout << origindex[arr[i]][0]<< " ";
        }
        if (origindex[arr[i]][0] - i != 0){
            dist = max(origindex[arr[i]][0] - i, 1);
            if (maxdist < dist){
                maxdist = dist;
            }
            origindex[arr[i]].erase(origindex[arr[i]].begin());
            //for(int id : origindex[arr[i]])cout << arr[i] << ":" << id << " ";
        }
    }
    cout << maxdist + 1;
    
}