#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

ifstream fin ("cluster.in");
int n, m, clusters;
unordered_map<int, int> labels;

//Union - Find implementation
int parent[200001], size[200001];

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

int main(){
	fin>>n>>m;

	for(int i=1; i<=n; i++){
    int x, y;
    fin>>x;
    for(int j=1; j<m; j++){
      fin>>y;
      x = 2*x+y;
    }
    labels.insert(make_pair(x, i));
  }

  for(int i=1; i<=n; i++){
    parent[i] = i;
  }

  clusters = labels.size();

  for(auto x : labels){
    for(int i=0; i<m; i++){
      int shift = x.first ^ (1 << i);
      auto v = labels.find(shift);
      if(v != labels.end()){
        if(Union(x.second, v->second)){
          clusters--;
        }
      }
    }
  }

  for(auto x : labels){
    for(int i=0; i<m; i++){
      for(int j=i+1; j<m; j++){
        int shift = x.first ^ (1 << i) ^ (1 << j);
        auto v = labels.find(shift);
        if(v != labels.end()){
          if(Union(x.second, v->second)){
            clusters--;
          }
        }
      }
    }
  }
  cout<<clusters<<endl;
}