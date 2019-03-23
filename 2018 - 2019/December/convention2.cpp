#include <fstream>
#include <algorithm>
#include <list>
using namespace std;

struct cow{
  int a, t, s;
  bool operator < (const cow& rhs) const {
    return a < rhs.a || (a == rhs.a && s < rhs.s);
  }
};

int n;
list<cow> arr;

ifstream cin ("convention2.in");
ofstream cout ("convention2.out");

int main(){
  cin>>n;
  for(int i=0; i<n; i++){
    cow c;
    cin>>c.a>>c.t;
    c.s = i;
    arr.push_back(c);
  }
  arr.sort();
  int t = arr.front().a + arr.front().t, maxwait = 0, nextpr;
  list<cow>::iterator i, next;
  arr.erase(arr.begin());
  while(!arr.empty()){
    nextpr = 1000001;
    i = arr.begin();
    do{
      if(i->s < nextpr){
        next = i;
        nextpr = i->s;
      }
      ++i;
    } while(i != arr.end() && i->a <= t);
    maxwait = max(maxwait, t - next->a);
    t = max(t, next->a);
    t += next->t;
    arr.erase(next);
  }
  cout<<maxwait<<endl;
}