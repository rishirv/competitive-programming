/*
ID: verma.r1
PROG: maze1
LANG: C++11
*/
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  ifstream cin ("maze1.in");
  ofstream cout ("maze1.out");
  int c, r;
  
  cin>>c>>r;
  
  bool visited[100][38] {{0}};
  int distance[100][38] {{3801}};
  string rows[201];
  
  cin.ignore();
  
  for(int i=0; i<=2*r; i++){
    getline(cin, rows[i]);
  }
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      distance[i][j]=3801;
      visited[i][j]=0;
    }
  }

  for(int i=0; i<c; i++){
    if(rows[0][2*i+1]==' '){
      distance[0][i]=1;
    }
    if(rows[2*r][2*i+1]==' '){
      distance[r-1][i]=1;
    }
  }
  for(int i=0; i<r; i++){
    if(rows[2*i+1][0]==' '){
      distance[i][0]=1;
    }
    if(rows[2*i+1][2*c]==' '){
      distance[i][c-1]=1;
    }
  }
  
  int n=r*c, numVisited=0, dist=1, i, j, a, b, x[4] {0, 1, 0, -1}, y[4] {-1, 0, 1, 0};
  while(numVisited<n){
    for(i=0; i<r; i++){
      for(j=0; j<c; j++){
        if(!visited[i][j] && distance[i][j]==dist){
          break;
        }
      }
      if(j<c){
        break;
      }
    }
    if(i==r){
      dist++;
      continue;
    }
    a=2*i+1;
    b=2*j+1;
    visited[i][j]=1;
    
    for(int k=0; k<4; k++){
      if(rows[a+y[k]][b+x[k]]==' ' && (i+y[k]<r) && (i+y[k]>=0) && (j+x[k]<c) && (j+x[k]>=0)){
        distance[i+y[k]][j+x[k]]=min(distance[i+y[k]][j+x[k]], distance[i][j]+1);
      }
    }
    numVisited++;
  }
  dist=0;
  for(i=0; i<r; i++){
    for(j=0; j<c; j++){
      if(distance[i][j]>dist){
        dist=distance[i][j];
      }
    }
  }
  cout<<dist<<endl;
}