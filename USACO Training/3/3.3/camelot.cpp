/*
ID: verma.r1
PROG: camelot
LANG: C++11
*/
#include <fstream>
#include <cmath>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

#define FOR(x,y) for(int x=0; x<y; x++)

const int inf=99999999;

int main(){
  ifstream cin ("camelot.in");
  ofstream cout ("camelot.out");
  int r, c, dkx[] {2, 2, 1, 1, -1, -1, -2, -2}, dky[] {1, -1, 2, -2, 2, -2, 1, -1};
  queue<pair<int, int>> s;
  
  cin>>r>>c;

  int knight[r][c][r][c], minDist=inf;
  vector<pair<int, int>> ks;
  pair<int, int> king;
  
  FOR(i, r) FOR(j, c){ 
    FOR(k, r)  FOR(l, c)
      knight[i][j][k][l]=inf;
    knight[i][j][i][j]=0;
    s.push(make_pair(i, j));
    while(s.size()){
      int k=s.front().first;
      int l=s.front().second;
      s.pop();
      FOR(x, 8)
        if(dkx[x]+k>=0 && dkx[x]+k<r && dky[x]+l>=0 && dky[x]+l<c)
          if(knight[i][j][k+dkx[x]][l+dky[x]]>knight[i][j][k][l]+1){
            knight[i][j][k+dkx[x]][l+dky[x]]=knight[i][j][k][l]+1;
            s.push(make_pair(k+dkx[x], l+dky[x]));
          }
    }
  }

  int y, dist[r][c];
  char x;
  cin>>x>>y;
  king=make_pair(y-1, x-'A');
  
  while(cin>>x>>y)
    ks.push_back(make_pair(y-1, x-'A'));

  FOR(i, r) FOR (j, c){
    dist[i][j]=0;
    for(auto p : ks){
      dist[i][j]+=knight[i][j][p.first][p.second];
    }
    dist[i][j]+=max(abs(i-king.first), abs(j-king.second));
    minDist=min(minDist, dist[i][j]);
  }
  
  for(auto k : ks){ //rescued by knight k
    FOR(i, r) FOR(j, c){
      int rescue=knight[i][j][k.first][k.second]+max(abs(i-king.first), abs(j-king.second));
      for(int dx : {-2, -1, 0, 1, 2}){
        for(int dy : {-2, -1, 0, 1, 2}){
          if(dx+king.first>=0 && dx+king.first<r && dy+king.second>=0 && dy+king.second<c){
            rescue=min(rescue, knight[k.first][k.second][dx+king.first][dy+king.second]+knight[dx+king.first][dy+king.second][i][j]+max(abs(dx), abs(dy)));
          }
        }
      }
      minDist=min(minDist, dist[i][j]-knight[i][j][k.first][k.second]-max(abs(i-king.first), abs(j-king.second))+rescue);
    }
  }
  cout<<minDist<<endl;
}