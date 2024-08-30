#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> multiplication(vector<int> &arr) {
  vector<ll> ans;
  priority_queue<int> pq;

  for (auto num : arr) {
    pq.push(num);
    if (pq.size() >= 3) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      int c = pq.top();
      pq.pop();

      ans.push_back(a * 1ll * b * 1ll * c);
      pq.push(a);
      pq.push(b);
      pq.push(c);
    } else
      ans.push_back(-1);
  }

  return ans;
}
