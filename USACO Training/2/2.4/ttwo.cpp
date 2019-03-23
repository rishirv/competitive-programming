/*
ID: verma.r1
PROG: ttwo
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void move(int d, int& x, int& y){
  switch(d){
    case 1: x--; break;
    case 2: y++; break;
    case 3: x++; break;
    case 4: y--; break;
  }
}

void rev(int& d, int& x, int& y){
  switch(d){
    case 1: x++; break;
    case 2: y--; break;
    case 3: x--; break;
    case 4: y++; break;
  }
  d=d%4+1;
}

int main(){
  ifstream cin ("ttwo.in");
  ofstream cout ("ttwo.out");
  int arr[12][12] {0}, cx, cy, cd=1, fx, fy, fd=1, c=0;
  string x;
  
  for(int i=1; i<=10; i++){
    arr[i][0]=arr[i][11]=arr[0][i]=arr[11][i]=1;
    cin>>x;
    for(int j=1; j<=10; j++){
      switch(x[j-1]){
        case '.': arr[i][j]=0; break;
        case '*': arr[i][j]=1; break;
        case 'F': fx=i; fy=j; arr[i][j]=0; break;
        case 'C': cx=i; cy=j; arr[i][j]=0; break;
      }
    }
  }
  while(true){
    move(cd, cx, cy);
    if(arr[cx][cy]){
      rev(cd, cx, cy);
    }
    move(fd, fx, fy);
    if(arr[fx][fy]){
      rev(fd, fx, fy);
    }
    c++;
    if(cx==fx && cy==fy){
      break;
    }
    if(c==1000){
      c=0;
      break;
    }
  }
  cout<<c<<endl;
}