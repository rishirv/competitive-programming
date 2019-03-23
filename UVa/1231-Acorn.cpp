//Clever DP
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a, c, t, h, f, x, acorn[2010][2010], dp[2010];

int main(){
  cin>>c;
  while(c--){
    memset(dp, 0, sizeof dp);
    memset(acorn, 0, sizeof acorn);
    cin>>t>>h>>f;
    for(int i=0; i<t; i++){
      cin>>a;
      while(a--){
        cin>>x;
        acorn[i][x]++;
        dp[x] = max(dp[x], acorn[i][x]);
      }
    }
    for(int i=h; i>=0; i--){
      for(int j=0; j<t; j++){
        acorn[j][i] += max(acorn[j][i+1], (i+f <= h ? dp[i+f] : 0));
        dp[i] = max(dp[i], acorn[j][i]);
      }
    }
    cout<<dp[0]<<'\n';
  }
}