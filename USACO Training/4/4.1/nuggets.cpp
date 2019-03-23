/*
ID: verma.r1
PROG: nuggets
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  ifstream cin ("nuggets.in");
  ofstream cout ("nuggets.out");

  int n;
  cin>>n;
  int nuggets[n], m=257;
  for(int i=0; i<n; i++){
    cin>>nuggets[i];
    m=min(m, nuggets[i]);
  }

  bool arr[200001] {0};
  sort(nuggets, nuggets+n);
  
  for(int i=0; i<n; i++)
    arr[nuggets[i]]=1;

  arr[0]=1;
  int x=0;
  int i;
  
  for(i=1; i<=200000; i++){
    for(int j=0; j<n; j++){
      if(i>=nuggets[j] && arr[i-nuggets[j]]){
        arr[i]=1;
        break;
      }
    }
    if(arr[i]==0)
      x=i;
    if(i==x+m){
      cout<<i-m<<endl;
      break;
    }
  }
  if(i==200001)
    cout<<0<<endl;
}