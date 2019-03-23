//BFS Breadth First Search
//Multi-source BFS
//Implicit Graph
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dist[2001][2001];
bool dest[2001][2001];
int p, x, y, n, m;
queue<ii> q;
bool f;

bool place(int x, int y){
  return x>=0 && x<2001 && y>=0 && y<2001 && dist[x][y]<0;
}

int main(){
  while(cin>>p && p!=0){
    memset(dist, -1, sizeof dist);
    memset(dest, 0, sizeof dest);
    while(!q.empty()) q.pop();
    for(int i=0; i<p; i++){
      cin>>x>>y;
      q.push(ii(x, y));
      dist[x][y] = 0;
    }
    cin>>p;
    for(int i=0; i<p; i++){
      cin>>x>>y;
      dest[x][y] = 1;
    }
    f = true;
    while(f && !q.empty()){
      n = q.front().first;
      m = q.front().second;
      q.pop();
      for(int i=0; i<4; i++){
        if(place(n+dr[i], m+dc[i])){
          dist[n+dr[i]][m+dc[i]] = dist[n][m] + 1;
          if(dest[n+dr[i]][m+dc[i]]){
            cout<<dist[n+dr[i]][m+dc[i]]<<'\n';
            f = false;
            break;
          }
          q.push(ii(n+dr[i], m+dc[i]));
        }
      }
    }
  }
}