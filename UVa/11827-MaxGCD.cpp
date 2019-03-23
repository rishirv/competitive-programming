//LCM LCD GCD GCF
//Math
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b){
  return a * (b/gcd(a, b));
}

vi f;
int n, m;
string s;

int main(){
  cin>>n;
  cin.ignore();
  while(n--){
    f.clear();
    getline(cin, s);
    stringstream str(s);
    while(str>>m) f.push_back(m);
    m = 0;
    for(int i=0; i<f.size(); i++)
      for(int j=i+1; j<f.size(); j++)
        m = max(m, gcd(f[i], f[j]));
    cout<<m<<'\n';
  }
}