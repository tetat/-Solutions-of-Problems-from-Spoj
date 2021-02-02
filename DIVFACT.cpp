/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

/// find the largest power of every
/// prime that is less or equal to n
/// using legendre's formula
/// then simply compute NOD

vector <int> p;
bool mark[N*5 + 1];

void sieve(){
  p.push_back(2);
  for (long long i = 3;i <= N*5;i+=2){
    if (mark[i])continue;
    p.push_back(i);
    for (long long j = i*i;j <= N*5;j+=i+i){
      mark[j] = true;
    }
  }
}

int power(int n, int p){
  int ret = 0;
  int pp = p;
  while (n/pp){
    ret += n/pp;
    pp *= p;
  }
  return ret+1;
}

long long mod = 1e9 + 7;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  sieve();
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 0;i < p.size() && p[i] <= n;i++){
      ans = (ans * power(n, p[i])) % mod;
    }
    cout << ans << '\n';
  }
  return 0;
}

