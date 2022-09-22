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
#define INF 9000000000
#define ll long long
#define fr(a,b,c) for(int a=b; a<=c; ++a)
#define frr(a,b,c) for(int a=b; a>=c; --a)
#define arr2DSize 1000
#define f first
#define s second
typedef pair<int, int> pii;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
template <class T>
void print1DArray(T a[], int n){
   cout << a[0];
   fr(i, 1, n-1) cout << "," << a[i];
   cout << endl;
}
template <class T>
void print2DArray(T a[arr2DSize][arr2DSize], int n, int m){
   fr(i, 0, n-1){
      fr(j, 1, m-1){
         cout << setw(4) << a[i][j] << ",";
      }
      cout<< setw(4) << a[i][0];
      cout << endl;
   }
   cout << endl;
}
//////////////////////////////////////////////////////
/////
///// Main
/////
/////////////////////////////////////////////////////


int main(){
   setUp();
   
   tearDown();
   return 0;
}
