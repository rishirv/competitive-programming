/*
ID: verma.r1
PROG: game1
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  ifstream cin ("game1.in");
  ofstream cout ("game1.out");
  int n, arr[100][100] {0}, s[100][100];
  cin>>n;
  bool flag=n%2;
  for(int i=0; i<n; i++){
    cin>>arr[i][1];
    s[i][1]=arr[i][1];
  }
  for(int j=2; j<=n; j++){
    for(int i=0; i<n+1-j; i++){
      s[i][j]=s[i][j-1]+arr[i+j-1][1];
    }
  }
  for(int j=2; j<=n; j++){
    for(int i=0; i<n+1-j; i++){
      arr[i][j]=s[i][j]-min(arr[i][j-1], arr[i+1][j-1]);
    }
  }
  cout<<arr[0][n]<<" "<<s[0][n]-arr[0][n]<<endl;
}