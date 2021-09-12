// Link   
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

int main(){
   setUp();
   
   return 0;
}
