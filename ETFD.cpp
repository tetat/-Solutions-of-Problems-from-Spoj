/// https://www.spoj.com/problems/ETFD/

/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

/// this problem solved with phi function & dp
/// first make phi of every number 1 to 1e6
/// now store answer using dp

int ph[N+1];

void make_phi(){
  for (int i = 1;i <= N;i++){
    ph[i] = i;
  }
  for (int i = 2;i <= N;i++){
    if (ph[i] == i){
      for (int j = i;j <= N;j += i){
        ph[j] /= i;
        ph[j] *= (i-1);
      }
    }
  }
}

int frq[N+1];

void find_freq(){
  int mx = 0;
  for (int i = 2;i <= N;i++){
    frq[i] = frq[ph[i]] + 1;
    mx = max(mx, frq[i]);
  }
  //cout << mx << '\n';
}

int ans[21][N+1];

void store_ans(){
  for (int i = 1;i <= N;i++){
    ans[frq[i]][i]++;
  }
  for (int i = 0;i < 21;i++){
    for (int j = 1;j <= N;j++){
      ans[i][j] += ans[i][j-1];
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  make_phi();
  find_freq();
  store_ans();
  cin >> T;
  while (T--){
    int n, m, k;
    cin >> n >> m >> k;
    cout << ans[k][m]-ans[k][n-1] << '\n';
  }
  return 0;
}
