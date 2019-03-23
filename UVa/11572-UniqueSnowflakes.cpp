#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> m;
int a, n, k, p, l;

int main(){
  cin>>a;
  for(int i=0; i<a; i++){
    cin>>n;
    m.clear();
    l = p = 0;
    for(int j=1; j<=n; j++){
      cin>>k;
      if(m[k] > p){
        l = max(l, j-p-1);
        p = m[k];
      } else{
        l = max(l, j-p); 
      }
      m[k] = j;
    }
    cout<<l<<endl;
  }
}