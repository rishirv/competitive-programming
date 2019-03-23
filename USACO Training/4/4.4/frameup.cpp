/*
ID: verma.r1
PROG: frameup
LANG: C++11
*/
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
  int min_x, min_y, max_x, max_y;
};

node frames[26];
string paint[30];
bool before[26][26];
int n;

string x(26, ' ');
bool visited[26];
vector<string> solutions;

string r(string s){
  string a(n, ' ');
  for(int i=0; i<n; i++){
    a[i] = s[n-i-1];
  }
  return a;
}

void solve(int pos){
  if(pos==n){
    solutions.push_back(r(x));
    return;
  }
  
  bool first;
  for(int i=0; i<26; i++){
    if(visited[i] || frames[i].min_x==30) continue;
    first = true;
    for(int j=0; j<26; j++){
      if(!visited[j] && before[i][j]){
        first = false;
      }
    }
    if(first){
      visited[i] = true;
      x[pos] = i+'A';
      solve(pos+1);
      visited[i] = false;
    }
  }
}

int main() {
  ifstream cin ("frameup.in");
  ofstream cout ("frameup.out");

  int h, w;
  cin>>h>>w;
  
  for(int i=0; i<26; i++){
    frames[i].min_y = frames[i].min_x = 30;
    frames[i].max_y = frames[i].max_x = -1;
  }
  
  for(int i=0; i<h; i++){
    cin>>paint[i];
    for(int j=0; j<w; j++){
      if(paint[i][j]=='.') continue;
      int letter = paint[i][j]-'A';
      if(i < frames[letter].min_x) frames[letter].min_x = i;
      if(i > frames[letter].max_x) frames[letter].max_x = i;
      if(j < frames[letter].min_y) frames[letter].min_y = j;
      if(j > frames[letter].max_y) frames[letter].max_y = j;
    }
  }
  
  for(int i=0; i<26; i++){
    if(frames[i].min_x==30) continue;
    ++n;
    node x = frames[i];
    char c;
    for(int j=x.min_x; j<=x.max_x; j++){
      c=paint[j][x.min_y]; 
      if(c!='.' && c-'A'!=i) before[i][c-'A']=true;
      c=paint[j][x.max_y];
      if(c!='.' && c-'A'!=i) before[i][c-'A']=true;
    }
    for(int j=x.min_y; j<=x.max_y; j++){
      c=paint[x.min_x][j];
      if(c!='.' && c-'A'!=i) before[i][c-'A']=true;
      c=paint[x.max_x][j];
      if(c!='.' && c-'A'!=i) before[i][c-'A']=true;
    }
  }
  
  solve(0);
  sort(solutions.begin(), solutions.end());
  for(string s : solutions) cout<<s<<endl;
}