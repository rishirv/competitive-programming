//MST Minimum Spanning Tree
//Kruskal's Algorithm
//Union Find Disjoint Set
//Minimum Spanning Forest
//Graph
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

int size[2001];
int parent[2001];

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
int n, k, t, x[1000], y[1000];
double c;

int main(){
  cin>>t;
  while(t--){
    cin>>k>>n;
    e.clear();
    c = 0;
    init(n);
    for(int i=0; i<n; i++) cin>>x[i]>>y[i];
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        e.push_back(make_pair((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]), ii(i, j)));
      }
    }
    sort(e.begin(), e.end());
    int i=0;
    for(auto x : e){
      if(Union(x.second.first, x.second.second)){
        c = max(c, sqrt(x.first));
        i++;
      }
      if(i == n-k) break;
    }
    cout<<fixed<<setprecision(2)<<c<<'\n';
  }
}