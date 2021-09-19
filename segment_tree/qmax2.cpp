// Link https://oj.vnoi.info/problem/qmax2  
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

#define MAX_I 100005
#define ll long long
#define INF 2000000000

int a[MAX_I];
struct Node {
   int val;
   int laz;
} st[4*MAX_I];
int n, m;
int x, y, k;
	
int max(int x,int y) {
	if (x>y) return (x); else return (y);
}
void build(int id, int l, int r) {
   st[id] = {0, 0};
   if (l==r) {
      return;
   }
   int mid = (l+r)/2;
   build(2*id, l, mid);
   build(2*id+1, mid+1, r);
}

void down(int id){
   int t = st[id].laz;
   st[2*id].laz += t;
   st[2*id+1].laz += t;
   st[2*id].val += t;
   st[2*id+1].val += t;

   st[id].laz = 0;
}

void update(int id, int l, int r, int u, int v, int k){
   if (r <u || l >v) return;
   if (u<=l && v>=r) {
      st[id].val += k;
      st[id].laz += k;
      return;
   }
   down(id);

   int mid = (l+r)/2;
   update(2*id, l, mid, u, v, k);
   update(2*id+1, mid+1, r, u, v, k);

   st[id].val = max(st[2*id].val, st[2*id+1].val);
}

int get(int id, int l, int r, int u, int v){
   if (r<u || l>v) return -INF;
   if (u<=l && v>=r) {
      return st[id].val;
   }
   int mid = (l+r)/2;
   down(id);

   return max(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
}
int main(){
   // setUp();
   cin >> n >> m;
   int t;
   while (m--) {
      scanf("%d", &t);
      if (t==0) {
         scanf("%d", &x);
         scanf("%d", &y);
         scanf("%d", &k);
         update(1, 1, n, x, y, k);

      } 
      else {
         scanf("%d", &x);
         scanf("%d", &y);
         printf("%d\n", get(1, 1, n, x, y) );
      }
   }
   return 0;
}
