// Link   https://oj.vnoi.info/problem/vsteps
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
#define MOD 14062008

int main(){
   setUp();
   int n, k, t;
   int a[MAX_I], s[MAX_I];

   cin >> n >> k;
   for (int i =0; i <=n ;++i) {
      a[i] = 0;
      s[i] = 0;
   }
   for (int i = 1; i <= k; ++i) {
      cin >> t;
      a[t] = 1;
   }
   s[1] =1 ;
   for (int i=2; i <= n; ++i){
      if (!a[i]) {
         if (s[i-1]) {
            s[i] = (s[i]+s[i-1])%MOD;
         }
          if (s[i-2]) {
            s[i] = (s[i]+s[i-2])%MOD;
         }
      }
      // cout << i << " " << s[i]<< "\n";
   }
   cout << s[n];
   return 0;
}
