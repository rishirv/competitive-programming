#include <iostream>
#include <algorithm>
using namespace std;

int x[12], y[12];
int s[12][1<<12];
const int inf = 1000000;
int n, t;

int dist(int i, int j){
  return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}

int main() {
  cin>>t;
  while(t--){
    cin>>n>>n>>x[0]>>y[0]>>n;
    ++n;

    for(int i=1; i<n; i++) cin>>x[i]>>y[i];

    for(int i=0; i<n; i++){
      for(int j=0; j<(1<<n); j++){
        s[i][j] = inf;
      }
    }

    s[0][1] = 0;

    for(int i=1; i<(1<<n); i+=2){
      for(int j=1; j<n; j++){
        if(i & 1<<j){
          for(int k=0; k<n; k++){
            if(j != k && (i & i<<k)){
              s[j][i] = min(s[j][i], s[k][i & ~(1<<j)] + dist(j, k));
            }
          }
        }
      }
    }

    int r = inf;

    for(int i=1; i<n; i++)
      r = min(r, s[i][(1<<n)-1] + dist(0, i));

    cout<<"The shortest path has length "<<r<<'\n';
  }
}