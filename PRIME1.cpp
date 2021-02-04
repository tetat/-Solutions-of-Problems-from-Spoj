/// https://www.spoj.com/problems/PRIME1/

/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

/// this problem is about segment sieve
/// you need to generate all prime up to
/// sqrt(R) then just mark the multiple
/// primes and you need to careful about
/// current prime is less or greater to L

int sqrtn(int L, int R, int n){
  int ret;
  while (L <= R){
    long long mid = L + (R-L)/2;
    if (mid*mid <= n){
      ret = mid;
      L = mid+1;
    }
    else {
      R = mid-1;
    }
  }
  return ret;
}

vector <int> prime;
bool mark[N+5];

void sieve(){
  int len = sqrtn(1, 100000, 2147483647);
  int lim = sqrtn(1, len, len);

  prime.push_back(2);

  for (int i = 3;i <= len;i += 2){
    if (mark[i] == false){
      prime.push_back(i);
      if (i <= lim){
        for (int j = i*i;j <= len;j += i+i){
          mark[j] = true;
        }
      }
    }
  }
}

void seg_sieve(int L, int R){
  int len = (R-L)+1;
  for (int i = 0;i <= len;i++){
    mark[i] = false;
  }
  for (int i = 0;i < prime.size() && prime[i]*prime[i] <= R;i++){
    int j = prime[i]+prime[i];
    if (j < L)j = (L+prime[i]-1)/prime[i] * prime[i];
    for ( ;j <= R;j += prime[i]){
      mark[j-L] = true;
    }
  }
  for (int i = 0;i < len;i++){
    if (mark[i]==false && i+L != 1){
      cout << i+L << '\n';
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  cin >> T;
  sieve();
  while (T--){
    int L, R;
    cin >> L >> R;
    seg_sieve(L, R);
    if (T)cout << '\n';
  }
  return 0;
}

