#include <iostream>
#include <cmath>
using namespace std;

double x[14], y[14];
double s[14][1<<14];
const double inf = 1000000;
int n;

double dist(int a, int b){
  return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int main() {
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>x[i]>>y[i];
  }

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

  double x = inf;

  for(int i=1; i<n; i++){
    x = min(x, s[i][(1<<n)-1] + dist(0, i));
  }

  cout<<x<<endl;
}