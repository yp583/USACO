#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
using namespace std;
 
int N, M;
map<int, vector<int>> nbrs;
map<pair<int,int>,double> edgecost;
map<pair<int,int>,double> edgeflow;
vector<int> flows;
 
int dijkstra(int source, int destination, int flowmin)
{
  map<int,int> dist;
  set<pair<int,int>> visited;
  visited.insert(make_pair(0,source));
  while (!visited.empty()) {
    int i = visited.begin()->second;
    visited.erase(visited.begin());
    if (i == destination) return dist[i];
    for (auto j : nbrs[i])
      if (edgeflow[make_pair(i,j)] >= flowmin)
	if (dist.count(j) == 0 || dist[i] + edgecost[make_pair(i,j)] < dist[j]) {
	  dist[j] = dist[i] + edgecost[make_pair(i,j)];
	  visited.insert(make_pair(dist[j],j));
	}
  }
  return -1;
}

int main(void)
{
  cin >> N >> M;
  int i, j, c, f;
  for (int m=0; m<M; m++) {
    cin >> i >> j >> c >> f;
    flows.push_back(f);
    nbrs[i].push_back(j);
    nbrs[j].push_back(i);
    edgecost[make_pair(i,j)] = edgecost[make_pair(j,i)] = c;
    edgeflow[make_pair(i,j)] = edgeflow[make_pair(j,i)] = f;
  }
  long long best_num = 0, best_den = 1, cur_num, cur_den;
  for (int f : flows) {
    cur_num = f;
    cur_den = dijkstra(1, N, f);
    if (cur_den != -1) {
      if (cur_num * best_den > best_num * cur_den) {
	best_num = cur_num; best_den = cur_den;
      }
    }
  }
  cout << best_num * 1000000LL / best_den << "\n";
  cout << best_num << " ";
  cout << best_den;
  return 0;
}