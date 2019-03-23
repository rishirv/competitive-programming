#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n;
long num;

bool isRun(string run){
  if(run.length()>n)
    n++;
  int pos=0, arr[n] {0}, check[10] {0};
  char c=4;
  for(int i=0; i<n; i++){
    if(arr[pos] || run[pos]==c){
      return false;
    }
    arr[pos]=1;
    c=run[pos];
    if(check[c-'0']){
      return false;
    }
    check[c-'0']=1;
    pos+=run[pos]-'0';
    pos%=n;
  }
  if(pos){
    return false;
  }
  return true;
}

int main(){
  cin>>num;
  n=ceil(log10(num));
  for(;;num++){
    if(isRun(to_string(num))){
      cout<<num<<endl;
      break;
    }
  }
  return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// using namespace std;

// int n;
// string num, runNum;
// vector<long> runs;

// void genRun(char i='1', int pos=0, int x=0){
//   if(x==n){
//     if(pos==0 && stol(runNum)>stol(num)){
//       runs.push_back(stol(runNum));
//     }
//     return;
//   }
//   if(runNum[pos]!='0'){
//     return;
//   }
//   for(;i<='9'; i++){
//     runNum[pos]=i;
//     // cout<<runNum<<" "<<(pos+i-'0')%n<<endl;
//     genRun('1', (pos+i-'0')%n, x+1);
//   }
// }

// int main(){
  
//   cin>>num;
//   n=num.length();
//   for(;;n++){
//     runNum = string(n, '1');
//     genRun(num[0]);
//     sort(runs.begin(), runs.end());
//     if(runs[0]){
//       cout<<runs[0]<<endl;
//       break;
//     }
//   }
//   return 0;
// }