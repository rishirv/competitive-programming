//Math
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

char ch;
int i;

int main(){
  while(cin>>ch){
    i = ch-'0';
    while(cin>>ch && ch != '#'){
      if(ch == '\n') continue;
      i*=2;
      i+=ch-'0';
      i%=131071;
    }
    cin.ignore();
    if(i == 0) cout<<"YES\n";
    else cout<<"NO\n";
  }
}