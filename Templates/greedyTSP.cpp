#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool visited[40000];
int n, j;
double x[40000], y[40000], d;

const double inf = 100000000;

double dist(int a, int b){
  return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

ifstream fin ("in.txt");

int main() {
  fin>>n;
  for(int i=0; i<n; i++){
    fin>>j>>x[j-1]>>y[j-1];
  }
  int v = 1, cur = 0, nc;
  double m;
  visited[0] = 1;

  while(v<n){
    m = inf;
    for(int i=0; i<n; i++){
      if(!visited[i]){
        if(x[i] - x[cur] >= m) break;
        if(dist(cur, i) < m){
          nc = i;
          m = dist(cur, i);
        }
      }
    }

    d+=m;
    cur=nc;
    visited[cur] = true;
    v++;
    if(v%1000 == 0) cout<<v<<endl;
  }
  d+=dist(cur, 0);

  cout<<fixed<<d<<endl;
}