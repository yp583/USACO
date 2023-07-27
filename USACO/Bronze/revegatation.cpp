//code for solution
#include <iostream>
#include <fstream>
using namespace std;
 
int main(void)
{
  int N, M;
  int A[151], B[151], G[101] = {0};
  cin >> N >> M;
  for (int i=0; i<M; i++) { 
    cin >> A[i] >> B[i];
    if (A[i] > B[i]) swap(A[i], B[i]);
  }
  /*
  cout << "\n";
  for (int i = 0; i < M; i++)
  {
     cout << A[i] << ":" << B[i] << "\n";
  }*/
  
  for (int i=1; i<=N; i++) {//every node
    int g;
    for (g = 1; g <= 4; g++) {//every grass type
      bool ok = true;
      for (int j=0; j<M; j++) {//every edge
        cout << "G[A[j]]: " << G[A[j]] << " g: " << g << " i: " << i << " j: " << j << "\n";
        if (B[j] == i && G[A[j]] == g) {
            ok = false;
        }
      }
      if (ok) {
        break;
      }
    }
    G[i] = g;
    cout << g;
  }
  cout << "\n";
  return 0;
}