#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

bool f;
int n, x;
vi v;
map<int, int> m;
bool comp(ii const &l, ii const &r){
  return l.second < r.second;
}

int main() {
  cin>>n;
  while(true){
    v.clear();
    m.clear();
    for(int i=0; i<n; i++){
      cin>>x;
      v.push_back(x);
      m[x]++;
    }
    x = max_element(m.begin(), m.end(), comp)->second;
    sort(v.begin(), v.end());
    cout<<x<<'\n';
    for(int i=0; i<x; i++){
      cout<<v[i];
      for(int j=i+x; j<n; j+=x) cout<<' '<<v[j];
      cout<<'\n';
    }
    cin>>n;
    if(n) cout<<'\n';
    else break;
  }
}