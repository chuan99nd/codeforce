// Link   https://oj.vnoi.info/problem/kplank
#include <bits/stdc++.h>
#define MAX_I 1000005
#define ll long long
using namespace std;
int a[MAX_I];
int q[MAX_I];
int top, bot;
int n, l[MAX_I], r[MAX_I];
int main(){
   int T = 1;
   while(T--){
      cin >> n;
      for (int i= 0; i<n; ++i){
         cin>> a[i];
      }

      top=-1, bot=0;
      for (int i=0; i<n; ++i) {
         while(top>=bot && a[q[top]] >= a[i]) --top;
         l[i] = top>=bot? q[top]: -1;
         q[++top] = i;
      }
      top=-1, bot=0;
      for (int i=n-1; i>= 0; --i) {
         while(top>=bot && a[q[top]] >= a[i]) --top;
         r[i] = top>=bot? q[top]: n;
         q[++top] = i;
      }
      int res = 0;
      for (int i=0; i<n; ++i){
          if (r[i]-l[i]-1 < a[i]) continue;
         int ss = min(a[i], (r[i]-l[i]-1));
         // cout << ss<<endl;
         if (res < ss){
            res = ss;
         }
      }
      cout << res;
   }
   return 0; 
}
