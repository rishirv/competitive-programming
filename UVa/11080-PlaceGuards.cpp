#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int t, v, e, x, y, color[200];
vector<int> adj[200];

int main() {
  cin>>t;
  while(t--){
    cin>>v>>e;
    memset(color, -1, sizeof color);
    for(int i=0; i<v; i++) adj[i].clear();
    for(int i=0; i<e; i++){
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    int i = 0, m = 0, s, r;
    while(m != -1){
      queue<int> q;
      for(; i<v; i++){
        if(color[i] == -1){
          q.push(i);
          color[i] = 0;
          break;
        }
      }
      s = r = 0;
      if(q.empty()) break;
      while(!q.empty() && m!=-1){
        ++s;
        int u = q.front();
        q.pop();
        if(color[u] == 0) ++r;
        for(int j : adj[u]){
          if(color[j] == -1){
            color[j] = 1 - color[u];
            q.push(j);
          } else if(color[j] == color[u]){
            m = -1;
            break;
          }
        }
      }
      r = (s == 1 ? 1 : min(r, s-r));
      if(m != -1) m+=r;
    }
    cout<<m<<'\n';
  }
}