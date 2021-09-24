// Link    http://codeforces.com/group/FLVn1Sc504/contest/315912/problem/A
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

#define MAX_I 200005
#define ll long long
int n, a[MAX_I];

void input(){
   scanf("%d", &n);
   for (int i = 1; i<=n; ++i) {
      scanf("%d", &a[i]);
   }
}

void reset(int lazy[]){
   for (int i = 1; i<= 100; ++i){
      lazy[i] = i;
   }
}
void printArr(int arr[]) {

}
struct Node {
   int lazy[100];
} st[4*MAX_I];

void build(int id, int l, int r){
   reset(st[id].lazy);
   if (l==r) {
      return;
   }
   int mid = (l+r)/2;
   build(2*id, l, mid);
   build(2*id+1, mid+1, r);
}

void apply(int target[], int op[]){
   for (int i=1; i<=100; ++i){
      target[i] = op[target[i]];
   }
}

void down(int id, int l, int r) {
   if (l==r) return;
   auto f = st[id].lazy;
   apply(st[2*id].lazy, f);
   apply(st[2*id+1].lazy, f);
   
   reset(st[id].lazy);
}

void update(int id, int l, int r, int u, int v, int x, int y){
   if (r <u || l >v) return;
   if (u<=l && r<=v) {
      auto l = st[id].lazy;
      for (int i=1; i<=100; ++i){
         if (l[i]==x) l[i] =y;
      }
      return;
   }
   down(id, l, r);
   int mid = (l+r)/2;
   update(2*id, l, mid, u, v,x, y);
   update(2*id+1, mid+1, r, u,v, x, y);
}

int res[MAX_I];
void finalUpdate(int id, int l, int r) {
   if (l==r){
      res[l] = st[id].lazy[a[l]];
      return;
   }
   int mid = (l+r)/2;
   down(id, l, r);
   finalUpdate(2*id, l, mid);
   finalUpdate(2*id+1, mid+1, r);
}


int main(){
   setUp();
   input();
   build(1, 1, n);
   int q;
   scanf("%d", &q);
   int u, v, x, y;
   while(q--){
      scanf("%d %d %d %d", &u, &v, &x, &y);
      update(1, 1, n, u, v, x, y);
   }
   finalUpdate(1, 1, n);
   for (int i=1; i<=n; ++i){
      printf("%d ", res[i]);
   }

   return 0;
}
