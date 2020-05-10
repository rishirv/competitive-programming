#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef priority_queue<ii, vector<ii>, greater<ii> > pqdi;

double inf = 2000000000;

int gcd(int a, int b) { 
  if (b == 0) return a; 
  return gcd(b, a % b);  
} 

ifstream fin ("falling.in");
ofstream fout ("falling.out");

int main() {
  int n;
  fin>>n;
  int a[n], q[n];
  for(int i=0; i<n; i++) fin>>a[i];
  for(int i=0; i<n; i++){
    fin>>q[i];
    q[i]--;
  }

  for(int i=0; i<n; i++){

    pqdi pq;
    bool v[n];
    double d[n];
    ii frac[n];

    for(int j=0; j<n; j++){
      d[j] = inf;
      v[j] = 0;
    }
    
    d[i] = 0;
    v[i] = 1;
    
    for(int j=0; j<n; j++){
      if(i!=j && ((a[i]-a[j])^(i-j)) >= 0){
        pq.push(make_pair(i, j));
      }
    }

    while(!pq.empty()){
      ii x = pq.top();
      pq.pop();
      
      int t = x.first;
      int s = x.second;
      double w = (a[t]-a[s])/((double) t - s);

      v[s] = 1;
      if(w < d[s]){
        frac[s] = x;
        d[s] = w;
      }

      if(s == q[i]) break;

      for(int j=0; j<n; j++){
        if(j != s){
          w = (a[j]-a[s])/((double) j - s);
          if(!v[j] && w > d[s]){
            pq.push(make_pair(s, j));
          }
        }
      }
    }

    if(d[q[i]] > 1500000000){
      fout<<-1<<'\n';
    } else{
      int r = frac[q[i]].first, s = frac[q[i]].second;
      fout<<abs((a[r]-a[s])/gcd(a[r]-a[s], r-s))<<'/';
      fout<<abs((r-s)/gcd(a[r]-a[s], r-s))<<'\n';
    }
  }
}