#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long n, k, m, dp[60][60];

int main() {
  while(cin>>n>>k>>m){
    memset(dp, 0, sizeof dp);
    for(int i=1; i<=m; i++) dp[1][i] = 1;
    for(int i=2; i<=k; i++){
      for(int j=1; j<=n; j++){
        for(int r=1; r<=m; r++){
          if(j-r<1) break;
          dp[i][j] += dp[i-1][j-r];
        }
      }
    }
    cout<<dp[k][n]<<'\n';
  }
}