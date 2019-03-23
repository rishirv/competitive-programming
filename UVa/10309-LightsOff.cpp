//Complete Search
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n, a, b, c;
bool arr[11][12], ar[11][12];
char ch;
string s;

void recurse(int i = 1){
  if(i == 11){
    c = a;
    for(int r=0; r<10; r++){
      for(int x=1; x<=10; x++){
        ar[r][x] = arr[r][x];
      }
    }
    for(int r=1; r<10; r++){
      for(int x=1; x<=10; x++){
        if(ar[r-1][x]){
          ++c;
          ar[r-1][x] = !ar[r-1][x];
          ar[r][x] = !ar[r][x];
          ar[r][x+1] = !ar[r][x+1];
          ar[r][x-1] = !ar[r][x-1];
          ar[r+1][x] = !ar[r+1][x];
        }
      }
    }
    for(int i=1; i<=10; i++)
      if(ar[9][i]) return;
    b = min(b, c);
    return;
  }
  recurse(i+1);
  arr[0][i] = !arr[0][i];
  arr[0][i+1] = !arr[0][i+1];
  arr[0][i-1] = !arr[0][i-1];
  arr[1][i] = !arr[1][i];
  ++a;
  recurse(i+1);
  arr[0][i] = !arr[0][i];
  arr[0][i+1] = !arr[0][i+1];
  arr[0][i-1] = !arr[0][i-1];
  arr[1][i] = !arr[1][i];
  --a;
}

int main(){
  while(cin>>s && s !="end"){
    a = 0, b=101;
    for(int i=0; i<10; i++){
      for(int j=1; j<=10; j++){
        cin>>ch;
        arr[i][j] = (ch == 'O');
      }
    }
    recurse();
    cout<<s<<' '<<b<<'\n';
  }
}