// Link https://www.spoj.com/PTIT/problems/SSAM219G/
#include <bits/stdc++.h>
#define MAX_I 100005

using namespace std;
long long h[MAX_I];
long long n;
long long l[MAX_I], r[MAX_I];
long long solve(){
   stack<long long>  s;
   for (long long i=0; i<n; ++i){
      while(!s.empty() && h[s.top()] >= h[i]){
         s.pop();
      }
      l[i] = s.empty()? 0: s.top()+1;
      s.push(i);
   }
   stack<long long> ss;
   for (long long i=n-1; i>=0; --i){
      while(!ss.empty() && h[ss.top()] >= h[i]){
         ss.pop();
      }
      r[i] = ss.empty() ? n-1: ss.top()-1;
      ss.push(i);
   }
   
   long long rs = 0;
   for (long long i=0; i<n; ++i){
      rs = max(rs, h[i]*(r[i]-l[i]+1));
      // cout << i << " " << l[i] << " " << r[i] << endl;
   }
   return rs;
}
int main(){
   long long T;
   cin >> T;
   while (T--){
      cin >> n;
      for (int i=0; i < n; ++i){
         cin >> h[i];
      }
      cout << solve() << endl;
   }
   return 0; 
}