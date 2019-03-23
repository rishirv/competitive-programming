/*
ID: verma.r1
PROG: fact4
LANG: C++11
*/
#include <fstream>
using namespace std;

int main(){
  ifstream cin ("fact4.in");
  ofstream cout ("fact4.out");
  int n, f=0, i;
  cin>>n;
  int x=n/5;
  while(x){
    f+=x;
    x/=5;
  }
  x=1;
  for(int j=1; j<=n; j++){
    i=j;
    while(f && !(i%2)){
      i/=2;
      --f;
    }
    while(!(i%5)){
      i/=5;
    }
    x=(x*i)%10;
  }
  cout<<x<<endl;
}