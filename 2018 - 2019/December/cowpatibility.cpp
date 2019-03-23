#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>
using namespace std;

ifstream cin ("cowpatibility.in");
ofstream cout ("cowpatibility.out");

bitset<50000> visited;
map<int, bitset<50000>> arr;
int n, x, m;

int main(){
  cin>>n;
  for(int i=0; i<n; i++){
    visited.reset();
    for(int j=0; j<5; j++){
      cin>>x;
      visited |= arr[x];
      arr[x].set(i);
    }
    m += i - visited.count();
  }
  cout<<m<<endl;
}