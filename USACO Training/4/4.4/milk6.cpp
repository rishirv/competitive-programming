/*
ID: verma.r1
PROG: milk6
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

const double infinity=4000000000000;
double arr[33][33];
int n, m;
bool visited[33];

double flow(){
  double maxflow, totalflow=0, pathcapacity=0, prev[n+1], flow[n+1];
  int maxloc, curnode, nextnode, source=1, sink=n;
  
  while(true){
    for(int i=1; i<=n; i++){
      prev[i]=0;
      flow[i]=0;
      visited[i]=0;
    }
    flow[source]=infinity;
    while(true){
      maxflow=0;
      maxloc=0;
      for(int i=1; i<=n; i++){
        if(flow[i]>maxflow && !visited[i]){
          maxflow=flow[i];
          maxloc=i;
        }
      }
      if(maxloc==0 || maxloc==sink){
        break;
      }
      visited[maxloc]=true;
      for(int i=1; i<=n; i++){
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
  
  return totalflow;
}

int main(){
  ifstream cin ("milk6.in");
  ofstream cout ("milk6.out");
  cin>>n>>m;
  int a, b, c, start[m+1], end[m+1];
  for(int i=1; i<=m; i++){
    cin>>a>>b>>c;
    arr[a][b] += c*1001 + 1001 + i;
    start[i]=a;
    end[i]=b;
  }
  double f = flow();
  int x = 0;
  for(int i=1; i<=m; i++)
    if(visited[start[i]] && !visited[end[i]]){
      f -= i + 1001;
      x++;
    }
  cout<<(int) (f/1001.0)<<' '<< x <<endl;
  for(int i=1; i<=m; i++)
    if(visited[start[i]] && !visited[end[i]])
      cout<<i<<endl;
}