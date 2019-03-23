/*
ID: verma.r1
PROG: milk2
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

struct Interval{
  int start, end;
};

bool comp(Interval a, Interval b){
  return (a.start<b.start);
}

int n;

int main(){
  ifstream fin ("milk2.in");
  ofstream fout ("milk2.out");
  fin>>n;
  int start, end;
  Interval ranges[n];
  stack<Interval> results;
  for(int i=0; i<n; i++){
	  fin>>start>>end;
	  ranges[i]=Interval {start, end};
  }
  sort(ranges, ranges+n, comp);
  results.push(ranges[0]);
  for(int i=1; i<n; i++){
    if(results.top().end>=ranges[i].start){
      Interval y {results.top().start, max(ranges[i].end, results.top().end)};
      results.pop();
      results.push(y);
    } else
      results.push(ranges[i]);
  }
  int maxIdle=0, high=results.top().end, low=results.top().start, maxMilk=high-low;
  results.pop();
  while(!results.empty()){
    high=results.top().end;
    maxIdle=max(maxIdle, low-high);
    low=results.top().start;
    maxMilk=max(maxMilk, high-low);
    results.pop();
  }
  fout<<maxMilk<<" "<<maxIdle<<endl;
  return 0;
}