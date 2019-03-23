//SSSP Single Source Shortest Paths
//Dijkstra
//Edge list
//Graph
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int inf = 1000000000;
vi distS, distT;
vii adj[10005], out[10005];
vector<pair<int, ii > > edges;
int c, n, m, s, t, p, x, y, z, r;

void dijkstraS(){
  distS = vi(10005, inf);
  distS[s] = 0;
  priority_queue<ii, vii, greater<ii > > pq;
  pq.push(ii(0, s));
  while(!pq.empty()){
    ii front = pq.top();
    pq.pop();
    int d = front.first, u = front.second;
    if(d > distS[u]) continue;
    for(ii &v : adj[u]){
      if(distS[u] + v.second < distS[v.first]){
        distS[v.first] = distS[u] + v.second;
        pq.push(ii(distS[v.first], v.first));
      }
    }
  }
}

void dijkstraT(){
  distT = vi(10005, inf);
  distT[t] = 0;
  priority_queue<ii, vii, greater<ii > > pq;
  pq.push(ii(0, t));
  while(!pq.empty()){
    ii front = pq.top();
    pq.pop();
    int d = front.first, u = front.second;
    if(d > distT[u]) continue;
    for(ii &v : out[u]){
      if(distT[u] + v.second < distT[v.first]){
        distT[v.first] = distT[u] + v.second;
        pq.push(ii(distT[v.first], v.first));
      }
    }
  }
}

int main(){
  cin>>c;
  while(c--){
    cin>>n>>m>>s>>t>>p;
    --s; --t;
    for(int i=0; i<n; i++){
      adj[i].clear();
      out[i].clear();
    }
    edges.clear();
    for(int i=0; i<m; i++){
      cin>>x>>y>>z;
      --x; --y;
      adj[x].push_back(ii(y, z));
      out[y].push_back(ii(x, z));
      edges.push_back(make_pair(z, ii(x, y)));
    }
    dijkstraS();
    dijkstraT();
    r = -1;
    for(auto i : edges){
      if(distS[i.second.first] + i.first + distT[i.second.second] <= p){
        r = max(r, i.first);
      }
    }
    cout<<r<<'\n';
  }
}