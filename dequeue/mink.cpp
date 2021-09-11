// Link   https://vnoi.info/wiki/algo/data-structures/deque-min-max.md
#include <bits/stdc++.h>
#define MAX_I 500005
#define ll long long
using namespace std;
int a[MAX_I], n, k;
int q[MAX_I];
int main(){
   int T;
   cin >> T;
   while (T--){
      cin >> n >> k;
      int top = -1, bot = 0;
      for (int i =0; i<n; ++i){
         cin >> a[i];
         while(top>=bot && a[q[top]] >= a[i]) top--;
         if (top >= bot && i - q[bot] + 1 > k) ++bot;
         q[++top] = i;
         if (i>=k-1) cout << a[q[bot]] << " ";
      }
      cout << endl;
   }
   return 0; 
}
