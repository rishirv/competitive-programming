/*
ID: verma.r1
PROG: transform
LANG: C++
*/
#include <fstream>
using namespace std;

int n;

bool is(char a[][10], char b[][10]){
  for(int r=0; r<n; r++){
    for(int c=0; c<n; c++){
      if(a[r][c]!=b[r][c]){
        return false;
      }
    }
  }
  return true;
}

void r90(char arr[][10]){
  char temp[10][10];
  for(int r=0; r<n; r++){
    for(int c=0; c<n; c++){
      temp[r][c]=arr[r][c];
    }
  }
  for(int r=0; r<n; r++){
    for(int c=0; c<n; c++){
      arr[c][n-1-r]=temp[r][c];
    }
  }
}

void reflectH(char arr[][10]){
  char temp[10][10];
  for(int r=0; r<n; r++){
    for(int c=0; c<n; c++){
      temp[r][c]=arr[r][c];
    }
  }
  for(int r=0; r<n; r++){
    for(int c=0; c<n; c++){
      arr[r][n-1-c]=temp[r][c];
    }
  }
}

int main(){
  ifstream fin ("transform.in");
  ofstream fout ("transform.out");

  fin>>n;
  
  char arr[10][10];
  char result[10][10];
  
  for(int r=0; r<n; r++){
    for(int c=0; c<n; c++){
      fin>>arr[r][c];
    }
  }
  for(int r=0; r<n; r++){
    for(int c=0; c<n; c++){
      fin>>result[r][c];
    }
  }
  bool notFound=true;
  for(int i=1; i<4; i++){
    r90(arr);
    if(is(arr, result)&&notFound){
      fout<<i<<endl;
      notFound=false;
    }
  }
  if(notFound){
    r90(arr);
    reflectH(arr);
    if(is(arr, result))
      fout<<4<<endl;
    else{
      for(int i=0; i<3; i++){
        r90(arr);
        if(is(arr, result)&&notFound){
          fout<<5<<endl;
          notFound=false;
        }
      }
      if(notFound){
        r90(arr);
        reflectH(arr);
        fout<<(is(arr,result)?6:7)<<endl;
      }
    }
  }
  return 0;
}