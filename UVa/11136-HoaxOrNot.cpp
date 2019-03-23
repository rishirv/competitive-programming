#include <iostream>
#include <set>
using namespace  std;

multiset<int> s;
multiset<int>::iterator it;

int main(){
  int n, k, a;
  long long t;
  while(cin>>n && n != 0){
    t = 0;
    s.clear();
    while(n--){
      cin>>k;
      while(k--){
        cin>>a;
        s.insert(a);
      }
      it = s.end();
      it--;
      t += (*it) - (*s.begin());
      s.erase(it);
      s.erase(s.begin());
    }
    cout<<t<<endl;
  }
}