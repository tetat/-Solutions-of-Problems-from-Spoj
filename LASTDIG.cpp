/// https://www.spoj.com/problems/LASTDIG/

/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

/// find a to the power of b with modulo 10
/// using bigmod algorithm

int ans(int b, long long p, int mod){
  if (p==0)return 1%mod;
  if (p%2)return (ans(b, p-1, mod) * b) % mod;
  else {
    int x = ans(b, p/2, mod);
    return (x * x) % mod;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  cin >> T;
  while (T--){
    long long a, b;
    cin >> a >> b;
    cout << ans(a, b, 10) << '\n';
  }
  return 0;
}
