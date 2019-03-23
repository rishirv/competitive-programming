#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[305][305], coins[40][2], t, c, emod, sq, mi;

int main() {
  cin>>t;
  while(t--){
    mi = 1000000;
    memset(dp, 1, sizeof dp);
    dp[0][0] = 0;
    cin>>c>>emod;
    sq = emod * emod;
    for(int i=0; i<c; i++) cin>>coins[i][0]>>coins[i][1];
    for(int i=0; i<=emod; i++){
      for(int j=0; j<=emod; j++){
        for(int k=0; k<c; k++){
          if(i-coins[k][0]>=0 && j-coins[k][1]>=0){
            dp[i][j] = min(dp[i][j], 1+dp[i-coins[k][0]][j-coins[k][1]]);
          }
        }
      }
    }
    for(int i=0, j=emod; i<=emod; i++){
      while(i*i + j*j > sq) j--;
      if(i*i + j*j == sq) mi = min(mi, dp[i][j]);
    }
    if(mi == 1000000) cout<<"not possible\n";
    else cout<<mi<<'\n';
  }
}