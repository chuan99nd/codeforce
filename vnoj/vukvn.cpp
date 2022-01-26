// Link   https://oj.vnoi.info/problem/vukvn
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
#define f first
#define s second
typedef pair<int, int> pii;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
   setUp();
   int n, m;
   queue<pii> q;
   pii start, end;
   int dist[600][600];
   cin >> n >> m;
   char k;
   fr(i, 0, n){
      fr(j,0, m){
         dist[i][j] = MAX_I;
         cin >> k;
         if (k == '+') q.push({i,j}), dist[i][j] = 0;
         if (k == 'V') start = {i,j};
         if (k == 'J') end = {i,j};
      }
   }

   // Get distance from + 
   while (!q.empty()) {
      auto p = q.front();
      q.pop();
      auto i = p.f, j = p.s;
      fr(a, 0, 3) {
         int dyy = i + dy[a], dxx = j + dx[a];
         if (dyy >= 0 && dyy < n && dxx >= 0 && dxx < m && dist[dyy][dxx] <  dist[i][j]+1) {
            dist[dyy][dxx] = dist[i][j] + 1;
            q.push({dyy, dxx});
         }
      }
   }

   // binary search
   int s = 0, e = 500;
   tearDown();
   return 0;
}
