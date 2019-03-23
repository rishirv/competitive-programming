#include <iostream>
using namespace std;

long long n, l, u, t;

int main(){
  while(cin>>n>>l>>u){
    t = 0;
    for(int i = 32; i >= 0; i--){
      if(t + (1L<<i) - 1 < l){
        t += (1L<<i);
      } else if(t + (1L<<i) <= u && (n & (1L<<i)) == 0){
        t += (1L<<i);
      }
    }
    cout<<t<<'\n';
  }
}