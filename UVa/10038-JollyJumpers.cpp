#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool arr[3000], f;

int main() {
  arr[0]=1;
  int n, i, j, m;
  while(cin>>n>>i){
    memset(arr+1, 0, n);
    f = 0;
    for(int r=0; r<n-1; r++){
      cin>>j;
      m = max(i,j) - min(i,j);
      if(m>n-1) m = 0;
      if(arr[m] == 1) f = 1;
      arr[m] = 1;
      i=j;
    }
    if(f)
      cout<<"Not jolly\n";
    else
      cout<<"Jolly\n";
  }
}