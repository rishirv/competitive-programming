#include <iostream>
using namespace std;

long long a, b, c, arr[20][20][20], n, m, s, x;

int main(){
  cin>>n;
  while(n--){
    m = -(1L<<40);
    cin>>a>>b>>c;
    for(int i=0; i<a; i++){
      for(int j=0; j<b; j++){
        for(int k=0; k<c; k++){
          cin>>arr[i][j][k];
          if(i > 0) arr[i][j][k] += arr[i-1][j][k];
          if(j > 0) arr[i][j][k] += arr[i][j-1][k];
          if(i > 0 && j > 0) arr[i][j][k] -= arr[i-1][j-1][k];
        }
      }
    }
    for(int i=0; i<a; i++) for(int j=0; j<b; j++)
      for(int k=i; k<a; k++) for(int l=j; l<b; l++){
        s = 0;
        for(int h=0; h<c; h++){
          x = arr[k][l][h];
          if(i > 0) x -= arr[i-1][l][h];
          if(j > 0) x -= arr[k][j-1][h];
          if(i > 0 && j > 0) x += arr[i-1][j-1][h];
          s += x;
          m = max(m, s);
          if(s < 0) s = 0;
        }
      }
    cout<<m<<'\n';
    if(n) cout<<'\n';
  }
}