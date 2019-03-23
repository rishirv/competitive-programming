/*
ID: verma.r1
PROG: zerosum
LANG: C++11
*/
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> nums (10);
vector<int> links (10);
vector<char> ops (9);
ifstream cin ("zerosum.in");
ofstream cout ("zerosum.out");

bool process(vector<string> nums, vector<char> ops, vector<int> links){
  int i=1, pos=1;
  for(int i=1; i<n; i++){
    if(ops[i]==' '){
      nums[pos]+=nums[links[pos]];
      links[pos]++;
    } else{
      pos=links[pos];
    }
  }
  i=links[1];
  int sum=stoi(nums[1]);
  while(i!=n+1){
    if(ops[i-1]=='+')
      sum+=stoi(nums[i]);
    else
      sum-=stoi(nums[i]);
    i=links[i];
  }
  if(sum)
    return false;
  return true;
}

void construct(int x=1){
  if(x==n){
    if(process(nums, ops, links)){
      for(int i=1; i<n; i++){
        cout<<nums[i]<<ops[i];
      }
      cout<<nums[n]<<endl;
    }
    return;
  }
  for(char i : {' ', '+', '-'}){
    ops[x]=i;
    construct(x+1);
  }
}

int main(){
  cin>>n;
  for(int i=1; i<=n; i++){
    nums[i]=i+'0';
    links[i]=i+1;
  }
  construct();
  return 0;
}