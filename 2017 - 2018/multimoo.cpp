#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int board[250][250];
int clusterNum[250][250];
vector<set<int>> edges(62500);
vector<int> clusterSize(62500);
vector<int> clusterId(62500);
set<int> joins;
int cur = 0;

ifstream cin ("multimoo.in");
ofstream cout ("multimoo.out");

void floodfill(int i, int j, int num){
  if(board[i][j] != num || clusterNum[i][j] != 0) return;
  clusterNum[i][j] = cur;
  clusterSize[cur]++;

  if(i<n-1) floodfill(i+1, j, num);
  if(j<n-1) floodfill(i, j+1, num);
  if(i>0) floodfill(i-1, j, num);
  if(j>0) floodfill(i, j-1, num);
}

void floodjoin(int i, int j, int x){
  joins.insert(x);
  for(int y : edges[x]){
    if((clusterId[y] == i || clusterId[y] == j) &&  joins.find(y) == joins.end()){
      floodjoin(i, j, y);
    }
  }
}

int main() {
  cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>board[i][j];
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(clusterNum[i][j] == 0){
        cur++;
        clusterId[cur] = board[i][j];
        floodfill(i, j, board[i][j]);
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i<n-1 && board[i][j] != board[i+1][j]){
        edges[clusterNum[i][j]].insert(clusterNum[i+1][j]);
        edges[clusterNum[i+1][j]].insert(clusterNum[i][j]);
      }
      if(j<n-1 && board[i][j] != board[i][j+1]){
        edges[clusterNum[i][j]].insert(clusterNum[i][j+1]);
        edges[clusterNum[i][j+1]].insert(clusterNum[i][j]);
      }
    }
  }

  int m = 0;
  for(int i : clusterSize){
    if(i>m) m = i;
  }
  cout<<m<<endl;

  m = 0;

  for(int i=1; i<=cur; i++){
    for(int j : edges[i]){
      if(j>i){
        joins.clear();
        floodjoin(clusterId[i], clusterId[j], i);
        int x = 0;
        for(int k : joins){
          x+=clusterSize[k];
        }
        if(x > m) m=x;
      }
    }
  }

  cout<<m<<endl;
}