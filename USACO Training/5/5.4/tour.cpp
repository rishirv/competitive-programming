/*
ID: verma.r1
PROG: tour
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, v;
bool arr[100][100], a=false;
double dp[100][100];
string s, t;
unordered_map<string, int> c;

bool debug = false;

ifstream fin ("tour.in");
ofstream fout ("tour.out");

int move(int x, int y){
  if(x==n-1 && y==n-1) a=true;
  if(dp[x][y] >= 0) return dp[x][y];
  int m = -1;
  if(x<=y){
    for(int i=x+1; i<n; i++)
      if(arr[x][i] && (i!=y || i == n-1)){
        m = max(m, move(i, y) + 1);
      }
  } else{
    for(int i=y+1; i<n; i++)
      if(arr[y][i] && (i!=x || i == n-1)){
        m = max(m, move(x, i) + 1);
      }
  }
  dp[x][y] = dp[y][x] = m;
  return m;
}

int main() {
  fin>>n>>v;

  for(int i=0; i<n; i++){
    fin>>s;
    c.insert(make_pair(s, i));
  }

  for(int i=0; i<v; i++){
    fin>>s>>t;
    arr[c[s]][c[t]] = true;
    arr[c[t]][c[s]] = true;
  }

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      dp[i][j]=-1;

  dp[n-1][n-1] = 0;
  int x = move(0, 0);

  if(a) fout<<x<<endl;
  else fout<<1<<endl;
}