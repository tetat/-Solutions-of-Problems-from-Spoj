/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;

/// quite simple problem
/// find minimum prime factor
/// for up to 1e7 using sieve
/// and now pre calculate answer

vector <long long> d(N+1, 0);

void sieve(){
  for (long long i = 2;i <= N;i += 2){
    d[i] = 2;
  }
  for (long long i = 3;i <= N;i+=2){
    if (!d[i]){
      d[i] = i;
      for (long long j = i*i;j <= N;j+=i+i){
        if (d[j])d[j] = min(d[j], i);
        else d[j] = i;
      }
    }
  }
}

vector <long long> ans(N+1, 0);

void store_ans(){
  for (int i = 2;i <= N;i++){
    ans[i] = ans[i-1] + d[i];
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  sieve();
  store_ans();
//  for (int i = 1;i <= 50;i++){
//    cout << i << ": " << ans[i] << '\n';
//  }
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    cout << ans[n] << '\n';
  }
  return 0;
}

