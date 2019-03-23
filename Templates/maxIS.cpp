//Maximum weight independent set of a path graph
#include <iostream>
#include <algorithm>
using namespace std;

double arr[1002], dp[1002];
bool is[1002];
int n;

int main() {
  cin>>n;
  for(int i=2; i<=n+1; i++) cin>>arr[i];

  arr[0] = 0;
  arr[1] = 0;
  dp[2] = arr[2];
  dp[3] = max(arr[2], arr[3]);

  for(int i=3; i<=n+1; i++){
    if(dp[i-1] > dp[i-2] + arr[i]){
      dp[i] = dp[i-1];
    } else{
      dp[i] = dp[i-2] + arr[i];
    }
  }

  int i = n+1;
  while(i>=2){
    if(dp[i-1] < dp[i-2] + arr[i]){
      is[i] = true;
      --i;
    }
    --i;
  }
  for(int i : {1, 2, 3, 4, 17, 117, 517, 997}){
    cout<<is[i+1];
  }
}