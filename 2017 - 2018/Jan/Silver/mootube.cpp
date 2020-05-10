#include <fstream>
#include <algorithm>
using namespace std;

int main() {
  ifstream cin ("mootube.in");
  ofstream cout ("mootube.out");

  int n, q, x, y;
  cin>>n>>q;
  int arr[n+1][n+1], k[q], v[q];
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      arr[i][j]=0;
    }
  }
  
  for(int i=0; i<n-1; i++){
    cin>>x>>y>>arr[x][y];
    arr[y][x] = arr[x][y];
  }
  
  for(int i=0; i<q; i++){
    cin>>k[i]>>v[i];
  }
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(!arr[i][j]){
        for(int k=1; k<=n; k++){
          if(arr[i][k] && arr[j][k]){
            arr[i][j] = min(arr[i][k], arr[j][k]);
            arr[j][i] = arr[i][j];
          }
        }
      }
    }
  }
  
  int c;

  for(int i=0; i<q; i++){
    c=0;
    for(int j=1; j<=n; j++){
      if(j!=v[i] && arr[v[i]][j]>=k[i]){
        c++;
      }
    }
    cout<<c<<endl;
  }
}