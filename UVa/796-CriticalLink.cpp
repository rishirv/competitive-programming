//Articulation Point
//Articulation Bridge
//Tarjans Algorithm
//Graph
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int v, e, x, y, low[2000], num[2000], p[2000], idx;
vector<int> adj[2000];
vector<pair<int, int> > res;
char ch;

void bridge(int i){
  low[i] = num[i] = idx++;
  for(int j : adj[i]){
    if(num[j] == -1){
      p[j] = i;
      bridge(j);
      if(low[j] > num[i]) res.push_back(make_pair(min(j, i), max(j, i)));
      low[i] = min(low[i], low[j]);
    } else if(p[i] != j)
      low[i] = min(low[i], num[j]);
  }
}

int main() {
  while(cin>>v){
    idx = 0;
    res.clear();
    memset(num, -1, sizeof num);
    for(int i=0; i<v; i++) adj[i].clear();
    for(int i=0; i<v; i++){
      cin>>x>>ch>>e>>ch;
      for(int j=0; j<e; j++){
        cin>>y;
        adj[x].push_back(y);
      }
    }
    for(int i=0; i<v; i++){
      if(num[i] == -1){
        bridge(i);
      }
    }
    sort(res.begin(), res.end());
    cout<<res.size()<<" critical links\n";
    for(pair<int, int> ii : res) cout<<ii.first<<" - "<<ii.second<<'\n';
    cout<<'\n';
  }
}