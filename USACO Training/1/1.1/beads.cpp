/*
ID: verma.r1
PROG: beads
LANG: C++11
*/
#include <fstream>
#include <string>
using namespace std;

int length(string sub){
  int len=0, n=0;
  char run='w', s;
  for(int i=0; i<sub.length(); i++){
    s=sub[i];
    if(s=='w');
    else if(run=='w')
      run=s;
    else if(run!=s){
      run=s;
      if(n++==1)
        return len;
    }
    len+=1;
  }
  return len;
}

int main(){
  ifstream fin ("beads.in");
  ofstream fout ("beads.out");
  
  int n, x, max=0;
  string s;
  fin>>n>>s;
  s+=s;
  for(int i=0; i<n; i++){
    x=length(s.substr(i,n));
    if(x>max)
      max=x;
  }
  fout<<max<<endl;
  return 0;
}