#include <iostream>
using namespace std;

int t, n, d, x, j, m, arr[210];
char c, _;

int main(){
  cin>>t;
  for(int i=1; i<=t; i++){
    cin>>n>>d;
    j = 2;
    while(n--){
      cin>>c>>_>>x;
      arr[j++] = x;
      if(c == 'B') arr[j++] = x;
    }
    arr[j++] = d;
    arr[j++] = d;
    m = 0;
    for(int k=0; k<j-2; k++){
      if(arr[k+2]-arr[k] > m) m = arr[k+2] - arr[k];
    }
    cout<<"Case "<<i<<": "<<m<<'\n';
  }
}