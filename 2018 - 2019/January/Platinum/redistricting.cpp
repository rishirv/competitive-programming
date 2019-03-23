#include <fstream>
#include <cstring>
using namespace std;

int n, k, dp[400000], count[400000];
char str[400000];

ifstream cin ("redistricting.in");
ofstream cout ("redistricting.out");

int lose(int i, int j){
  if(count[i+j] - count[i] >= (j+1)/2) return 1;
  return 0;
}

int main(){
  cin>>n>>k>>str;
  for(int i=0; i<=n; i++) dp[i] = 400000;
  for(int i=1; i<=n; i++){
    count[i] = count[i-1];
    if(str[i-1] == 'G') count[i]++;
  }
  dp[0] = 0;
  for(int i=0; i<n; i++){
    for(int j=1; j<=k; j++){
      if(i+j <= n) dp[i+j] = min(dp[i+j], dp[i] + lose(i, j));
      else break;
    }
  }
  cout<<dp[n]<<'\n';
}