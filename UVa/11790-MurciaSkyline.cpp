#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, t, arr[2000][2], w[2000], tr[2000], lis, lds;

int main(){
  cin>>t;
  for(int x=1; x<=t; x++){
    cin>>n;
    lis = lds = 0;
    for(int i=0; i<n; i++) cin>>tr[i];
    for(int i=0; i<n; i++){
      cin>>w[i];
      arr[i][1] = arr[i][0] = w[i];
    }
    for(int i=n-1; i>=0; i--){
      for(int j=i+1; j<n; j++){
        if(tr[i] > tr[j] && arr[j][0] + w[i] > arr[i][0]){
          arr[i][0] = arr[j][0] + w[i];
        } else if(tr[i] < tr[j] && arr[j][1] + w[i] > arr[i][1]){
          arr[i][1] = arr[j][1] + w[i];
        }
      }
      lds = max(lds, arr[i][0]);
      lis = max(lis, arr[i][1]);
    }
    cout<<"Case "<<x<<". ";
    if(lis >= lds) cout<<"Increasing ("<<lis<<"). ";
    cout<<"Decreasing ("<<lds<<").";
    if(lds > lis) cout<<" Increasing ("<<lis<<").";
    cout<<'\n';
  }
}