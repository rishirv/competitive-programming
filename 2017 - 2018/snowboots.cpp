#include <fstream>
using namespace std;

int main() {
  ifstream cin ("snowboots.in");
  ofstream cout ("snowboots.out");

  int n, b;
  cin >> n >> b;
  
  int tiles[n], depth[b], distance[b], dp[n];
  
  for(int i=0; i<n; i++){
    cin>>tiles[i];
    dp[i] = 300;
  }
  
  dp[0]=0;
  
  for(int i=0; i<b; i++){
    cin >> depth[i] >> distance[i];
  }
  
  for(int i=0; i<n; i++){
    for(int j=dp[i]; j<b; j++){
      for(int k=1; k<=distance[j] && i+k<n; k++){
        if(j<dp[i+k] && depth[j]>=tiles[i] && depth[j]>=tiles[i+k]){
          dp[i+k]=j;
        }
      }
    }
  }
  
  cout<<dp[n-1];
}