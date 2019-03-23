#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("teamwork.in");
ofstream fout ("teamwork.out");

typedef vector<int> vi;

vi A, arr[10001];
int n, k, x, dp[10001], pre;

int main(){
  fin>>n>>k;
  A.push_back(0);
  for(int i=0; i<n; i++){
    fin>>x;
    A.push_back(x);
  }

  n++;
  for(int i=1; i<n; i++){
    pre = 0;
    arr[i].push_back(pre);
    for(int j=i; j<n; j++){
      pre = max(A[j], pre);
      arr[i].push_back(pre);
    }
  }

  dp[0] = 0;
  for(int i=1; i<n; i++){
    for(int j=1; j<=k; j++){
      if(i-j>=0){
        dp[i] = max(dp[i], dp[i-j]+j*arr[i-j+1][j]);
      } else{
        break;
      }
    }
  }

  fout<<dp[n-1]<<endl;
}