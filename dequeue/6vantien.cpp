// Link   https://oj.vnoi.info/problem/kagain
#include <bits/stdc++.h>
#define MAX_I 500005
#define ll long long
using namespace std;
int a[MAX_I];
int q[MAX_I];
int top, bot;
int n, l[MAX_I], r[MAX_I];
int main(){
   int T;
   cin >> T;
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
      int l1, r1;
      int res = 0;
      for (int i=0; i<n; ++i){
         int ss = a[i]*(r[i]-l[i]-1);
         // cout << ss<<endl;
         if (res < ss){
            l1 = l[i];
            r1= r[i];

            res = ss;
         }
      }
      printf("%d %d %d\n", res, l1+2, r1);
   }
   return 0; 
}
