/*
ID: verma.r1
PROG: crypt1
LANG: C++11
*/
#include <fstream>
#include <string>
#include <set>
using namespace std;

bool is(string r, string x, int n){
  if(r.length()!=n)
    return false;
  for(char y: r){
    if(x.find(y)==string::npos)
      return false;
  }
  return true;
}

int main(){
  ifstream fin ("crypt1.in");
  ofstream fout ("crypt1.out");
  int n, count=0;
  string x = "";
  char a;
  fin>>n;
  for(int i=0; i<n; i++){
    fin>>a;
    x+=a;
  }
  for(int a : x){
    a-='0';
    for(int b : x){
      b-='0';
      for(int c: x){
        c-='0';
        set<int> nums;
        for(int i: x){
          i-='0';
          if(is(to_string((100*a+10*b+c)*i),x,3)){
            nums.insert((100*a+10*b+c)*i);
          }
        }
        for(int i: nums){
          for(int j:nums){
            if(is(to_string(10*i+j),x,4))
              count+=1;
          }
        }
      }
    }
  }
  fout<<count<<endl;
}