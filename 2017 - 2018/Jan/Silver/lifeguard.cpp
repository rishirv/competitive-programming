#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval{
  int start, end;
};

int n, intPos = 0;

bool comp(Interval a, Interval b){
  return (a.start<b.start);
}

vector<Interval> results;
int pos[100000], maxTime = 0, t = 0;
Interval ranges[100000];

int condense(int p){
  Interval a;
  a.start = -1;
  a.end = -1;
  int m = maxTime - results[pos[p]].end + results[pos[p]].start;

  for(int i=0; i<n; i++){
    if(i!=p && pos[i] == pos[p]){
      if(a.end>=ranges[i].start){
        a.end = max(ranges[i].end, a.end);
      } else{
        m = a.end - a.start;
        a=ranges[i];
      }
    }
  }
  
  t = max(t, m + a.end - a.start);
}

void func(){
  results.push_back(ranges[0]);
  
  for(int i=1; i<n; i++){
    if(results.back().end>=ranges[i].start){
      results.back().end = max(ranges[i].end, results.back().end);
    } else{
      results.push_back(ranges[i]);
      intPos++;
    }
    pos[i] = intPos;
  }
  
  int high, low;
  for(Interval i : results){
    maxTime += i.end-i.start;
  }
}

int main(){
  ifstream cin ("lifeguards.in");
  ofstream cout ("lifeguards.out");
  
  cin>>n;

  for(int i=0; i<n; i++)
    cin>>ranges[i].start>>ranges[i].end;
  
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  
  sort(ranges, ranges+n, comp);
  func();
  
  for(int i=0; i<n; i++)
    condense(i);

  cout<<t<<endl;

  return 0;
}