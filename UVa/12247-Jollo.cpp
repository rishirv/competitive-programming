#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int a[3], x[2], r;
  while(scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &x[0], &x[1]), a[0]>0){
    sort(a, a+3);
    sort(x, x+2);
    if(a[2] < x[0]){
      r=1;
    } else if(a[1]<x[0]){
      r=a[1]+1;
    } else if(a[2] > x[1]){
      r=-1;
    } else{
      r=a[2]+1;
    }
    if(r>0){
      do{
        if(a[0] != r && a[1] != r && a[2] != r && x[0] !=r && x[1] != r) break;
      } while(r++);
    }
    if(r>52) r = -1;
    printf("%d\n", r);
  }
  return 0;
}