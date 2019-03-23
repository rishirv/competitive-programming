#include <iostream>
using namespace std;

int main() {
  int x, y, a;
  while(cin>>x>>y){
    if(x*4 - y < 0){
      a = 10*x - 2*y;
    } else if(x*3 - y*2 < 0){
      a = 8*x - 4*y;
    } else if(x*2 - y*3 < 0){
      a = 6*x - 6*y;
    } else if(x - y*4 < 0){
      a = 3*x - 9*y;
    } else{
      a = -12*y;
    }
    if(a > 0) cout<<a<<'\n';
    else cout<<"Deficit\n";
  }
}