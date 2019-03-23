#include <iostream>
#include <algorithm>
using namespace std;

int n, d, r, morn[200], eve[200], t;

int main(){
  while(cin>>n>>d>>r && n !=0){
    t = 0;
    for(int i=0; i<n; i++) cin>>morn[i];
    for(int i=0; i<n; i++) cin>>eve[i];
    sort(morn, morn+n);
    sort(eve, eve+n, greater<int>());
    for(int i=0; i<n; i++) t+= max(0, morn[i] + eve[i] - d);
    cout<<t*r<<'\n';
  }
}