#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <iomanip>
using namespace std;

map<char, int> m;

int main() {
  char c, l[10009];
  int n, k, v, x, t;

  cin>>n;
  while(n--){
    t = 0;
    m.clear();
    cin>>k;
    while(k--){
      cin>>c>>v;
      m[c] = v;
    }
    cin>>x;
    cin.get(c);
    while(x--){
      cin.getline(l, 10009);
      for(int i=0; i<strlen(l); i++){
        t += m[l[i]];
      }
    }
    cout<<t/100<<'.'<<setfill('0')<<setw(2)<<(t%100)<<'$'<<endl;
  }
}