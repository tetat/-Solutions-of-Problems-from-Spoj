/// https://www.spoj.com/problems/DIVSUM/

/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

/// store sum of divisors of all the numbers
/// using the idea of sieve

vector <int> sum(N*5+1, 0);

void make(){
  int lim = sqrt(N+N+N+N+N);
  for (int i = 1;i <= N*5;i++){
    for (int j = i+i;j <= N*5;j+=i){
      sum[j] += i;
      //if (j > lim && (j/i) != i)sum[j] += j/i;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  make();
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    cout << sum[n] << '\n';
  }
  return 0;
}
