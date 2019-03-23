/*
ID: verma.r1
PROG: hamming
LANG: C++11
*/
#include <fstream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

int n, b, d;
set<int> codes;

string bi(int a, string s, int x){
  if(x==b)
     return s;
  return bi(a/2, s+char(a%2), x+1);
}

int hamming(int a, int s){
  string sa = bi(a, "", 0);
  string ss = bi(s, "", 0);
  int count=0;
  for(int i=0; i<b; i++){
    if(sa[i]!=ss[i]){
      count++;
    }
  }
  return count;
}

bool add_code(int i){
  for(int x : codes){
    if(hamming(x, i)<d)
      return false;
  }
  return true;
}

int main(){
  ifstream fin ("hamming.in");
  ofstream fout ("hamming.out");

  int c=1;
  codes.insert(0);
  fin>>n>>b>>d;
  for(int i=1; i<pow(2,b); i++){
    if(c==n){
      break;
    }
    if(add_code(i)){
      codes.insert(i);
      c++;
    }
  }
  int count=0, x=codes.size();
  for(int i : codes){
    fout<<i;
    count++;
    if(count%10==0 || count==x){
      fout<<endl;
    } else{
      fout<<" ";
    }
  }
}