// Link   https://codeforces.com/problemset/problem/280/B
#include <bits/stdc++.h>
#define MAX_I 500005
#define ll long long
using namespace std;
int n;
int s[MAX_I];
void input(){
   cin >> n;
   for (int i =0; i<n; ++i){
      cin >> s[i];
   }
}

int solve(){
   stack<int> st;
   int l[MAX_I], r[MAX_I];
   for (int i=0; i<n; ++i){
      while (!st.empty() && s[st.top()] < s[i]){
         st.pop();
      }
      l[i] = st.empty() ? -1: st.top();
      st.push(i);
   }
   stack<int> sst;
   for (int i=n-1; i>=0; --i){
      while(!sst.empty() && s[sst.top()] < s[i]) {
         sst.pop();
      }
      r[i] = sst.empty() ? -1: sst.top();
      sst.push(i);
   }

   int res = 0;
   for (int i=0; i<n; ++i){
      if (l[i] >= 0) res = max(res, s[l[i]] ^ s[i]);
      if (r[i] >=0) res = max(res, s[r[i]] ^ s[i]);
   }
   return res;
}
int main(){
   input();
   cout << solve() << endl;
   return 0; 
}