/*
ID: verma.r1
PROG: concom
LANG: C++11
*/
#include <fstream>
#include <set>
using namespace std;
int n, p[101][101] {0}; //a has 60% of b -> p[a][b]=60
bool c[101][101] {0}; //a controls b -> c[a][b]=1
set<int> comps;
ifstream cin ("concom.in");
ofstream cout ("concom.out");

void solve(){
  for(int i=1; i<=100; i++){
    for(int j=1; j<=100; j++){
      if(!c[i][j] && i!=j){
        int sum=0;
        for(int k=1; k<=100; k++){
          if(c[i][k]){
            sum+=p[k][j];
          }
        }
        if(sum>50){
          c[i][j]=1;
          solve();
          return;
        }
      }
    }
  }
}

int main(){
  cin>>n;

  int a, b, k;
  for(int i=0; i<n; i++){
    cin>>a>>b>>k;
    p[a][b]=k;
    if(k>50){
      c[a][b]=1;
    }
    comps.insert(a);
    comps.insert(b);
  }
  for(int i=1; i<=100; i++){
    c[i][i]=1;
  }
  solve();
  for(int i=1; i<=100; i++){
    for(int j=1; j<=100; j++){
      if(c[i][j] && i!=j){
        cout<<i<<" "<<j<<endl;
      }
    }
  }
  return 0;
}