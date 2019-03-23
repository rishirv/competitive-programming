/*
ID: verma.r1
PROG: bigbrn
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin ("bigbrn.in");
ofstream cout ("bigbrn.out");

int n, arr[1000][1000], size=1;
bool impossible[1000][1000];

void square(int i, int j){
  if(i+size >=n || j+size >= n){
    for(int x=i; x<min(i+size, n); x++){
      for(int y=j; y<min(j+size, n); y++){
        impossible[x][y] = true;
      }
    }
    return;
  }
  for(int x=size; x>=0; x--){
    if(arr[i+x][j+size]!=0){
      for(int r=i; r<=i+x; r++){
        for(int c=j; c<=j+size; c++){
          impossible[r][c] = true;
        }
      }
      return;
    }
    if(arr[i+size][j+x]!=0){ 
      for(int r=i; r<=i+size; r++){
        for(int c=j; c<=j+x; c++){
          impossible[r][c] = true;
        }
      }
      return;
    }
  }

  size++;
  square(i, j);
}

void test(int i, int j){
  if(i+size >=n || j+size >= n){
    for(int x=i; x<min(i+size, n); x++){
      for(int y=j; y<min(j+size, n); y++){
        impossible[x][y] = true;
      }
    }
    return;
  }

  for(int x=size-1; x>=0; x--){
    for(int y=size-1; y>=0; y--){
      if(arr[i+x][j+y]!=0){ 
        for(int r=i; r<=i+x; r++){
          for(int c=j; c<=j+y; c++){
            impossible[r][c] = true;
          }
        }
        return;
      }
    }
  }
  square(i, j);
}

int main() {
  int t, r, c;
  cin>>n>>t;

  for(int i=0; i<t; i++){
    cin>>r>>c;
    arr[r-1][c-1]=1;
    impossible[r-1][c-1] = true;
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(!impossible[i][j]){
        test(i, j);
      }
    }
  }

  cout<<size<<endl;
}