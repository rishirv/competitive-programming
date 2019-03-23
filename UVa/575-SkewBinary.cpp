//Math
//Char input
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
long long n, a;

int main(){
  while(cin.get(ch) && ch!='0'){
    n = a = ch - '0';
    while(cin.get(ch) && ch != '\n'){
      n = 2*n + ch-'0';
      a += ch-'0';
    }
    n = 2*n-a;
    cout<<n<<'\n';
  }
}