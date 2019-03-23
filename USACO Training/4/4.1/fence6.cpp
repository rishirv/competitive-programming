/*
ID: verma.r1
PROG: fence6
LANG: C++11
*/
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int infinity=25600;

int main(){
  ifstream cin ("fence6.in");
  ofstream cout ("fence6.out");
  int s, n=0, x, l, a, b, r; //segments, verticies
  cin>>s;
  int arr[s+1][s+1], path[s][2], length[s]; //dist from vertex a to b (n<=s)
  for(int i=0; i<=s; i++){
    for(int j=0; j<=s; j++){
      arr[i][j]=infinity;
    }
  }
  set<int> v;
  map<set<int>, int> verticies;
  for(int i=0; i<s; i++){
    cin>>x>>l>>a>>b;
    v.insert(x);
    for(int j=0; j<a; j++){
      cin>>r;
      v.insert(r);
    }
    if(!verticies[v]){
      verticies[v]=++n;
    }
    a=verticies[v];
    v.clear();
    v.insert(x);
    for(int j=0; j<b; j++){
      cin>>r;
      v.insert(r);
    }
    if(!verticies[v]){
      verticies[v]=++n;
    }
    b=verticies[v];
    v.clear();
    arr[a][b]=arr[b][a]=l;
    path[i][0]=a;
    path[i][1]=b;
    length[i]=l;
  }
  int m=infinity, dist[n+1], source, numVisited, d;
  for(int e=0; e<s; e++){
    arr[path[e][0]][path[e][1]]=arr[path[e][1]][path[e][0]]=infinity;
    for(int v : {0, 1}){
      bool visited[n+1] {0};
      for(int i=1; i<=n; i++){
        dist[i]=infinity;
      }
      numVisited=0;
      dist[path[e][v]]=0;
      while(numVisited<n){
        d=infinity;
        for(int i=1; i<=n; i++){
          if(!visited[i] && dist[i]<d){
            source=i;
            d=dist[source];
          }
        }
        visited[source]=1;
        for(int i=1; i<=n; i++){
          dist[i]=min(dist[i], dist[source]+arr[source][i]);
        }
        numVisited++;
      }
      if(dist[path[e][!v]]+length[e]>0)
        m=min(dist[path[e][!v]]+length[e], m);
    }
    arr[path[e][0]][path[e][1]]=arr[path[e][1]][path[e][0]]=length[e];
  }
  cout<<m<<endl;
}