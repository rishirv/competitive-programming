/*
ID: verma.r1
PROG: nocows
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
  int s, n, arr[200][100] {0};
  ifstream cin ("nocows.in");
  ofstream cout ("nocows.out");
  cin>>s>>n;
  
  for(int i=1; i<=n; i++){
    arr[1][i]=1;
  }
  
  for(int j=1; j<=n; j++){
    for(int i=1; i<=s; i++){
      for(int k=1; k<i-1; k+=2){
        arr[i][j]+=arr[k][j-1]*arr[i-1-k][j-1];
      }
      arr[i][j]%=9901;
    }
  }
  
  cout<<(arr[s][n]-arr[s][n-1]+9901)%9901<<endl;
  return 0;
}