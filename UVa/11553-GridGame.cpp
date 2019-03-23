#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[8][8], t, n, m, x;

int main() {
  cin>>t;
  while(t--){
    cin>>n;
    m = 10000;
    int p[] = {0, 1, 2, 3, 4, 5, 6, 7};
    memset(arr, 0, sizeof arr);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin>>arr[i][j];
      }
    }
    do{
      x = 0;
      for(int i=0; i<n; i++) x += arr[i][p[i]];
      m = min(m, x);
    } while(next_permutation(p, p+n));
    cout<<m<<'\n';
  }
}