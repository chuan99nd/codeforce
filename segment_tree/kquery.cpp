// Link   https://oj.vnoi.info/submission/206431
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
int a[MAX_I];
int n, q;
struct Query {
   int k;
   int l, r;
   int index;
};

bool operator < (const Query& a, const Query &b) {
    return a.k < b.k;
}
vector<Query> query;
pair<int, int> eI[MAX_I]; // (val, ind in array a) 

void readInput(){
   cin >> n;
   for (int i=1; i<=n; ++i){
      cin >> a[i];
      eI[i] = {a[i], i};
   }
   cin >> q;
   int t1, t2, t3;
   for (int i = 0; i <q; ++i) {
      cin >> t1 >> t2 >> t3;
      Query qu = {t3, t1, t2, i};
      query.push_back(qu);
   }
}

int st[MAX_I*4];
int ans[MAX_I];
void build(int id, int l, int r){
   if (l==r) {
      st[id] = 1;
      return;
   }
   int mid = (l+r)/2;
   build(2*id, l,mid);
   build(2*id+1, mid+1, r);
   st[id] = st[2*id] + st[2*id+1];
}

void update(int id, int l, int r, int u){
   // if u nam ngoai l, r thi bo qua
   if (u<l || u>r) {
      return;
   }
   if (l==r){ // ==u
      st[id] = 0;
      return;
   }
   int mid = (l+r)/2;
   update(2*id, l, mid, u);
   update(2*id+1, mid+1, r, u);
   st[id] = st[2*id] + st[2*id+1];
}
int get(int id, int l, int r, int u, int v){
   if (v<l || u>r) return 0;
   if (u<=l && v>=r) return st[id];
   int mid = (l+r)/2;
   return get(2*id, l, mid, u, v)+ get(2*id+1, mid+1, r, u, v);
}
int main(){
   setUp();
   readInput();
   // sort query
   build(1, 1, n);
   sort(query.begin(), query.end());
   sort(eI +1, eI+n+1);
   int indEI = 0;
   for (auto qu: query){
      while (indEI <= n && eI[indEI].first <= qu.k) {
         // update element eI[indeEi].second
         update(1, 1, n, eI[indEI].second);
         ++indEI;
      }
      ans[qu.index] = get(1, 1, n, qu.l, qu.r);
   } 
   for (int i=0; i<q; ++i){
      cout << ans[i] << endl;
   }
   return 0;
}
