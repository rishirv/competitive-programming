//MST Minimum Spanning Tree
//Kruskal's Algorithm
//Union Find Disjoint Set
//Minimax
//Maximin
//Graph
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

int parent[2000], size[2000];

int find(int i){
  if(i == parent[i]) return i;
  parent[i] = find(parent[i]);
  return parent[i];
}

bool Union(int x, int y){
  int a = find(x), b = find(y);
  if(a == b) return false;

  if(size[a] == size[b]){
    size[b]++;
    parent[a] = b;
  } else if(size[a] < size[b]){
    parent[a] = b;
  } else{
    parent[b] = a;
  }

  return true;
}

void init(int n){
  memset(size, 0, sizeof size);
  for(int i=0; i<n; i++) parent[i] = i;
}

vector<vector<ii>> adj;
vector<pair<int, ii>> e;
bool visited[200];
int n, m, q, u, v, w, t = 1;
bool flag;

int traverse(int u, int v){
  int minimax = -1;
  visited[u] = true;
  if(u == v) return 0;
  for(ii i : adj[u]){
    if(!visited[i.first]){
      int dist = traverse(i.first, v);
      if(dist >= 0) minimax = max(dist, i.second);
    }
  }
  return minimax;
}

int main(){
  while(cin>>n>>m>>q && n!=0){
    if(t != 1) cout<<'\n';
    cout<<"Case #"<<t++<<'\n';
    e.clear();
    adj.assign(n, vector<ii>());
    init(n);
    for(int i=0; i<m; i++){
      cin>>u>>v>>w;
      e.push_back(make_pair(w, ii(--u, --v)));
    }
    sort(e.begin(), e.end());
    for(auto x : e){
      if(Union(x.second.first, x.second.second)){
        adj[x.second.second].push_back(ii(x.second.first, x.first));
        adj[x.second.first].push_back(ii(x.second.second, x.first));
      }
    }
    for(int i=0; i<q; i++){
      memset(visited, false, sizeof visited);
      cin>>u>>v;
      int dist = traverse(u-1, v-1);
      if(dist != -1) cout<<dist<<'\n';
      else cout<<"no path\n";
    }
  }
}