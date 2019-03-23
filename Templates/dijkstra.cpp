#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int inf = 1000000000;
vi dist;
vii edges[105];
int t, n, e, k, m, x, y, z, c;

void dijkstra(int s){
  dist = vi(105, inf);
  dist[s] = 0;
  priority_queue<ii, vii, greater<ii > > pq;
  pq.push(ii(0, s));
  while(!pq.empty()){
    ii front = pq.top();
    pq.pop();
    int d = front.first, u = front.second;
    if(d > dist[u]) continue;
    for(ii &v : edges[u]){
      if(dist[u] + v.second < dist[v.first]){
        dist[v.first] = dist[u] + v.second;
        pq.push(ii(dist[v.first], v.first));
      }
    }
  }
}

int main(){
  cin>>t;
  while(t--){
    cin>>n>>e>>k>>m;
    for(int i=0; i<n; i++) edges[i].clear();
    for(int i=0; i<m; i++){
      cin>>x>>y>>z;
      edges[x-1].push_back(ii(y-1, z));
    }
    dijkstra(e-1);
    c = 0;
    for(int i=0; i<n; i++) if(dist[i] <= k) c++;
    cout<<c<<'\n';
    if(t) cout<<'\n';
  }
}