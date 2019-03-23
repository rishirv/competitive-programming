#include <iostream>
using namespace std;

long long n, t, arr[200][200], m, x;

int main(){
  cin>>t;
  while(t--){
    cin>>n;
    m = -800000;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin>>arr[i][j];
        arr[i+n][j] = arr[i][j+n] = arr[i+n][j+n] = arr[i][j];
      }
    }
    for(int i=0; i<2*n; i++){
      for(int j=0; j<2*n; j++){
        if(i > 0) arr[i][j] += arr[i-1][j];
        if(j > 0) arr[i][j] += arr[i][j-1];
        if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
      }
    }
    for(int i=0; i<n; i++) for(int j=0; j<n; j++)
      for(int k=i; k<i+n; k++) for(int l=j; l<j+n; l++){
        x = arr[k][l];
        if(i > 0) x -= arr[i-1][l];
        if(j > 0) x -= arr[k][j-1];
        if(i > 0 && j > 0) x += arr[i-1][j-1];
        m = max(m, x);
      }
    cout<<m<<'\n';
  }
}