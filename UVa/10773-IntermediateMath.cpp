//Easy math
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

double d, v, u;
int t;

int main(){
  cin>>t;
  for(int i=1; i<=t; i++){
    cout<<"Case "<<i<<": ";
    cin>>d>>v>>u;
    if(u<=v || v==0) cout<<"can't determine\n";
    else cout<<setprecision(3)<<fixed<<d/sqrt(u*u-v*v) - d/u<<'\n';
  }
}