//Directed SCC
//Strongly Connected Component
//Graph
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

vii adj, out;
vi num, low, visited, S, sccs, r;
int t, n, m, x, y, idx, nSCC;

void SCC(int i){
  low[i] = num[i] = idx++;
  S.push_back(i);
  visited[i] = true;
  for(int j : adj[i]){
    if(num[j] == -1){
      SCC(j);
      low[i] = min(low[i], low[j]);
    } else if(visited[j]){
      low[i] = min(low[i], num[j]);
    }
  }
  if(low[i] == num[i]){
    bool f  = true;
    r.clear();
    while(true){
      int v = S.back();
      S.pop_back();
      visited[v] = false;
      sccs[v] = i;
      r.push_back(v);
      if(v == i) break;
    }
    for(int v : r){
      for(int j : out[v]){
        if(sccs[j] != sccs[v]){
          f = false;
          break;
        }
      }
      if(!f) break;
    }
    if(f) nSCC++;
  }
}

int main(){
  cin>>t;
  while(t--){
    cin>>n>>m;
    adj.assign(n, vi());
    out.assign(n, vi());
    num.assign(n, -1);
    low.assign(n, 0); 
    visited.assign(n, 0);
    sccs.assign(n, -1);
    idx = nSCC = 0;
    for(int i=0; i<m; i++){
      cin>>x>>y;
      adj[--x].push_back(--y);
      out[y].push_back(x);
    }
    for(int i=0; i<n; i++) if(num[i] == -1) SCC(i);
    cout<<nSCC<<endl;
  }
}