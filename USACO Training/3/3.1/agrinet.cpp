/*
ID: verma.r1
PROG: agrinet
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  ifstream cin ("agrinet.in");
  ofstream cout ("agrinet.out");

  int n, infinity = 1000000, cost=0, num=0;
  cin>>n;
  int arr[n][n], distance[n];
  bool in[n];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>arr[i][j];
    }
    in[i]=false;
    distance[i]=arr[0][i];
  }

  in[0]=1;
  num=1;
  distance[0]=infinity;

  int dist, source;
  while(num<n){
    source=-1;
    for(int i=0; i<n; i++)
      if(!in[i] && distance[i]<(source>0 ? distance[source] : infinity))
        source=i;

    in[source]=1;
    cost+=distance[source];
    num++;

    for(int i=0; i<n; i++)
      distance[i]=min(distance[i], arr[source][i]);
  }
  cout<<cost<<endl;
  return 0;
}