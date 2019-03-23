/*
ID: verma.r1
PROG: lamps
LANG: C++11
*/
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<int> on, off;

void but1(string &lamps){
  for(int i=0; i<n; i++){
    lamps[i]=(lamps[i]=='1'?'0':'1');
  } 
}

void but2(string &lamps){
  for(int i=0; i<n; i+=2){
    lamps[i]=(lamps[i]=='1'?'0':'1');
  } 
}

void but3(string &lamps){
  for(int i=1; i<n; i+=2){
    lamps[i]=(lamps[i]=='1'?'0':'1');
  } 
}

void but4(string &lamps){
  for(int i=0; i<n; i+=3){
    lamps[i]=(lamps[i]=='1'?'0':'1');
  } 
}

bool check(string a){
  for(int i : on)
    if(a[i]=='0')
      return false;
  for(int i : off)
    if(a[i]=='1')
      return false;
  return true;
}

int main(){
  ifstream cin ("lamps.in");
  ofstream cout ("lamps.out");

  int c, x, count=0;
  cin>>n>>c;
  vector<int> cVec;;
  vector<string> lampVec, outVec;
  string lamps(n, '1');

  while(true){
    cin>>x;
    if(x==-1){
      break;
    } else{
      on.push_back(x-1);
    }
  }
  
  while(true){
    cin>>x;
    if(x==-1){
      break;
    } else{
      off.push_back(x-1);
    }
  }
  
  for(int a : {0,1}){
    for(int b : {0,1}){
      for(int c : {0,1}){
        for(int d : {0,1}){
          if(a)
            but1(lamps);
          if(b)
            but2(lamps);
          if(c)
            but3(lamps);
          if(d)
            but4(lamps);
          lampVec.push_back(lamps);
          cVec.push_back(a+b+c+d);
          lamps = string (n, '1');
        }
      }
    }
  }
  
  for(int i=0; i<16; i++){
    if((c-cVec[i])>=0 && (c-cVec[i])%2==0 && check(lampVec[i])){
      outVec.push_back(lampVec[i]);
      count++;
    }
  }
  
  sort(outVec.begin(), outVec.end());
  
  for(string a : outVec){
    cout<<a<<endl;
  }
  if(!count){
    cout<<"IMPOSSIBLE"<<endl;
  }
  return 0;
}