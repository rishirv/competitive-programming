/*
ID: verma.r1
PROG: stall4
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

const int infinity=2147483647;

int main(){
  ifstream cin ("stall4.in");
  ofstream cout ("stall4.out");
  int n, m, x, y, maxflow, maxloc, pathcapacity=0, totalflow=0, curnode, nextnode;
  cin>>n>>m;
  int arr[n+m+2][n+m+2], source=0, sink=n+m+1;
  memset(arr, 0, sizeof(arr));
  for(int i=1; i<=n; i++){
    arr[0][i]=1;
    cin>>x;
    for(int j=0; j<x; j++){
      cin>>y;
      arr[i][n+y]=1;
    }
  }
  for(int i=n+1; i<n+m+1; i++){
    arr[i][sink]=1;
  }

  int prev[n+m+2], flow[n+m+2];
  bool visited[n+m+2];
  
  while(true){
    for(int i=0; i<n+m+2; i++){
      prev[i]=0;
      flow[i]=0;
      visited[i]=0;
    }
    flow[source]=infinity;
    while(true){
      maxflow=0;
      maxloc=-1;
      for(int i=0; i<n+m+2; i++){
        if(flow[i]>maxflow && !visited[i]){
          maxflow=flow[i];
          maxloc=i;
        }
      }
      if(maxloc==-1 || maxloc==sink){
        break;
      }
      visited[maxloc]=true;
      for(int i=0; i<n+m+2; i++){
        if(arr[maxloc][i] && flow[i]<min(maxflow, arr[maxloc][i])){
          prev[i]=maxloc;
          flow[i]=min(maxflow, arr[maxloc][i]);
        }
      }
    }
    if(maxloc==-1){
      break;
    }
    pathcapacity=flow[sink];
    totalflow+=pathcapacity;
    curnode=sink;
    while(curnode!=source){
      nextnode=prev[curnode];
      arr[nextnode][curnode]-=pathcapacity;
      arr[curnode][nextnode]+=pathcapacity;
      curnode=nextnode;
    }
  }
  cout<<totalflow<<endl;
}