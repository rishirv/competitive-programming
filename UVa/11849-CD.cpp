#include <iostream>
using namespace std;

int x, y, i, j, c, a[1000000], b;

int main() {
  while(cin>>x>>y){
    if(x==0) break;
    for(i=0; i<x; i++) cin>>a[i];
    i = c = 0;
    for(j=0; j<y; j++){
      cin>>b;
      while(b>a[i] && i<x) i++;
      if(b == a[i]) c++;
    }
    cout<<c<<endl;
  }
}