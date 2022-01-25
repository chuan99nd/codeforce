// Link https://oj.vnoi.info/problem/vratf 
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

int main(){
   setUp();
   int n, k, kount = 0;
   cin >> n >> k;
   stack<int> s;
   s.push(n);
   while (!s.empty())    {
      int t = s.top();
      s.pop();
      if (t <= k || (t-k)%2) {
         // cout << t;
         ++kount ;
         continue;
      }
      s.push((t-k)/2);
      s.push((t+k)/2);
   }
   cout << kount;
   return 0;
}
