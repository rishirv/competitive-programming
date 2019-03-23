//Clever DP
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;

int m, n, arr[200], dp[(1<<12)][(1<<12)], x;
bitset<20> b;

int backtrack(int i = 0, int j = 0){
  if(dp[i][j] >= 0) return dp[i][j];
  x = 0;
  for(int k=0; k<n; k++) if((arr[k] & i) == j) x++;
  if(x == 0 || x == 1) return dp[i][j]=0;
  dp[i][j] = 11;
  for(int k=0; k<m; k++){
    if((i | (1<<k)) != i){
      dp[i][j] = min(dp[i][j], 1 + max(backtrack(i | (1<<k), j), backtrack(i | (1<<k), j | (1<<k))));
    }
  }
  return dp[i][j];
}

int main(){
  while(cin>>m>>n && m != 0){
    memset(dp, -1, sizeof dp);
    for(int i=0; i<n; i++){
      cin>>b;
      arr[i] = (int) b.to_ulong();
    }
    cout<<backtrack()<<'\n';
  }
}