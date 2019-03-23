#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, k, val[5], num[5];
char v;
vector<vector<int> > com;

int main() {
  cin>>n;
  while(n--){
    com = vector<vector<int> >(5);
    set<char> a[5];
    set<char> b[5];

    cin>>k;
    k--;

    for(int i=0; i<6; i++){
      for(int j=0; j<5; j++){
        cin>>v;
        a[j].insert(v);
      }
    }
    for(int i=0; i<6; i++){
      for(int j=0; j<5; j++){
        cin>>v;
        b[j].insert(v);
      }
    }

    for(int i=0; i<5; i++){
      auto it = set_intersection(a[i].begin(), a[i].end(), b[i].begin(), b[i].end(), inserter(com[i], com[i].begin()));
    }

    val[4] = com[4].size();
    for(int i=3; i>=0; i--) val[i] = com[i].size()*val[i+1];
    if(k >= val[0]) cout<<"NO\n";
    else{
      for(int i=0; i<4; i++){
        num[i] = k/val[i+1];
        k %= val[i+1];
      }
      num[4] = k;
      for(int i=0; i<5; i++){
        cout<<(char) com[i][num[i]];
      }
      cout<<'\n';
    }
  }
}