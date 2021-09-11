// Link   https://codeforces.com/problemset/problem/1132/G
// False test
#include <bits/stdc++.h>
#define MAX_I 1000005
#define ll long long
using namespace std;
int dequeue[MAX_I];
int a[MAX_I], n, k;
int top = -1, bot = 0;
void printQ(){
   if (top < bot) {
      cout << "Q rong" << endl;
      return;
   }
   for (int i = bot; i <= top; ++i){
      cout << a[dequeue[i]] << " ";
   }
   cout << endl;
}
vector<int> solve(){
   vector<int>  res;
   int max_c = 0;
   for (int i=n-1; i>=0; --i){
       // queue
      while(top >= bot && dequeue[bot] - i +1 > k){
         bot++;
         max_c = max(0, max_c-1);
         // printf("tang queue co max_c la %d\n", max_c);
      }
      //stack
      while(top>=bot && a[dequeue[top]] <= a[i]){
         --top;
      }
     
      dequeue[++top] = i;
      // printQ();
      max_c = max(max_c, top-bot+1);
      // printf("Max c : %d \n", max_c);
      res.push_back(max_c);
   }
   return res;
}

void input(){
   cin >> n >> k;
   for (int i=0; i<n; ++i){
      cin >> a[i];
   }
}
int main(){
   input();
   // cout << "---";
   auto s = solve();
   for (int i = n-1; i>=k-1; --i){
      cout << s[i] << " ";
   }
   // cout << "----";
   return 0; 
}