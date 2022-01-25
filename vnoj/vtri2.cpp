// Link   
#include <bits/stdc++.h>
using namespace std;

clock_t tStart;
void setUp(){
   if(const char* env_p = std::getenv("FILE_BASE_TEMPLATE")) {
      std::cout << "Input to input.txt file\n";
      tStart = clock();
      if (freopen("input.txt", "r", stdin) == NULL) {
         cout << env_p << "  ";
         perror("freopen() failed");
      }
   }
}
void tearDown(){
   if(const char* env_p = std::getenv("FILE_BASE_TEMPLATE")) {
      clock_t tEnd = clock();
      printf("\nTime take: %.2fs\n", (double) (tEnd - tStart)/CLOCKS_PER_SEC);
   }
}
#define MAX_I 500005
#define ll long long
#define fr(a,b,c) for(int a=b; a<=c; ++a)
#define frr(a,b,c) for(int a=b; a>=c; --a)

int main(){
   setUp();

   tearDown();
   return 0;
}
