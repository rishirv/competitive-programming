//Math
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

ll arr[1000010], n;

int main(){
  arr[3] = 0;
  n = 1;
  for(n=1; n<=500000; n++){
    arr[2+2*n] = arr[1+2*n] + n*n;
    arr[3+2*n] = arr[2+2*n] + n*n+n;
  }
  while(cin>>n && n>2) cout<<arr[n]<<'\n';
}