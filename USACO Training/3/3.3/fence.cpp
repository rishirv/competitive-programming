/*
ID: verma.r1
PROG: fence
LANG: C++11
*/
#include <fstream>
#include <stack>
#include <vector>
#include <set>
using namespace std;

int n, x[501] {0}, f[501][501] {{0}};
vector<int> path, odd;
stack<int> s;

void tour(int i){
  int j;
  s.push(i);
  while(s.size()){
    i=s.top();
    for(j=1; j<=500; j++){
      if(f[i][j]){
        break;
      }
    }
    if(j==501){
      path.push_back(i);
      s.pop();
    } else{
      f[i][j]--;
      f[j][i]--;
      s.push(j);
    }
  }
}

int main(){
  ifstream cin ("fence.in");
  ofstream cout ("fence.out");
  int a, b, i, start;
  cin>>n;
  for(i=0; i<n; i++){
    cin>>a>>b;
    f[a][b]++;
    f[b][a]++;
    x[a]++;
    x[b]++;
  }

  for(i=1; i<=500; i++){
    if(x[i]){
      start=i;
      break;
    }
  }

  for(i=1; i<=n; i++){
    if(x[i]%2){
      start=i;
      break;
    }
  }
  
  tour(start);
  
  for(int i=n; i>=0; i--){
    cout<<path[i]<<endl;
  }
}