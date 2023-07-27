#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

bool cmps(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.f.s < b.f.s;
}
bool cmpf(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.f.f < b.f.f;
}

int main(){
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> no;
    vector<pair<pair<int, int>, int>> ea;
    int blame[1000] = {0};
    for (int i = 0; i < n; i++)
    {
        char d; int x, y; cin >> d >> x >> y;
        if (d == 'E'){
            ea.push_back({{x, y}, i});
        }
        else{
            no.push_back({{x, y}, i});
        }
    }
    int nos = no.size();
    int eas = ea.size();
    sort(begin(no), end(no), cmpf);
    sort(begin(ea), end(ea), cmps);
    for (int i = 0; i < nos; i++)
    {
        pair<int, int> cno = no[i].f;
        for (int j = 0; j < eas; j++)
        {
            pair<int, int> cea = ea[j].f;
            //cout << cno.f << " ";
            if (cea.f < cno.f && cea.s > cno.s){
                int dx = cno.f - cea.f;
                int dy = cea.s - cno.s;
                //cout << dx << " " << dy << "\n";
                if (dx < dy){
                    blame[ea[j].s]+=blame[no[i].s]+1;
                    break;
                }
                else if(dy < dx){
                    blame[no[i].s]+=blame[ea[j].s]+1;
                }
            }
        }
    }
    //for(auto noo: ea) cout << noo.f.f << ":" << noo.f.s << " ";
    for (int i = 0; i < n; i++)
    {
        cout << blame[i] << "\n";
    }
    
}