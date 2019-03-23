#include <iostream>
using namespace std;

int n, m, arr[1000];

bool can(int t){
  int c = 0, v = 0;
  for(int i = 0; i<n; i++){
    if(v + arr[i] <= t){
      v += arr[i];
    } else{
      v = 0;
      c++;
      i--;
    }
    if(c == m) return false;
  }
  return true;
}

int main(){
  while(cin>>n>>m){
    for(int i=0; i<n; i++){
      cin>>arr[i];
    }
    int lo = 1, hi = 1000000000, mid = 0;
    while(hi - lo > 1){
      mid = (lo + hi)/2;
      if(can(mid)){
        hi = mid;
      } else{
        lo = mid;
      }
    }
    if(can(lo)) cout<<lo<<'\n';
    else cout<<hi<<'\n';
  }
}