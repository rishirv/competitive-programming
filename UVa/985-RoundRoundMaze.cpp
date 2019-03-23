//Clever
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int idx(char ch){
  if(ch == 'N') return 0;
  if(ch == 'E') return 1;
  if(ch == 'S') return 2;
  if(ch == 'W') return 3;
  return -1;
}

int dist[501][501][4];
queue<iii> q;
int r, c, x, y, z;
bool f, edge[501][501][4];
char ch;

bool place(int x, int y, int z, int i){
  return x+dr[i]>=0 && x+dr[i]<r && y+dc[i]>=0 && y+dc[i]<c && edge[x][y][(i-z+16)%4] && dist[x+dr[i]][y+dc[i]][(z+1)%4]<0;
}

int main(){
  while(cin>>r>>c){
    cin.ignore();
    memset(dist, -1, sizeof dist);
    memset(edge, 0, sizeof edge);
    while(!q.empty()) q.pop();
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        if(i != r-1 || j != c-1){
          while(cin.get(ch) && ch != '\n'){
            edge[i][j][idx(ch)] = 1;
          }
        }
      }
    }
    q.push(iii(0, ii(0, 0)));
    dist[0][0][0] = 0;
    f = true;
    while(f && !q.empty()){
      z = q.front().first;
      x = q.front().second.first;
      y = q.front().second.second;
      q.pop();
      for(int i=0; i<4; i++){
        if(place(x, y, z, i)){
          dist[x+dr[i]][y+dc[i]][(z+1)%4] = dist[x][y][z] + 1;
          if(x+dr[i] == r-1 && y+dc[i] == c-1){
            cout<<dist[x+dr[i]][y+dc[i]][(z+1)%4]<<'\n';
            f = false;
            break;
          }
          q.push(iii((z+1)%4, ii(x+dr[i], y+dc[i])));
        }
      }
    }
    if(f) cout<<"no path to exit\n";
  }
}