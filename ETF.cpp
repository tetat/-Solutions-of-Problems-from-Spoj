/// https://www.spoj.com/problems/ETF/

/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

/// just store phi value of all number
/// to modifying phi function like sieve

vector <int> ans(N+1);

void phi(){
  for (int i = 1;i <= N;i++){
    ans[i] = i;
  }
  for (int i = 2;i <= N;i++){
    if (ans[i]==i){
      for (int j = i;j <= N;j += i){
        ans[j] /= i;
        ans[j] *= (i-1);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  cin >> T;
  phi();
  while (T--){
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }
  return 0;
}
