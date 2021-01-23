/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

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
