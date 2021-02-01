/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

/// find prime numbers up to 1e3
/// marked the numbers m[p*q]
/// this will take n^2 time
/// but don't afraid cause will
/// have taken prime numbers up to 1e3
/// now find the NOD of every numbers
/// up to 1e6

vector <int> p;
bool mark[1001];

void sieve(){
  p.push_back(2);
  for (int i = 3;i <= 1000;i += 2){
    if (mark[i])continue;
    p.push_back(i);
    for (int j = i*i;j <= 1000;j += i+i){
      mark[j] = true;
    }
  }
}

int d[N+1];

void store_div(){
  for (int i = 1;i <= 1000;i++){
    for (int j = i;j <= N;j+=i){
      d[j]++;
      if (j/i != i && j/i > 1000)d[j]++;
    }
  }
}

int m[N+1];

void mark_ans(){
  for (int i = 0;i < p.size();i++){
    for (int j = i+1;j < p.size();j++){
      m[p[i]*p[j]]++;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  sieve();
  store_div();
  mark_ans();
  int cnt = 0;
  for (int i = 1;i <= N;i++){
    if (m[d[i]]){
      cnt = (cnt+1)%9;
      if (cnt==0)cout << i << '\n';
    }
  }
  return 0;
}

