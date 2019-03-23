#include <iostream>
#include <map>
#include <iomanip>
#include <string>
using namespace std;

map<string, int> m;
string s;

int main() {
  int n;
  double x;
  cin>>n;
  cout<<fixed<<setprecision(4);
  getline(cin, s);
  getline(cin, s);
  while(n--){
    x = 0;
    m.clear();
    while(getline(cin, s) && s.length() > 0){
      m[s] += 100;
      x++;
    }
    for(auto a : m){
      cout<<a.first<<' '<<a.second/x<<endl;
    }
    if(n) cout<<endl;
  }
}