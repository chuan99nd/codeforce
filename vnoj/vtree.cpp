// Link  https://oj.vnoi.info/problem/vtri 
#include <bits/stdc++.h>
using namespace std;

clock_t tStart;
void setUp(){
   if(const char* env_p = std::getenv("FILE_BASE_TEMPLATE")) {
        std::cout << "Input to input.txt file\n";
        if (freopen("input.txt", "r", stdin) == NULL)   {
      cout << env_p << "  ";
      perror("freopen() failed");
    }
   }
}

void tearDown(){
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
#define fr(a,b,c) for(int a=b; a<=c; ++a)
#define frr(a,b,c) for(int a=b; a>=c; --a)

// idea: cos(a-b) = sin(a)cos(b) + sin(b)cos(a)
// a(i,j), b(u,v),
// sin(a) = j/|a|, sin(b) = v/|b|
// cos(a) = i/|a|, cos(b) = u/|b|
// s = |(j*u + i*v)|/2
int main(){
   setUp();
   int x, y, S, kount;
   kount = 0;
   cin >> x >> y >> S;
   fr(i, 0, x){
      fr(j, -y, y){
         fr(u, 0, x){
            fr(v, -y, y){
               if (i == 0 && j > 0) continue;
               if (u==0 && v > 0) continue;
               int s = (j*u - i*v);
               if (s%2) continue;
               if (s < 0) s = -s;
               s = s/2;
               int maxHeight = max(max(abs(v), abs(j)), abs(v-j));
               int maxLength = max(abs(i), abs(u));
               if (maxHeight <= y && s == S) {
                  // printf("%d %d %d %d %d %d \n", i, j, u, v, maxHeight, maxLength);
                  int b = (y-maxHeight+1)*(x-maxLength+1);
                  // cout << sqrt(i*i +j*j) << " " << sqrt(u*u + v*v) << endl;
                  kount += (y-maxHeight+1)*(x-maxLength+1);
               }
            }
         }
      }
   }
   cout  <<kount/2;
   return 0;
}
