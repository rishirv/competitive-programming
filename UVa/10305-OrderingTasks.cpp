#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;
int m, n, x, y;
vi adj[110], res;
bool visited[110];

void dfs(int v){
  visited[v] = true;
  for(int u : adj[v]){
    if(!visited[u]){
      dfs(u);
    }
  }
  res.push_back(v);
}

int main() {
  while(cin>>m>>n && m!=0){
    res.clear();
    for(int i=0; i<m; i++) adj[i].clear();
    memset(visited, 0, sizeof visited);
    for(int i=0; i<n; i++){
      cin>>x>>y;
      adj[x].push_back(y);
    }
    for(int i=1; i<=m; i++){
      if(!visited[i]){
        dfs(i);
      }
    }
    for(int i=m-1; i>0; i--){
      cout<<res[i]<<' ';
    }
    cout<<res[0]<<'\n';
  }
}