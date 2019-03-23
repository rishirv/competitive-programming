#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int infinity = 10000000;
int arr[1001][1001];
int n, m;

ifstream fin ("in.txt");
ofstream fout ("out.txt");

int main() {
  fin>>n>>m;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      arr[i][j] = infinity;
    }
    arr[i][i] = 0;
  }

  int x, y, z;

  for(int i=1; i<=m; i++){
    fin>>x>>y>>z;
    arr[x][y] = min(arr[x][y], z);
  }

  x = infinity;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      for(int k=1; k<=n; k++){
        arr[j][k] = min(arr[j][k], arr[j][i]+arr[i][k]);
        x = min(x, arr[j][k]);
      }
    }
  }

  for(int i=1; i<=n; i++){
    if(arr[i][i]<0){
      fout<<"Negative cycle!"<<endl;
      break;
    }
  }
  fout<<x<<endl;
}