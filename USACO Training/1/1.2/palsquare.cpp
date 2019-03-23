/*
ID: verma.r1
PROG: palsquare
LANG: C++11
*/
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string reverse(string s){
  reverse(s.begin(), s.end());
  return s;
}

bool isPalindrome(string s){
  string x = reverse(s);
  if(s==x){
    return true;
  }
  return false;
}

string tenToB(int n, int b, string s){
  if(n==0)
    return reverse(s);
  char x=((n%b<10)?'0'+n%b:'A'+n%b-10);
  return tenToB(n/b, b, s+x);
}

int main(){
  ifstream fin ("palsquare.in");
  ofstream fout ("palsquare.out");
  
  int b;
  fin>>b;
  for(int i=1; i<=300; i++){
    if(isPalindrome(tenToB(pow(i,2), b, "")))
      fout<<tenToB(i,b,"")<<" "<<tenToB(pow(i,2),b,"")<<endl;
  }
  return 0;
}