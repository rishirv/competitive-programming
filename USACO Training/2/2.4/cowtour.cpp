/*
ID: verma.r1
PROG: cowtour
LANG: C++11
*/
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int n, x[150], y[150];
bool adj[150][150], arr[150][150];
double dist[150][150], largest=0;
const int infinity = 1000001;
ifstream cin ("cowtour.in");
ofstream cout ("cowtour.out");

double distance(int i, int j){
  return sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));  
}

double build(int i, int j){
  double most1=0, most2=0, diameter;
  for(int k=0; k<n; k++){
    if(dist[i][k]>most1 && dist[i][k]<infinity)
      most1=dist[i][k];
    if(dist[j][k]>most2 && dist[j][k]<infinity)
      most2=dist[j][k];
  }
  diameter = distance(i,j)+most1+most2;
  if(diameter>=largest){
    return diameter;
  }
  for(int l=0; l<n; l++){
    if(arr[i][l] || arr[j][l]){
      for(int k=0; k<n; k++){
        if((arr[i][k] || arr[j][k]) && arr[l][k]){
          diameter=max(diameter, dist[l][k]);
        }
      }  
    }
  }
  return diameter;
}

int main(){
  double diameter = infinity;
  string row;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>x[i]>>y[i];
  }
  for(int i=0; i<n; i++){
    cin>>row;
    for(int j=0; j<n; j++){
      adj[i][j]=row[j]-'0';
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      dist[i][j]=(adj[i][j] ? distance(i, j) : infinity);
    }
    dist[i][i]=0;
  }
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        if(dist[i][k]+dist[k][j] < dist[i][j])
          dist[i][j]=dist[i][k]+dist[k][j];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(dist[i][j] && dist[i][j]<infinity){
        arr[i][j]=1;
        largest=max(largest, dist[i][j]);
      } else{
       arr[i][j]=0;
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(dist[i][j]==infinity){
        diameter=min(diameter, build(i,j));
      }
    }
  }
  cout<<setprecision(6)<<fixed<<diameter<<endl;
}