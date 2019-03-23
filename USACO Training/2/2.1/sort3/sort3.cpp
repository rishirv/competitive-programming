/*
ID: verma.r1
PROG: sort3
LANG: C++11
*/
#include <fstream>
using namespace std;

int count=0;

struct sorter{
  int a=0,b=0,c=0;
};

void swap(int &x, int &y){
  if(x>=y){
    count+=y;
    x-=y;
    y=0;
  } else{
    count+=x;
    y-=x;
    x=0;
  }  
}

int main(){
  ifstream fin ("sort3.in");
  ofstream fout ("sort3.out");
  int n, ones=0, twos=0, threes=0;
  fin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    fin>>arr[i];
    switch(arr[i]){
      case 1: ones++; break;
      case 2: twos++; break;
      case 3: threes++; break;
    }
  }
  // cout<<ones<<" "<<twos<<" "<<threes<<endl;
  sorter a, b, c;
  for(int i=0; i<ones; i++){
    switch(arr[i]){
      case 1: a.a++; break;
      case 2: a.b++; break;
      case 3: a.c++; break;
    }
  }
  for(int i=ones; i<ones+twos; i++){
    switch(arr[i]){
      case 1: b.a++; break;
      case 2: b.b++; break;
      case 3: b.c++; break;
    }
  } 
  for(int i=ones+twos; i<n; i++){
    switch(arr[i]){
      case 1: c.a++; break;
      case 2: c.b++; break;
      case 3: c.c++; break;
    }
  }
  // cout<<a.a<<" "<<a.b<<" "<<a.c<<endl<<b.a<<" "<<b.b<<" "<<b.c<<endl<<c.a<<" "<<c.b<<" "<<c.c<<endl;
  swap(a.b,b.a);
  swap(a.c,c.a);
  swap(b.c,c.b);
  // cout<<a.a<<" "<<a.b<<" "<<a.c<<endl<<b.a<<" "<<b.b<<" "<<b.c<<endl<<c.a<<" "<<c.b<<" "<<c.c<<endl;
  // cout<<count<<endl;
  count+=2*(a.b+b.a);
  fout<<count<<endl;
}