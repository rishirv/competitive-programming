#include <iostream>
using namespace std;

int n, a, b;
bool f;

int main() {
  while(cin>>n){
    if(n==0) break;
    f = 1;
    a = b = 0;
    while(n > 0){
      if(f)
        a += n - (n & (n-1));
      else 
        b += n - (n & (n-1));
      n &= n-1;
      f = !f;
    }
    cout<<a<<' '<<b<<endl;
  }
}