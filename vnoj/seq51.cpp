// Link   https://oj.vnoi.info/problem/fct020_seq51
#include <bits/stdc++.h>
using namespace std;
void setUp(){
   if(const char* env_p = std::getenv("FILE_BASE_TEMPLATE")) {
        std::cout << "Input to input.txt file\n";
        if (freopen("input.txt", "r", stdin) == NULL)
   {
      cout << env_p << "  ";
      perror("freopen() failed");
    }
   }
}

#define MAX_I 500005
#define ll long long
int n, a[MAX_I];
int dequeue[MAX_I];
int top, bot;

bool check(int k){
   top = -1, bot = 0;
   bool res = false;
   for (int i=1; i<=n; ++i) {
      while (top>=bot && a[dequeue[top]] > a[i]) --top;
      while (top >= bot && i - dequeue[bot] + 1 > k) ++bot;
      dequeue[++top] = i;
      // cout << a[dequeue[bot]] << endl;
      if (i >=k) {
         if (a[dequeue[bot]] >= 1- (i-k+1)) return true;
      }
   }
   return false;
}
int main(){
   setUp();
   cin >>n ;
   for (int i=1; i<=n; ++i){
      cin >> a[i];
      a[i] = a[i] - i;
   }

   int l =1, r= n;
   int mid = (l+r)/2;
   while (l!= mid && r!=mid){
      if (check(mid)) {
         l = mid;
      } else {
         r = mid;
      }
      mid = (l+r)/2;
   }
   cout << mid;
   return 0;
}
