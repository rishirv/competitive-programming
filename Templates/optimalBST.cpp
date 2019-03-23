#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n = 7;
  double v[8] = {0, 0.05, 0.4, 0.08, 0.04, 0.1, 0.1, 0.23};
  double arr[8][8] = {{0}};
  for(int s=0; s<n; s++){
    for(int i=1; i<=n-s; i++){
      arr[i][i+s] = 1000000;
      double m = 0;
      for(int j=i; j<=i+s; j++){
        m += v[j];
        arr[i][i+s] = min(arr[i][i+s], arr[i][j-1] + (j==n ? 0 : arr[j+1][i+s]));
      }
      arr[i][i+s] += m;
    }
  }
  cout<<arr[1][n]<<endl;
}