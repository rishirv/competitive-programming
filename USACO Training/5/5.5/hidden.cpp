/*
ID: verma.r1
PROG: hidden
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream fin ("hidden.in");
ofstream fout ("hidden.out");
int n, o, opts[100000];
string a, s="";

int main() {
  fin>>n;
  while(fin >> a) s+=a;
  s+=s;

  o=1;
  opts[0]=0;
  for(int i=1; i<n; i++){
    if(s.substr(i-1, 1) != s.substr(i, 1)){
      opts[o] = i;
      o++;
    }
  }

  int r = 1;

  while(o > 1){
    int x = 0;
    string m = "z";
    for(int i=0; i<o; i++){
      if(s.substr(opts[i]+r-1, 1).compare(m) == 0){
        opts[x] = opts[i];
        if(x>0 && opts[x]-opts[x-1] < r) x--;
        x++;
      }
      if(s.substr(opts[i]+r-1, 1).compare(m) < 0){
        x = 1;
        opts[0] = opts[i];
        m = s.substr(opts[i]+r-1, 1);
      }
    }
    o = x;
    r++;
  }
  fout<<opts[0]<<endl;
}