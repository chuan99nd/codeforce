// Link https://codeforces.com/contest/1407/problem/D   

#include <bits/stdc++.h>
#define MAX_I 300005
#define ll long long

using namespace std;
int l1[MAX_I], r1[MAX_I];
int l2[MAX_I], r2[MAX_I];
int h[MAX_I];
int n, k;
int q1[MAX_I];
int q2[MAX_I];
int top1 = -1, bot1 = 0;
int top2 = -1, bot2 = 0;
bool duyet[MAX_I];
vector<int> adj[MAX_I];
void input(){
   cin >>n;  
   for (int i =0; i<n; ++i) {
      cin >> h[i];
   }
}

int bfs(){
   queue<pair<int, int> > q;
   q.push({0,0});
   while(!q.empty()){
      auto p = q.front();
      q.pop();
      if (p.first == (n-1)) return p.second;
      if (duyet[p.first]) continue;
      duyet[p.first] = true;
      for (auto k: adj[p.first]){
         q.push({k, p.second + 1});
         // cout << "canh" << p.first << " " << k << endl;
      }
   }
   return 0;
}
int solve(){
   for (int i=0; i<n; ++i){
      while(top1>=bot1 && h[q1[top1]] <= h[i]) --top1;
      l1[i] = top1>=bot1? q1[top1] : -1;
      q1[++top1] = i;

      // scan l2, r2
      while(top2>=bot2 && h[q2[top2]] >= h[i]) --top2;
      l2[i] = top2>=bot2? q2[top2] : -1;
      q2[++top2] = i;
   }

   top1 = top2 = -1;
   bot1 = bot2 = 0;
   for (int i=n-1; i>= 0; --i){
      while(top1>=bot1 && h[q1[top1]] <= h[i]) --top1;
      r1[i] = top1>=bot1? q1[top1] : -1;
      q1[++top1] = i;

      // scan l2, r2
      while(top2>=bot2 && h[q2[top2]] >= h[i]) --top2;
      r2[i] = top2>=bot2? q2[top2] : -1;
      q2[++top2] = i;
   }

   // Create grapjh
   for (int i=1; i<n; ++i) {
      if (l1[i] >=0 && r1[i] >=0 ) adj[l1[i]].push_back(r1[i]);
      if (l2[i] >=0 && r2[i] >=0)adj[l2[i]].push_back(r2[i]);
      adj[i-1].push_back(i);
      // printf("%d (%d %d) (%d %d)\n", i, l1[i], r1[i], l2[i], r2[i]);
   }
   return bfs();
}


int main(){
   input();
   int res = solve();
   cout << res;
   return 0; 
}