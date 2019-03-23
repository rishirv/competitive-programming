/*
ID: verma.r1
PROG: theme
LANG: C++11
*/
#include <fstream>
using namespace std;

int n, notes[5000];

int main() {
  ifstream cin ("theme.in");
  ofstream cout ("theme.out");

  int prev, cur, max = 0, x;
  cin >> n >> prev;
  for(int i=0; i<n-1; i++){
    cin >> cur;
    notes[i] = cur - prev;
    prev = cur;
  }

  for(int j=5; j<n-1; j++){
    x=0;
    for(int i=0; i+j<n-1; i++){
      if(x<j-1 && notes[i]==notes[i+j]){
        x++;
      } else{
        if(x>max) max=x;
        x=0;
      }
    }
    if(x>max) max=x;
  }


  if(max<4) cout<<0<<endl;
  else cout<<max+1<<endl;
  return 0;
}