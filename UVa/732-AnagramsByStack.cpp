#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s, t; 
void dfs(string a, string st, string seq = "i", string res = "", int i = 1){
  if(i == 2*s.length()){
    if(res == t) cout<<seq<<endl;
  } else{
    if(a.size() > 0){
      dfs(a.substr(1), a[0] + st, seq + " i", res, i + 1);
    }
    if(st.length() > 0 && t[res.length()] == st[0]){
      dfs(a, st.substr(1), seq + " o", res + st[0], i + 1);
    }
  }
}
 
int main() {
  while(cin >> s >> t) {
    cout<<"[\n";
    if(s.length() == t.length()) dfs(s.substr(1), string(1, s[0]));
    cout<<"]\n";
  }
}