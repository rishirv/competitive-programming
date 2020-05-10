//Simple
#include <iostream>
#include <vector>
using namespace std;

int n, k, x;
vector<int> v;

int main(){
  cin>>n;
  while(n--){
    cin>>k;
    v.clear();
    for(int i=1; i<=k; i++) v.push_back(i);
    for(int i=0; i<k-1; i++){
      cin>>x;
      cout<<v[x]<<' ';
      v.erase(v.begin()+x);
    }
    cin>>x;
    cout<<v[0]<<'\n';
  }
}