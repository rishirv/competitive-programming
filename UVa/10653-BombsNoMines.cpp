//BFS Breadth First Search
//Graph
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;

int dist[1000][1000];
int r, c, k, x, y, z, a, b, n, m;
queue<ii> q;

bool place(int x, int y){
  return x>=0 && x<r && y>=0 && y<c && dist[x][y] == -1;
}

int main(){
  while(cin>>r>>c && r!=0){
    memset(dist, -1, sizeof dist);
    while(!q.empty()) q.pop();
    cin>>k;
    for(int i=0; i<k; i++){
      cin>>x>>y;
      for(int j=0; j<y; j++){
        cin>>z;
        dist[x][z]=-2;
      }
    }
    cin>>x>>y>>a>>b;
    dist[x][y] = 0;
    q.push(ii(x, y));
    while(!q.empty()){
      n = q.front().first;
      m = q.front().second;
      q.pop();
      if(n == a && m == b) break;
      if(place(n+1, m)){
        dist[n+1][m] = dist[n][m] + 1;
        q.push(make_pair(n+1, m));
      }
      if(place(n-1, m)){
        dist[n-1][m] = dist[n][m] + 1;
        q.push(make_pair(n-1, m));
      }
      if(place(n, m+1)){
        dist[n][m+1] = dist[n][m] + 1;
        q.push(make_pair(n, m+1));
      }
      if(place(n, m-1)){
        dist[n][m-1] = dist[n][m] + 1;
        q.push(make_pair(n, m-1));
      }
    }
    cout<<dist[a][b]<<'\n';
  }
}