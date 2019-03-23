//MST Minimum Spanning Tree
//Kruskal's Algorithm
//Union Find Disjoint Set
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
vector<bool> f;
int n, m, u, v, w, c;
bool flag;

int main(){
  while(cin>>n>>m && n!=0){
    e.clear();
    f.clear();
    c = 0;
    for(int i=0; i<m; i++){
      cin>>u>>v>>w;
      e.push_back(make_pair(w, ii(u, v)));
    }
    sort(e.begin(), e.end());
    init(n);
    for(auto x : e){
      if(Union(x.second.first, x.second.second)){
        c += x.first;
        f.push_back(false);
      } else{
        f.push_back(true);
      }
    }
    flag = false;
    for(int i=0; i<m; i++){
      if(f[i]){
        if(flag) cout<<' ';
        cout<<e[i].first;
        flag = true;
      }
    }
    if(!flag) cout<<"forest";
    cout<<'\n';
  }
}