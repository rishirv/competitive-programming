//Easy math
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int arr[10], t, n, j;

int main(){
  cin>>t;
  while(t--){
    cin>>n;
    memset(arr, 0, sizeof arr);
    for(int i=1; i<=n; i++){
      j = i;
      while(j){
        arr[j%10]++;
        j/=10;
      }
    }
    for(int i=0; i<9; i++) cout<<arr[i]<<' ';
    cout<<arr[9]<<'\n';
  }
}