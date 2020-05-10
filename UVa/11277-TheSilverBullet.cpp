//Slope
//Maximum Number of collinear points in a plane
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<double, double> dd;
int t, n, m;
double a, b;
dd arr[100];
set<dd> s;
map<double, int> r;

int main(){
  cin>>t;
  for(int i=1; i<=t; i++){
    cin>>n;
    s.clear();
    while(n--){
      cin>>a>>b;
      s.insert(make_pair(a, b));
    }
    m = 0;
    for(dd x : s){
      r.clear();
      for(dd y : s)
        if(x != y)
          r[(x.second-y.second)/(x.first-y.first)]++;
      m = max(m, max_element(r.begin(), r.end())->second);
    }
    if(s.size() == 1){
      cout<<"Data set #"<<i<<" contains a single gnu.\n";
    } else{
      cout<<"Data set #"<<i<<" contains "<<s.size()<<" gnus, out of which a maximum of "<<m+1<<" are aligned.\n";
    }
  }
}