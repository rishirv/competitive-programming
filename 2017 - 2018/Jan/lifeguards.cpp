#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

struct Interval{
  int start, end;
};

int n;

bool comp(Interval a, Interval b){
  return (a.start<b.start);
}

int func(Interval ranges[]){
  stack<Interval> results;
  results.push(ranges[0]);
  
  for(int i=1; i<n; i++){
    if(results.top().end>=ranges[i].start){
      Interval y;
      y.start = results.top().start;
      y.end = max(ranges[i].end, results.top().end);
      results.pop();
      results.push(y);
    } else
      results.push(ranges[i]);
  }
  
  int maxTime = 0, high, low;
  while(!results.empty()){
    high=results.top().end;
    low=results.top().start;
    maxTime += high-low;
    results.pop();
  }
  
  return maxTime;
}

int main(){
  ifstream cin ("lifeguards.in");
  ofstream cout ("lifeguards.out");
  
  cin>>n;
  Interval ranges[n];
  int maxTime = 0, start, end;

  for(int i=0; i<n; i++){
	  cin>>ranges[i].start>>ranges[i].end;
  }
  
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  
  sort(ranges, ranges+n, comp);
  
  start = ranges[0].start;
  end = ranges[0].end;
  
  ranges[0].start = ranges[1].start;
  ranges[0].end = ranges[1].end;
  
  maxTime = max(maxTime, func(ranges));
  
  ranges[0].start = start;
  ranges[0].end = end;
  
  for(int i=1; i<n; i++){
    start = ranges[i].start;
    end = ranges[i].end;
    
    ranges[i].start = ranges[i-1].start;
    ranges[i].end = ranges[i-1].end;
    
    maxTime = max(maxTime, func(ranges));
    
    ranges[i].start = start;
    ranges[i].end = end;
  }
  
  cout<<maxTime<<endl;
  return 0;
}