/*
ID: verma.r1
PROG: humble
LANG: C++11
*/
#include <fstream>
#include <set>
using namespace std;

int main(){
  ifstream cin ("humble.in");
  ofstream cout ("humble.out");

  int k, n;
  cin>>k>>n;
  long p[k];
  set<long> h;
  for(int i=0; i<k; i++)
    cin>>p[i];
    
  h.insert(1);
  for(int i=0; i<k; i++){
    auto it=h.begin();
    while(true){
      if(it==h.end())
        break;
      long x=(*it)*p[i];
      if(x<0)
        break;
      if(h.size()>n){
        if(x>*(--h.end()))
          break;
        h.erase(--h.end());
      }
      h.insert(x);
      it++;
    }
  }
  cout<<*(--h.end())<<endl;
  return 0;
}