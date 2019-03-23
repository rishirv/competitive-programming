#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int r, c, m, n, t, w, x, y, visited[100][100], o, e, f;
int dr[] = {-1, -1, 1, 1};
int dc[] = {-1, 1, -1, 1};
int dx[] = {0, 0, -1, 1};

bool place(int i, int j){
  return i>=0 && i<r && j>=0 && j<c && visited[i][j]!=2;
}

void dfs(int i, int j){
  if(visited[i][j]) return;
  visited[i][j] = 1;
  int k = 0;

  if(f){
    for(int a=0; a<4; a++){
      if(place(i+f*dx[a], j+f*dx[3-a])){
        k++;
        dfs(i+f*dx[a], j+f*dx[3-a]);
      }
    }
  } else{
    for(int a=0; a<4; a++){
      if(place(i+m*dr[a], j+n*dc[a])){
        k++;
        dfs(i+m*dr[a], j+n*dc[a]);
      }
      if(m != n && place(i+n*dr[a], j+m*dc[a])){
        k++;
        dfs(i+n*dr[a], j+m*dc[a]);
      }
    }
  }
  if(k & 1) o++;
  else e++;
}

int main() {
  cin>>t;
  for(int i=0; i<t; i++){
    memset(visited, 0, sizeof visited);
    o = e = f = 0;
    cin>>r>>c>>m>>n>>w;
    while(w--){
      cin>>x>>y;
      visited[x][y] = 2;
    }
    if(m == 0 || n == 0) f = max(m, n);
    if(m == 0 && n == 0) o = 1;
    else dfs(0, 0);
    cout<<"Case "<<i+1<<": "<<e<<' '<<o<<'\n';
  }
}