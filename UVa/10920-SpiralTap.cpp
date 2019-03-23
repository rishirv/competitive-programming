#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
  int size, n, r, c, x, l;
  cin>>size>>n;
  while(true){
    r = c = (size+1)/2;
    x = sqrt(n);
    l = n - x*x;
    if(x % 2 == 0){
      r -= x/2 - 1;
      c -= x/2;
      if(l != 0){
        r -= 1;
        c += min(x, l-1);
        r += max(0, l-x-1);
      }
    } else{
      r += x/2;
      c += x/2;
      if(l != 0){
        r += 1;
        c -= min(x, l-1);
        r -= max(0, l-x-1);
      }
    }
    cout<<"Line = "<<r<<", column = "<<c<<".\n";
    cin >> size >> n;
    if(size == 0 || n == 0) break;
  }
}