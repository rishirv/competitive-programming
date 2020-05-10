//K-clustering based on Kruskal's algorithm
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

bool comp(const tuple<int, int, int>& a, const tuple<int, int, int>& b){
  return get<2>(a) < get<2>(b);
}

ifstream fin ("cluster.in");
vector<tuple<int, int, int>> g;
int n, clusters, space, it=0;

//Union - Find implementation
int parent[501], size[501];

int Find(int i){
  if(i == parent[i]) return i;
  parent[i] = Find(parent[i]);
  return parent[i];
}

bool Union(int x, int y){
  int a = Find(x), b = Find(y);

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

//End Union - Find

void add_edge(){
  while(!Union(get<0>(g[it]), get<1>(g[it]))) ++it;
  space=get<2>(g[it]);
  ++it;
  clusters--;
}

int main(){
  int i, j, k, target;
  fin>>n;
  cin>>target;

  while(fin>>i>>j>>k){
    g.push_back(make_tuple(i, j, k));
  }

  sort(g.begin(), g.end(), comp);

  for(int i=1; i<=500; i++){
    parent[i] = i;
  }

  clusters = n;

  while(clusters != target){
    add_edge();
  }
  add_edge();

  cout<<space<<endl;
}