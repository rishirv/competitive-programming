//SSSP Single Source Shortest Paths
//Bellman Ford
//Negative Weight Cycle
//Graph
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int inf = 1000000000;
vector<vii> adj;
vi dist;
int c, n, m, x, y, z;
bool f;

int main(){
  cin>>c;
  while(c--){
    cin>>n>>m;
    adj.assign(n, vii());
    for(int i=0; i<m; i++){
      cin>>x>>y>>z;
      adj[x].push_back(ii(y, z));
    }
    dist.assign(n, inf);
    dist[0] = 0;
    for(int i=0; i<n-1; i++){
      for(int j=0; j<n; j++){
        for(ii k : adj[j]){
          dist[k.first] = min(dist[k.first], dist[j] + k.second);
        }
      }
    }
    f = false;
    for(int j=0; j<n; j++){
      if(dist[j] < 5000000){
        for(ii k : adj[j]){
          if(dist[j] + k.second < dist[k.first]){
            f = true;
            break;
          }
        }
      }
    }
    if(!f) cout<<"not ";
    cout<<"possible\n";
  }
}