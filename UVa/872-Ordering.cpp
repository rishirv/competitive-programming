#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;

int t, idx, c;
vi adj[30];
vector<string> v;
int map[30], val[30], ind[30];
bool visited[30];
string str, s;

int id(char i){
  if(map[i-'A']) return map[i-'A'];
  val[++idx] = i;
  return map[i-'A'] = idx;
}

void backtrack(int a = 0){
  if(a == idx){
    v.push_back(s);
  }
  for(int i=1; i<=idx; i++){
    if(!visited[i] && ind[i]==0){
      visited[i] = true;
      for(int j : adj[i]){
        ind[j]--;
      }
      s[c++] = val[i];
      backtrack(a+1);
      --c;
      visited[i] = false;
      for(int j : adj[i]){
        ind[j]++;
      }
    }
  }
}

int main() {
  cin>>t;
  cin.ignore();
  while(t--){
    memset(map, 0, sizeof map);
    memset(val, 0, sizeof val);
    memset(visited, 0, sizeof visited);
    memset(ind, 0, sizeof ind);
    v.clear();
    for(int i=0; i<30; i++) adj[i].clear();
    idx = c = 0;
    getline(cin, str);
    getline(cin, str);
    for(int i=0; i<str.length(); i+=2) id(str[i]);
    s = string(idx, 'a');
    getline(cin, str);
    for(int i=0; i<str.length(); i+=4){
      adj[id(str[i])].push_back(id(str[i+2]));
      ind[id(str[i+2])]++;
    }
    backtrack();
    sort(v.begin(), v.end());
    if(v.size()){
      for(string s : v){
        for(int i=0; i<s.size()-1; i++) cout<<s[i]<<' ';
        cout<<s[s.size()-1]<<'\n';
      }
    }
    else cout<<"NO\n";
    if(t) cout<<'\n';
  }
}