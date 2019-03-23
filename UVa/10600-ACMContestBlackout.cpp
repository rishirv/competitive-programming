//MST Minimum Spanning Tree
//Kruskal's Algorithm
//Union Find Disjoint Set
//2nd Best Spanning Tree
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

vector<pair<int, ii>> e;
int n, m, u, v, w, t, c, c1, k;
vector<bool> used;

int main(){
  cin>>t;
  while(t--){
    cin>>n>>m;
    e.clear();
    used.clear();
    init(n);
    c = 0;
    c1 = 3000000;
    for(int i=0; i<m; i++){
      cin>>u>>v>>w;
      e.push_back(make_pair(w, ii(--u, --v)));
    }
    sort(e.begin(), e.end());
    for(auto x : e){
      if(Union(x.second.first, x.second.second)){
        c += x.first;
        used.push_back(true);
      } else used.push_back(false);
    }
    cout<<c<<' ';
    for(int i=0; i<e.size(); i++){
      if(used[i]){
        init(n);
        c = k = 0;
        for(int j=0; j<e.size(); j++){
          if(j!=i && Union(e[j].second.first, e[j].second.second)){
            c += e[j].first;
            k++;
          }
        }
        if(k == n-1) c1 = min(c1, c);
      }
    }
    cout<<c1<<'\n';
  }
}