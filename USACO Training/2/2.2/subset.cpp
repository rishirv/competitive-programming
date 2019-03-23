/*
ID: verma.r1
PROG: subset
LANG: C++11
*/
#include <fstream>
using namespace std;

int d, n, arr[40] {0}, map[40][781] {0};
int construct_tuple(int x=n-1, int s=d){
  if(s==0 || s==arr[x]){
    return 1;
  }
  if(s<0 || x==0 || s>arr[x]){
    return 0;
  }
  // cout<<s<<" "<<x<<endl;
  if(!map[x-1][s]){
    map[x-1][s]=construct_tuple(x-1, s);
  }
  if(!map[x-1][s-x]){
    map[x-1][s-x]=construct_tuple(x-1, s-x);
  }
  return map[x-1][s]+map[x-1][s-x];
}

int main(){
  ifstream cin ("subset.in");
  ofstream cout ("subset.out");
  int count=0;
  cin>>n;
  for(int i=1; i<=n; i++){
    arr[i]=i*(i+1)/2;
  }
  d=arr[n];
  if(!(d%2)){
    d/=2;
    count=construct_tuple();
  }
  cout<<count<<endl;
}