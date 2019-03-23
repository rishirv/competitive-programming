/*
ID: verma.r1
PROG: dualpal
LANG: C++11
*/
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string reverse(string s){
  reverse(s.begin(), s.end());
  return s;
}

bool isPalindrome(string s){
  string x = reverse(s);
  if(s==x)
    return true;
  return false;
}

string tenToB(int n, int b, string s){
  if(n==0)
    return reverse(s);
  return tenToB(n/b, b, s+to_string(n%b));
}

int main(){
  ifstream fin ("dualpal.in");
  ofstream fout ("dualpal.out");
  int n, s, count=0, x;
  fin>>n>>s;
  while(count<n){
    x=0;
    s++;
    for(int b=2; b<=10; b++){
      if(isPalindrome(tenToB(s,b,"")))
        x++;
      if(x==2){
        count++;
        fout<<s<<endl;
        break;
      }
    }
  }
  return 0;
}