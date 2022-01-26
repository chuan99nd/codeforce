// Link   

#include"help_file/lib.cpp"

int main(){
   setUp();
   int a[] = {1,2,3};
   print1DArray(a, 3);
   int b[1000][1000] = {{1,2,3}, {3,5,6}, {100,200,300}};
   print2DArray(b, 3, 3);
   tearDown();
   return 0;
}
