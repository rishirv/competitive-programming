/*
ID: verma.r1
PROG: comehome
LANG: C++11
*/
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

const int infinity = 10000001;
const int size = 'z'+1;

int main(){
  ifstream cin ("comehome.in");
  ofstream cout ("comehome.out");
  set<char> s;
  int p, x, n, numVisited=0, dist;
  char a, b, source='Z', newSource;
  
  int adj[size][size] {0}, distance[size];
  bool visited[size];
  
  for(int i='A'; i<='z'; i++){
    distance[i]=infinity;
  }
  
  distance['Z']=0;
  visited['Z']=1;
  
  for(int i='A'; i<='z'; i++){
    if(adj['Z'][i]){
      distance[i]=adj['Z'][i];
    }
  }
  
  cin>>p;
  for(int i=0; i<p; i++){
    cin>>a>>b>>x;
    s.insert(a);
    s.insert(b);
    if(adj[a][b]){
      adj[a][b]=adj[b][a]=min(x, adj[a][b]);
    } else{
      adj[a][b]=adj[b][a]=x;
    }
  }
  
  n=s.size();

  while(numVisited<n){
    dist=infinity;
    for(int i='A'; i<='z'; i++){    
      if(!visited[i] && distance[i]<dist){
        source=i;
        dist=distance[i];
      }
    }
    visited[source]=1;
    for(int i='A'; i<='z'; i++){
      if(adj[source][i]){
        if(distance[source]+adj[source][i]<distance[i]){
          distance[i]=distance[source]+adj[source][i];
        }
      }
    }
    numVisited++;
  }
  dist=infinity;
  for(int i='A'; i<='Y'; i++){
    if(distance[i]<dist){
      source=i;
      dist=distance[i];
    }
  }
  cout<<source<<" "<<dist<<endl;
}