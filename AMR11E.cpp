/// https://www.spoj.com/problems/AMR11E/

/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

/// limit is quite small
/// you can solve it with brute force
/// the idea of this solution is
/// increase the positions that are divisible
/// by prime numbers
/// take the positions if it has more than 2
/// divisors

bool mark[1001];
vector <int> p;

void sieve(){
  p.push_back(2);
  for (int i = 3;i <= 1000;i += 2){
    if (!mark[i]){
      p.push_back(i);
      for (int j = i*i;j <= 1000;j += i+i){
        mark[j] = true;
      }
    }
  }
}

vector <int> pd(N+1, 0);

void make(){
  for (int i = 0;i < p.size();i++){
    for (int j = p[i];j <= N;j += p[i]){
      pd[j]++;
    }
  }
}

vector <int> ans;

void store(){
  for (int i = 1;i <= N;i++){
    if (pd[i] > 2)ans.push_back(i);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  sieve();
  make();
  store();
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    cout << ans[n-1] << '\n';
  }
  return 0;
}
