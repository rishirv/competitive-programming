#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> l, h;
int n;

int main() {
  cin>>n;
  l.push(n);
  cout<<n<<'\n';
  bool f = false;
  while(cin>>n){
    if(n <= l.top()){
      l.push(n);
      if(l.size()>h.size()+1){
        h.push(-l.top());
        l.pop();
      }
    } else{
      h.push(-n);
      if(h.size()>l.size()){
        l.push(-h.top());
        h.pop();
      }
    }
    if(f) cout<<l.top()<<'\n';
    else cout<<(l.top()-h.top())/2<<'\n';
    f = !f;
  }
}