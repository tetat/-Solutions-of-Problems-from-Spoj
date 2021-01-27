/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

/// this is quite strait forward problem
/// It can solve with prime factorizations

void get_len(){
  freopen("output.txt", "w", stdout);
  long long n = 1e15;
  long long r = 1e8;
  long long l = 1;
  long long root;
  while (l <= r){
    long long mid = l + (r-l)/2;
    if (mid*mid <= n){
      root = mid;
      l = mid+1;
    }else r = mid-1;
  }
  cout << root << '\n';
}

const long long NN = 31622776;

vector <long long> prime;
bool mark[NN+1];

void sieve(){
  prime.push_back(2);
  for (long long i = 3;i <= NN;i += 2){
    if (mark[i])continue;
    prime.push_back(i);
    for (long long j = i*i;j <= NN;j += i+i){
      mark[j] = true;
    }
  }
}

void solve(long long n){
  if (n==1){
    cout << "2^0" << '\n';
    return;
  }
  map <long long, int> m;
  for (int i = 0;i < prime.size() && prime[i]*prime[i] <= n;i++){
    int cnt = 0;
    while (n%prime[i]==0){
      n /= prime[i];
      cnt++;
    }
    if (cnt)m[prime[i]] = cnt;
  }
  if (n > 1)m[n] = 1;
  for (map <long long, int>::iterator it = m.begin();it != m.end();it++){
    cout << it->first << "^" << it->second << ' ';
  }cout << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  //get_len();
  sieve();
  long long n;
  while (cin >> n && n){
    solve(n);
  }
  return 0;
}

