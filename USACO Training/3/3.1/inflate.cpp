/*
ID: verma.r1
PROG: inflate
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
  ifstream cin ("inflate.in");
  ofstream cout ("inflate.out");
  int s, n;
  cin>>s>>n;
  int arr[s+1] {0}, times[n], points[n];
  for(int i=0; i<n; i++){
    cin>>points[i]>>times[i];
  }
  for(int i=1; i<=s; i++){
    for(int j=0; j<n; j++){
      if(i-times[j]>=0){
        arr[i]=max(arr[i-times[j]]+points[j], arr[i]);
      }
    }
  }
  cout<<arr[s]<<endl;
}