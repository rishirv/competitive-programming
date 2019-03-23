//DFS
//Star League
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int visited[200], n, l, x, y;
vector<int> adj[200];

bool dfs(int i=0, int c=1){
  visited[i] = c;
  for(int j : adj[i]){
    if(visited[j]>0 && visited[j] == c){
      return false;
    }
    if(visited[j]==0 && !dfs(j, 3-c)){
      return false;
    }
  }
  return true;
}

int main() {
  while(cin>>n && n!=0){
    memset(visited, 0, sizeof visited);
    for(int i=0; i<n; i++){
      adj[i].clear();
    }
    cin>>l;
    for(int i=0; i<l; i++){
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    if(dfs()) cout<<"BICOLORABLE.\n";
    else cout<<"NOT BICOLORABLE.\n";
  }
}