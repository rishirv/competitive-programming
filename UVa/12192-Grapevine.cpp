#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500], n, m, x, y, q, pos[500][2];

int search(){
  for(int i=0; i<n; i++){
    auto low = lower_bound(arr[i], arr[i]+m, x);
    auto up = upper_bound(arr[i], arr[i]+m, y);
    pos[i][0] = low - arr[i];
    pos[i][1] = up - arr[i] - 1;
  }

  int t = 0;
  for(int i=0; i<n; i++){
    if(i+t < n && pos[i+t][1] >= pos[i][0] + t){
      t++;
      i--;
    }
  }
  return t;
}

int main(){
  while(cin>>n>>m && n!=0 && m!=0){
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cin>>arr[i][j];
      }
    }
    cin>>q;
    for(int i=0; i<q; i++){
      cin>>x>>y;
      cout<<search()<<'\n';
    }
    cout<<"-\n";
  }
}