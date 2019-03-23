/*
ID: verma.r1
PROG: ditch
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

const int infinity=2147483647;

int main(){
  ifstream cin ("ditch.in");
  ofstream cout ("ditch.out");
  int n, m, a, b, c, maxflow, maxloc, pathcapacity=0, totalflow=0, curnode, nextnode;
  cin>>n>>m;
  int arr[m+1][m+1] {{0}}, source=1, sink=m;
  for(int i=0; i<n; i++){
    cin>>a>>b>>c;
    arr[a][b]+=c;
  }

  int prev[m+1], flow[m+1];
  bool visited[m+1];
  
  while(true){
    for(int i=1; i<=m; i++){
      prev[i]=0;
      flow[i]=0;
      visited[i]=0;
    }
    flow[source]=infinity;
    while(true){
      maxflow=0;
      maxloc=0;
      for(int i=1; i<=m; i++){
        if(flow[i]>maxflow && !visited[i]){
          maxflow=flow[i];
          maxloc=i;
        }
      }
      if(maxloc==0 || maxloc==sink){
        break;
      }
      visited[maxloc]=true;
      for(int i=1; i<=m; i++){
        if(arr[maxloc][i] && flow[i]<min(maxflow, arr[maxloc][i])){
          prev[i]=maxloc;
          flow[i]=min(maxflow, arr[maxloc][i]);
        }
      }
    }
    if(maxloc==0){
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