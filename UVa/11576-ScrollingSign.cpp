//String Matching
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

int c, w, k, t;
string a, b;

bool match(int i){
  for(int j=i; j<k; j++)
    if(a[j] != b[j-i]) return false;
  return true;
}

int main(){
  cin>>c;
  while(c--){
    cin>>k>>w;
    cin>>a;
    t = k;
    for(int i=1; i<w; i++){
      cin>>b;
      for(int i=0; i<=k; i++){
        if(match(i)){
          t += i;
          break;
        }
      }
      a = b;
    }
    cout<<t<<'\n';
  }
}