// Link  https://codeforces.com/contest/380/problem/C
#include <bits/stdc++.h>
#define MAX_I 1000005
#define ll long long
using namespace std;
struct Node {
   int left = 0;
   int right = 0;
   int val = 0;
   Node(int l, int r, int v){
      left = l;
      right = r;
      val = v;
   };
   Node(){
   }
};

Node operator + (const Node& n1, const Node& n2){
   Node res(0,0,0);
   int ss = min(n1.left, n2.right);
   res.left = n1.left + n2.left -ss;
   res.right = n2.right + n1.right -ss;
   res.val = n1.val + n2.val + ss;
   return res;
} 
Node st[4*MAX_I];
char s[MAX_I];
int n;

void input(){
   scanf("%s", s);
   n = strlen(s);
}
void build(int id, int l, int r){
   if (l==r){
      if (s[l-1] == '(') st[id] = {1, 0, 0};
      else st[id] = {0,1,0};
      return; 
   }
   int mid = (l+r)/2;
   build(2*id, l, mid);
   build(2*id+1, mid+1, r);
   st[id] = st[2*id] + st[2*id+1];
}

Node query(int id, int l, int r, int u, int v){
   // Not intersect
   if (v<l || u>r){
      return {0,0,0};
   }
   // Inner
   if (u<=l && v>=r){
      return st[id];
   }
   int mid = (l+r)/2;
   auto r1 = query(2*id, l, mid, u,v);
   auto r2 = query(2*id+1, mid+1, r, u, v);

   return r1 + r2;
}

int main(){
   if(const char* env_p = std::getenv("TEST_ENVIRONMENT")) {
        std::cout << "Input to input.txt file\n";
        if (freopen("help_file/base.cpp", "r", stdin) == NULL)
    {
       perror("freopen() failed");
       return EXIT_FAILURE;
    }
   }
   input();
   build(1, 1, n);
   int t, x, y;
   cin >> t;
   while (t--){
      cin >> x >> y;
      auto res = query(1, 1, n, x, y);
      cout << res.val*2 << endl;
   }
   return 0; 
}
