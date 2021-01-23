/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

/// if a is co-prime with b
/// then it doesn't matter the value of c
/// ax+by = c (c can be any number)
/// other-wise gcd(a, b) must be divide c

int gc(int a, int b){
  if (b==0)return a;
  return gc(b, a%b);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  cin >> T;
  while (T--){
    int a, b, c;
    cin >> a >> b >> c;
    cout << "Case " << ++ca << ": ";
    if (c%gc(a, b)==0)cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}
