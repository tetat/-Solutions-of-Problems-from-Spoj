/// https://www.spoj.com/problems/INVCNT/

/**
 *  winners never quit
**/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

/// this problem solved with the idea of merge sort
/// while sorting the array
/// you just need to count
/// how many move need an element to move right (line 39)
/// total number number of move of all element
/// is the total number of inversion of this array

vector <int> aa(N+N);
long long ans = 0;

void Merge(int b1, int e1, int b2, int e2){
  vector <int> a, b;
  for (int i = b1;i <= e1;i++){
    a.push_back(aa[i]);
  }
  for (int i = b2;i <= e2;i++){
    b.push_back(aa[i]);
  }
  vector <int> r;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  while (a.size() || b.size()){
    if (a.size() && b.size()){
      if (a.back() < b.back()){
        r.push_back(a.back());
        a.pop_back();
      }else {
        r.push_back(b.back());
        b.pop_back();
        ans += a.size();
      }
    }else {
      while (a.size()){
        r.push_back(a.back());
        a.pop_back();
      }
      while (b.size()){
        r.push_back(b.back());
        b.pop_back();
      }
    }
  }
  for (int i = b1, j = 0;i <= e2;i++, j++){
    aa[i] = r[j];
  }
}

pair <int, int> dc(int b, int e){
  if (b==e){
    return {b, e};
  }
  int mid = b + (e-b)/2;
  pair <int, int> r1 = dc(b, mid);
  pair <int, int> r2 = dc(mid+1, e);
  Merge(r1.first, r1.second, r2.first, r2.second);
  return {r1.first, r2.second};
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, ca = 0;
  cin >> T;
  while (T--){
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
      cin >> aa[i];
    }
    dc(0, n-1);
    cout << ans << '\n';
    ans = 0;
  }
  return 0;
}
