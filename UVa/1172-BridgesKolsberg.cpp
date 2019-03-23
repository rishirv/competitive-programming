//Clever DP
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string s, os[4000];
int a, b, c, t[4000], dp[2000][2000], br[2000][2000], m, n;

int main(){
  cin>>c;
  while(c--){
    memset(dp, 0, sizeof dp);
    memset(br, 0, sizeof br);
    cin>>a;
    for(int i=0; i<a; i++) cin>>s>>os[i]>>t[i];
    cin>>b;
    for(int i=0; i<b; i++) cin>>s>>os[a+i]>>t[a+i];
    for(int i=0; i<a; i++){
      for(int j=0; j<b; j++){
        if(os[i] == os[a+j] && (i>0 && j>0 ? dp[i-1][j-1] : 0) + t[i] + t[a+j] == dp[i][j]){
          br[i][j] = min(br[i][j], (i>0 && j>0 ? br[i-1][j-1] : 0) + 1);
        }

        if(os[i] == os[a+j] && (i>0 && j>0 ? dp[i-1][j-1] : 0) + t[i] + t[a+j] > dp[i][j]){
          dp[i][j] = (i>0 && j>0 ? dp[i-1][j-1] : 0) + t[i] + t[a+j];
          br[i][j] = (i>0 && j>0 ? br[i-1][j-1] : 0) + 1;
        }

        if(i>0 && dp[i-1][j] == dp[i][j]){
          br[i][j] = min(br[i][j], br[i-1][j]);
        }

        if(i>0 && dp[i-1][j] > dp[i][j]){
          dp[i][j] = dp[i-1][j];
          br[i][j] = br[i-1][j];
        }

        if(j>0 && dp[i][j-1] == dp[i][j]){
          br[i][j] = min(br[i][j], br[i][j-1]);
        }

        if(j>0 && dp[i][j-1] > dp[i][j]){
          dp[i][j] = dp[i][j-1];
          br[i][j] = br[i][j-1];
        }
      }
    }
    if(a == 0 || b == 0) cout<<"0 0\n";
    else cout<<dp[a-1][b-1]<<' '<<br[a-1][b-1]<<'\n';
  }
}