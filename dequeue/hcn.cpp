// Link   https://oj.vnoi.info/problem/qbrect
#include <bits/stdc++.h>
#define MAX_I 1001
#define ll long long
using namespace std;
int mat[MAX_I][MAX_I];
int w[MAX_I][MAX_I];
int m, n;
int q[MAX_I];
int l[MAX_I], r[MAX_I];
int top, bot;
int r1, l1, rr1;
int main(){
   cin >> m >> n;
   for (int i =0; i<m; ++i) {
      for (int j =0; j <n; ++j) {
         cin >> mat[i][j];
      }
   }
   for (int i=0; i<m; ++i)
      for (int j =n-1; j>=0; --j){
         w[i][j] = mat[i][j]? w[i][j+1]+1: 0;
      }

   // cout << endl;
   // for (int i =0; i<m; ++i) {
   //    for (int j =0; j <n; ++j) {
   //       cout << w[i][j] <<  " ";
   //    }
   //    cout << endl;
   // }

   int res = 0;
   for (int j=0; j<n; ++j){
      top = -1, bot = 0;
      for (int i= 0; i<m ; ++i){
         while(top>=bot && w[q[top]][j] >= w[i][j]) --top;
         l[i] = top>=bot? q[top]:-1;
         q[++top] = i;
      }

      top = -1, bot = 0;
      for (int i= m-1; i>=0 ; --i){
         while(top>=bot && w[q[top]][j] >= w[i][j]) --top;
         r[i] = top>=bot? q[top]:m;
         q[++top] = i;
      }

      for (int i=0; i<m; ++i) {
         // if (res < w[i][j]*(r[i]-l[i]-1)){
         //    l1 = l[i];
         //    r1 = r[i];
         //    rr1 = w[i][j];
         // }
         res = max(res, w[i][j]*(r[i]-l[i]-1));
         // if (j==2) cout << "        trace  " << l[i] << "  " << r[i] << " " << w[i][j] << endl; 
      }
      // cout << "  trace  " << l1 << "  " << r1 << " " << rr1 << endl; 
   }
   cout << res;
   // cout << "  trace  " << l1 << "  " << r1 << " " << rr1 << endl; 
   return 0;
}
