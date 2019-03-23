/*
ID: verma.r1
PROG: range
LANG: C++11
*/
#include <fstream>
#include <string>
using namespace std;

int main(){
  ifstream cin ("range.in");
  ofstream cout ("range.out");
  
  int n, s;
  cin>>n;
  string arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  for(int x=2; x<=n; x++){
    s=0;
    for(int i=0; i<n+1-x; i++){
      for(int j=0; j<n+1-x; j++){
        if(arr[i][j]=='1' && arr[i][j+1]=='1' && arr[i+1][j]=='1' && arr[i+1][j+1]=='1'){
          s++;
          arr[i][j]='1';
        } else{
          arr[i][j]='0';
        }
      }
    }
    if(s==0)
      break;
    cout<<x<<" "<<s<<endl;
  }
}