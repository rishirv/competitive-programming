/*
ID: verma.r1
PROG: runround
LANG: C++11
*/
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string num, run;
int n;
bool arr[10] {0}, flag=0;
long numb, bestRun;
// ifstream cin ("runround.in"); //
// ofstream cout ("runround.out"); //

void gen(int pos, int x){
  if(x==n){
    if(pos==0 && stol(run)>numb && stol(run)<bestRun){
      flag=1;
      bestRun=stol(run);
    }
    return;
  }
  
  if(run[pos]!='0')
    return;

  for(char i='1'; i<='9'; i++){
    if(arr[i-'0'])
      continue;
  
    arr[i-'0']=1;
    run[pos]=i;
    gen((pos+i-'0')%n, x+1);
    arr[i-'0']=0;
  }
  run[pos]='0';
}

int main(){
  ifstream cin ("runround.in");
  ofstream cout ("runround.out");
  bestRun = 1000000000;
  cin>>num;
  n=num.length();
  numb=stol(num);
  for(;;n++){
    run = string(n, '0');
    for(char i=(n==num.length()?num[0]:'1'); i<='9'; i++){
      run[0]=i;
      arr[i-'0']=1;
      gen((i-'0')%n, 1);
      arr[i-'0']=0;
      if(flag)
        break;
    }
    if(flag || n==10)
      break;
  }
  cout<<bestRun<<endl;
}