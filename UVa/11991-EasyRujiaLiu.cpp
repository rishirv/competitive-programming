#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define vi vector<int>

map<int, vi> m;
int r, s, x, y;

int main() {
  while(cin>>r>>s){
    for(int i=1; i<=r; i++){
      cin>>x;
      m[x].push_back(i);
    }
    for(int i=0; i<s; i++){
      cin>>x>>y;
      if(m[y].size()>x-1){
        cout<<m[y][x-1]<<endl;
      } else{
        cout<<0<<endl;
      }
    }
  }
}