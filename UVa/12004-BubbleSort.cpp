//Math
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

ll t, n;

int main(){
  cin>>t;
  for(int i=1; i<=t; i++){
    cin>>n;
    n = n*(n-1)/2;
    cout<<"Case "<<i<<": ";
    if(n&1) cout<<n<<'/'<<2<<'\n';
    else cout<<(n/2)<<'\n';
  }
}