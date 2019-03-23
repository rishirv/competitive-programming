/*
ID: verma.r1
PROG: buylow
LANG: C++11
*/

//Repl.it BlindEnormousPony

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//Begin bigint class (needs string and algorithm)
char get(string a, int b){
  if(b<a.length())
    return a[b];
  else
    return '0';
}

string addInt(string a, string b){
  string s(max(a.length(), b.length()), '0');
  int c=0;
  
  for(int i=0; i<max(a.length(), b.length()); i++){
    s[i]=((get(a,i)-'0')+(get(b,i)-'0')+c)%10 + '0';
    c=((get(a,i)-'0')+(get(b,i)-'0')+c)/10;
  }
  
  if(c)
    s+= c+'0';
  
  return s;
}

string subInt(string a, string b){
  string s(max(a.length(), b.length()), '0');
  int borrow=0, size=0;
  
  for(int i=0; i<max(a.length(), b.length()); i++){
    s[i]=get(a,i)-get(b,i)-borrow;
    borrow = (s[i]<0);
    if(borrow)
      s[i]+=10;
    s[i]+='0';
    
    if(s[i]!='0')
      size=i;
  }
  
  return s.substr(0, size+1);
}

bool isLess(string a, string b){
  if(a.length()!=b.length()){
    return a.length()<b.length();
  }
  
  for(int i=max(a.length(), b.length())-1; i>=0; i--){
    if(get(a,i)!=get(b,i)){
      return get(a,i)<get(b,i);
    }
  }
    
  return false;
}

string rev(string s){
  reverse(s.begin(), s.end());
  return s;
}
//End bigint class


int main(){
  ifstream cin ("buylow.in");
  ofstream cout ("buylow.out");
  
  int n;
  cin>>n;
  string prices[n], len[n], num[n], longestLength="0", numSols="0", prev;

  for(int i=0; i<n; i++){
    cin>>prices[i];
    prices[i]=rev(prices[i]);

    len[i]="1";
    num[i]="0";

    for(int j=0; j<i; j++){
      if(isLess(prices[i], prices[j]) && isLess(len[i], addInt(len[j], "1"))){
        len[i]=addInt(len[j], "1");
      }
    }
    
    prev="";
    
    if(len[i]=="1"){
      num[i]="1";
    } else{
      for(int j=i-1; j>=0; j--){
        if(isLess(prices[i], prices[j]) && addInt(len[j], "1") == len[i] && prices[j]!=prev){
          num[i] = addInt(num[i], num[j]);
          prev = prices[j];
        }
      }
    }
    
    if(!isLess(len[i], longestLength)){
      longestLength = len[i];
    }
  }
  
  prev="";
  
  for(int i=n-1; i>=0; i--){
    if(len[i]==longestLength && prices[i]!=prev){  
      numSols = addInt(numSols, num[i]);
      prev = prices[i];
    }
  }

  cout<<rev(longestLength)<<" "<<rev(numSols)<<endl;
}