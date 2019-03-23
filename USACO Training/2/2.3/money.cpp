/*
ID: verma.r1
PROG: money
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ifstream cin ("money.in");
  ofstream cout ("money.out");
  int n, s, c;
  vector<int> coins;
  cin>>n>>s;
  long long arr[s+1] {1};
  for(int i=0; i<n; i++){
    cin>>c;
    coins.push_back(c);
  }
  sort(coins.begin(), coins.end());
  for(int c: coins){
    for(int i=1; i<=s; i++){
      if(i-c<0){
        continue;
      }
      arr[i]+=arr[i-c];
    }
  }
  cout<<arr[s]<<endl;
}