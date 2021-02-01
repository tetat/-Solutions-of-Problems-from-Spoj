/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

/// store all the divisors of n
/// in n-th pos in 2d vector
/// the size of any pos will
/// NOD of that pos
/// now calculations is
/// quite brute force

vector <vector <int> > d(N+1);

void NOD_Div(){
  for (int i = 1;i <= 1000;i++){
    for (int j = i;j <= N;j+=i){
      d[j].push_back(i);
      if (j/i > 1000 && j/i != i){
        d[j].push_back(j/i);
      }
    }
  }
}

bool ans[N+1];

void mark_ans(){
  for (int i = 1;i <= N;i++){
    int len = d[i].size();
    if (len > 2){
      int ad = 1;
      for (int j = 0;j < len;j++){
        if (len % d[d[i][j]].size()){
          ad = 0;
          break;
        }
      }
      ans[i] = ad;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  NOD_Div();
  mark_ans();
  int cnt = 0;
  for (int i = 1;i <= N;i++){
    if (ans[i]){
      cnt = (cnt+1)%108;
      if (cnt==0)cout << i << '\n';
    }
  }
  return 0;
}

