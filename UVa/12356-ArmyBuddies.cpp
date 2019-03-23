#include <iostream>
#include <cstring>
using namespace std;

int pre[100005], after[100005];
int b, s, l, r;

int main() {
  while(cin>>s>>b && s!=0 && b != 0){
    memset(pre, 0, sizeof pre);
    memset(after, 0, sizeof after);
    pre[1] = 0;
    after[s] = 0;
    for(int i = 2; i <= s; i++){
      pre[i] = i-1;
      after[i-1] = i;
    }
    while(b--){
      cin>>l>>r;
      if(pre[l] == 0) cout<<"* ";
      else cout<<pre[l]<<' ';
      if(after[r] == 0) cout<<"*\n";
      else cout<<after[r]<<'\n';
      pre[after[r]] = pre[l];
      after[pre[l]] = after[r];
    }
    cout<<'-'<<endl;
  }
}