/*
ID: verma.r1
PROG: telecow
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

const int infinity = 2147483647;

int n, m, a, b;
int arr[203][203];
bool visited[203];

double flow(){
  int maxflow, totalflow=0, pathcapacity=0, prev[203], flow[203], maxloc, curnode, nextnode, source=2*a+1, sink=2*b;
  
  while(true){
    for(int i=2; i<=2*n+1; i++){
      prev[i]=0;
      flow[i]=0;
      visited[i]=0;
    }
    flow[source]=infinity;
    while(true){
      maxflow=0;
      maxloc=0;
      for(int i=2; i<=2*n+1; i++){
        if(flow[i]>maxflow && !visited[i]){
          maxflow=flow[i];
          maxloc=i;
        }
      }
      if(maxloc==0 || maxloc==sink){
        break;
      }
      visited[maxloc]=true;
      for(int i=2; i<=2*n+1; i++){
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
	ifstream cin ("telecow.in");
	ofstream cout ("telecow.out");
	cin>>n>>m>>a>>b;
	int x, y, start[m+1], end[m+1];

	for(int i=1; i<=n; i++){
		arr[2*i][2*i+1] = i + 101;
	}

	for(int i=1; i<=m; i++){
		cin>>x>>y;
		arr[2*x+1][2*y] = infinity;
		arr[2*y+1][2*x] = infinity;
	}

	flow();
  
	x = 0;
	for(int i=1; i<=n; i++)
		if(visited[2*i] && !visited[2*i+1])
    		x++;
	cout<<x<<endl;

	bool first = true;

	for(int i=1; i<=n; i++)
	    if(visited[2*i] && !visited[2*i+1]){
        	if(first){
          		first = false;
	        } else{
    	      cout<<' ';
        	}
       		cout<<i;
		}
	cout<<endl;
}