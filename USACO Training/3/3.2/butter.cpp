/*
ID: verma.r1
PROG: butter
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int infinity = 2147483647;

int cows[500]; //pastures of cows
int a[801][801] {0}; //adjacency
int d[801]; //distance 
bool v[801]; //visited
int n, p, c, minDist=infinity;
vector<int> f[801]; //neighbors

void solve(int source){
  int numVisited=0, dist;
  queue<int> q;

  for(int i=1; i<=p; i++){
    d[i]=infinity;
    v[i]=0;
  }

  d[source]=0;
  v[source]=1;
  q.push(source);
  
  while(!q.empty()){
    int x = q.front();
    q.pop();
    v[x]=0;
    
    for(int i : f[x]){
      if(d[x]+a[x][i]<d[i]){
        d[i]=d[x]+a[x][i];
        if(!v[i]){
          q.push(i);
          v[i]=1;
        }
      }
    }
  }
  
  dist=0;
  for(int j=0; j<n; j++)
    dist+=d[cows[j]];
  
  if(dist<minDist)
    minDist=dist;
}

int main(){
  ifstream cin ("butter.in");
  ofstream cout ("butter.out");
  
  int x, y, z;
  cin>>n>>p>>c;
  
  for(int i=0; i<n; i++)
    cin>>cows[i];
  
  for(int i=0; i<c; i++){
    cin>>x>>y>>z;
    a[x][y]=a[y][x]=z;
    f[x].push_back(y);
    f[y].push_back(x);
  }
  
  for(int i=1; i<=p; i++)
    solve(i);
  
  cout<<minDist<<endl;
}