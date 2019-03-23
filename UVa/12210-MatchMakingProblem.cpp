#include <iostream>
#include <algorithm>
using namespace std;

int b, s, x, y, n = 0;

int main(){
  while(cin>>b>>s && b != 0){
    y = 70;
    for(int i=0; i<b; i++){
      cin>>x;
      y = min(x, y);
    }
    for(int i=0; i<s; i++) cin>>x;
    cout<<"Case "<<++n<<": "<<max(0, b-s);
    if(b-s > 0) cout<<' '<<y;
    cout<<'\n';
  }
}