#include <iostream>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

int x, y, n, c;
vector<int> a, b;
set<pair<int, int> > s[10001];

int main() {
  while(cin>>x>>y){
    set<pair<int, int> > s[10001];
    for(int r=1; r<=x; r++){
      a.clear();
      b.clear();
      cin>>n;
      for(int i=0; i<n; i++){
        cin>>c;
        a.push_back(c);
      }
      for(int i=0; i<n; i++){
        cin>>c;
        b.push_back(c);
      }
      for(int i=0; i<a.size(); i++){
        s[a[i]].insert(make_pair(r, b[i]));
      }
    }
    cout<<y<<' '<<x<<endl;
    for(int i=1; i<=y; i++){
      cout<<s[i].size();
      for(auto p : s[i]) cout<<' '<<p.first;
      cout<<endl;
      for(auto it = s[i].begin(); it != s[i].end(); it++){
        cout<<it->second;
        if(it != --s[i].end()) cout<<' ';
      }
      cout<<endl;
    }
  }
}