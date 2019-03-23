/*
ID: verma.r1
PROG: starry
LANG: C++11
*/
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
string x;
int skymap[100][100];
vector<int> clusters[502];
vector<int> cluster;
int index[502];
int cur = 1;

ifstream cin ("starry.in");
ofstream cout ("starry.out");

bool similar(vector<int> x, vector<int> y){
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  if(x.size()!=y.size()) return false;
  for(int i=1; i<x.size(); i++)
    if(x[i]-x[i-1] != y[i]-y[i-1]) return false;
  return true;
}

bool compare(int x, int y){
  for(int i=0; i<4; i++){
    for(int& s : clusters[x])
      s = (99 - s%100)*100 + s/100;
    if(similar(clusters[x], clusters[y])) return true;
  }

  for(int& s : clusters[x])
    s = s + 99 - 2*(s%100);

  if(similar(clusters[x], clusters[y])) return true;

  for(int i=0; i<3; i++){
    for(int& s : clusters[x])
      s = (99 - s%100)*100 + s/100;
    if(similar(clusters[x], clusters[y])) return true;
  }

  return false;
}

void floodfill(int i, int j){
  if(skymap[i][j] != 1) return;
  skymap[i][j] = cur;
  clusters[cur].push_back(100*i + j);

  if(i<r-1) floodfill(i+1, j);
  if(j<c-1) floodfill(i, j+1);
  if(i<r-1 && j<c-1) floodfill(i+1, j+1);
  if(i>0) floodfill(i-1, j);
  if(j>0) floodfill(i, j-1);
  if(i>0 && j>0) floodfill(i-1, j-1);
  if(i<r-1 && j>0) floodfill(i+1, j-1);
  if(i>0 && j<c-1) floodfill(i-1, j+1);
}

int main() {
  cin>>c>>r;
  for(int i=0; i<r; i++){
    cin>>x;
    for(int j=0; j<c; j++){
      skymap[i][j] = x.at(j)-'0';
    }
  }

  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if(skymap[i][j]==1){
        cur++;
        floodfill(i, j);
        sort(clusters[cur].begin(), clusters[cur].end());
      }
    }
  }

  int x = 1;
  for(int i=2; i<=cur; i++){
    if(index[i] == 0){
      index[i] = x;
      for(int j=i+1; j<=cur; j++)
        if(compare(i, j))
          index[j] = x;
      x++;
    }
  }

  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if(skymap[i][j]==0) cout<<0;
      else cout<<(char) ('a'-1+index[skymap[i][j]]);
    }
    cout<<endl;
  }
}