/*
ID: verma.r1
PROG: stamps
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  ifstream cin ("stamps.in");
  ofstream cout ("stamps.out");

  int k, n; //At most k stamps from an option of n
  cin>>k>>n;
  int stamps[n], m=0;
  for(int i=0; i<n; i++){
    cin>>stamps[i];
    m=max(m, stamps[i]);
  }

  int arr[m*k+1];
  sort(stamps, stamps+n);

  for(int i=1; i<=m*k; i++)
    arr[i]=k+1;
  
  for(int i=0; i<n; i++)
    arr[stamps[i]]=1;

  arr[0]=0;
  int i=0;
  while(true){
    i++;
    if(i==m*k+1)
      break;
    if(arr[i]==1)
      continue;
    for(int j=0; j<n; j++){
      if(stamps[j]>i){
        break;
      }
      arr[i]=min(arr[i], arr[i-stamps[j]]+1);
    }
    if(arr[i]==k+1){
      break;
    }
  }
  cout<<i-1<<endl;
}