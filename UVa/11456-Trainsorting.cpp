#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, t, arr[2000][2], tr[2000], m;

int main(){
  cin>>t;
  while(t--){
    for(int i=0; i<2000; i++) arr[i][0]=arr[i][1]=1;
    cin>>n;
    m = 0;
    if(n == 0){
      cout<<0<<'\n';
      continue;
    }
    for(int i=0; i<n; i++) cin>>tr[i];
    for(int i=n-1; i>=0; i--){
      for(int j=i+1; j<n; j++){
        if(tr[i] > tr[j] && arr[j][0] + 1 > arr[i][0]){
          arr[i][0] = arr[j][0] + 1;
        } else if(tr[i] < tr[j] && arr[j][1] + 1 > arr[i][1]){
          arr[i][1] = arr[j][1] + 1;
        }
      }
      m = max(m, arr[i][0]+arr[i][1]-1);
    }
    cout<<m<<'\n';
  }
}