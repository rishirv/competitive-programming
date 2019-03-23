/*
ID: verma.r1
PROG: preface
LANG: C++11
*/
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int i=0, v=0, x=0, l=0, c=0, d=0, m=0;

void roman(string n){
  reverse(n.begin(), n.end());
  switch(n[0]){
    case '0': break;
    case '9': i++; x++; break;
    case '8': i++;
    case '7': i++;
    case '6': i++; v++; break;
    case '5': v++; break;
    case '4': i++; v++; break;
    case '3': i++; 
    case '2': i++;
    case '1': i++; break;
  }
  switch(n[1]){
    case '0': break;
    case '9': x++; c++; break;
    case '8': x++;
    case '7': x++;
    case '6': x++; l++; break;
    case '5': l++; break;
    case '4': x++; l++; break;
    case '3': x++; 
    case '2': x++;
    case '1': x++; break;
  }
  switch(n[2]){
    case '0': break;
    case '9': c++; m++; break;
    case '8': c++;
    case '7': c++;
    case '6': c++; d++; break;
    case '5': d++; break;
    case '4': c++; d++; break;
    case '3': c++; 
    case '2': c++;
    case '1': c++; break;
  }
  switch(n[3]){
    case '3': m++; 
    case '2': m++;
    case '1': m++; break;
  }
}

int main(){
  ifstream cin ("preface.in");
  ofstream cout ("preface.out");
  int n;
  cin>>n;
  for(; n>0; n--){
    roman(to_string(n));
  }
  if(i)
    cout<<"I "<<i<<endl;
  if(v)
    cout<<"V "<<v<<endl;
  if(x)
    cout<<"X "<<x<<endl;
  if(l)
    cout<<"L "<<l<<endl;
  if(c)
    cout<<"C "<<c<<endl;
  if(d)
    cout<<"D "<<d<<endl;
  if(m)
    cout<<"M "<<m<<endl;
  return 0;
}