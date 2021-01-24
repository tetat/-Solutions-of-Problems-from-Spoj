/// https://www.spoj.com/problems/COMDIV/

/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

/// Assume x is greatest common divisor of A & B
/// if x is divide both A & B then divisors of
/// x must be divide both A & B also
/// so, the solution is NOD(__gcd(A, B))

int di[N+1];

void init(){
  for (int i = 1;i <= 1000;i++){
    for (int j = i;j <= N;j+=i){
      di[j]++;
      if (j/i > 1000 && j/i != i)di[j]++;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  init();
  cin >> T;
  while (T--){
    int a, b;
    cin >> a >> b;
    cout << di[__gcd(a, b)] << '\n';
  }
  return 0;
}

