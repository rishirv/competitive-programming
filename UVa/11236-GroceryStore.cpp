#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int x, y, s=0;

int main(){
  cout<<fixed<<setprecision(2);
  for(int a = 1; a <= 212; a++){
    for(int b = a; b <= 670; b++){
      if(a*b*b*b > 2000000000) break;
      for(int c = b; c <= 1000; c++){
        x = a+b+c,
        y = a*b*c;
        if(y <= 1000000) continue;
        if(y*c > 2000000000) break;
        if(x*1000000 % (y - 1000000) == 0){
          int d = x*1000000/(y - 1000000);
          if(d >= c && x+d <= 2000 && y*d <= 2000000000){
            cout<<a/100.0<<' '<<b/100.0<<' '<<c/100.0<<' '<<d/100.0<<endl;
          }
        }
      }
    }
  }
}