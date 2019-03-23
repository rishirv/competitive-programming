#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int m, n, dp[100][11000], f[100], p[100], cost[101][11000];

int solve(int i=0, int r = 0){
  if(m <= 1800 && r > m) return -100000;
  if(r > m + 200) return -100000;
  if(i == n && r > m && r <= 2000) return -10000;
  if(i == n) return 0;
  if(dp[i][r] >= 0) return dp[i][r];
  return dp[i][r] = max(solve(i+1, r), f[i] + solve(i+1, r+p[i]));
}

int main(){
  while(cin>>m>>n){
    memset(dp, -1, sizeof dp);
    memset(cost, 0, sizeof cost);
    for(int i=0; i<n; i++) cin>>p[i]>>f[i];
    cout<<solve()<<'\n';
  }
}