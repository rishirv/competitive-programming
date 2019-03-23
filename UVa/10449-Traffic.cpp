//APSP All Pairs Shortest Paths
//Floyd Warshall
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
vi queries;
int n, b[300], r, q, x, y, c, dist[300][300];

int main(){
  while(cin>>n){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        dist[i][j] = inf;
      }
    }
    for(int i=0; i<n; i++){
      cin>>b[i];
      dist[i][i] = 0;
    }
    cin>>r;
    for(int i=0; i<r; i++){
      cin>>x>>y;
      --x; --y;
      dist[x][y] = (b[y]-b[x])*(b[y]-b[x])*(b[y]-b[x]);
    }
    cin>>q;
    queries.clear();
    for(int i=0; i<q; i++){
      cin>>x;
      queries.push_back(--x);
    }
    for(int k=0; k<n; k++){
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(dist[i][j] < 10000000 && dist[i][i] < 0){
          dist[j][j] = -1;
        }
      }
    }
    cout<<"Set #"<<++c<<'\n';
    for(int i : queries){
      if(dist[0][i]<3 || dist[0][i]>10000000 || dist[i][i]<0) cout<<"?\n";
      else cout<<dist[0][i]<<'\n';
    }
  }
}