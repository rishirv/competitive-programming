/*
ID: verma.r1
PROG: snail
LANG: C++11
*/
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int arr[120][120];
int n, b;

ifstream cin ("snail.in");
ofstream cout ("snail.out");

int dfs(int i, int j, int x, int y){
  arr[i][j] = 2;
  int s=0;

  if(i+x >= 0 && i+x < n && j+y >= 0 && j+y < n && arr[i+x][j+y]==2){
    s=0;
  } else if(i+x >= 0 && i+x < n && j+y >= 0 && j+y < n && arr[i+x][j+y]==0){
    s=dfs(i+x, j+y, x, y);
  } else{
    if(i+y >= 0 && i+y < n && j+x >= 0 && j+x < n && arr[i+y][j+x] == 0){
      s=max(s, dfs(i+y, j+x, y, x));
    }
    if(i-y >= 0 && i-y < n && j-x >= 0 && j-x < n && arr[i-y][j-x] == 0){
      s=max(s, dfs(i-y, j-x, -y, -x));
    }
  }

  arr[i][j] = 0;
  return 1+s;
}

int main() {
  cin>>n>>b;
  string s;

  for(int i=0; i<b; i++){
    cin>>s;
    arr[atoi(s.substr(1).data())-1][s[0]-'A'] = 1;
  }

  cout<<max(dfs(0, 0, 1, 0), dfs(0, 0, 0, 1))<<endl;

  return 0;
}