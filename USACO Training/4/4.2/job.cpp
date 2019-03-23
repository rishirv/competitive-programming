/*
ID: verma.r1
PROG: job
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define f(a) for(int i=0; i<a; i++)
const int inf = 2147483647;

int main(){
  ifstream cin ("job.in");
  ofstream cout ("job.out");

  int n, a, b;
  cin>>n>>a>>b;
  int aTimes[a] {0}, bTimes[b] {0}, aJobs[n] {0}, bJobs[n] {0}, aFinish[a] {0}, bFinish[b] {0}, minTime, index;
  
  f(a) cin>>aTimes[i];
  f(b) cin>>bTimes[i];
  
  for(int i=0; i<n; i++){
    minTime=inf, index=-1;
    for(int j=0; j<a; j++){
      if(aFinish[j]+aTimes[j]<minTime){
        minTime=aFinish[j]+aTimes[j];
        index=j;
      }
    }
    aFinish[index]+=aTimes[index];
    aJobs[i]=minTime;
  }
  
  cout<<aFinish[index]<<" ";
  
  for(int i=n-1; i>=0; i--){
    minTime=inf, index=-1;
    for(int j=0; j<b; j++){
      if(bFinish[j]+bTimes[j]<minTime){
        minTime=bFinish[j]+bTimes[j];
        index=j;
      }
    }
    bFinish[index]+=bTimes[index];
    bJobs[i]=minTime;
  }
  
  int time=0;
  
  f(n)
    time=max(time, aJobs[i]+bJobs[i]);
    
  cout<<time<<endl;
  
  return 0;
}
