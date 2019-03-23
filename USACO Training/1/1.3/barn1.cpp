/*
ID: verma.r1
PROG: barn1
LANG: C++11
*/
#include <fstream>
#include <algorithm>
using namespace std;

struct Board{
  int a,b;
};

Board maxDif(int stalls[], Board board){
  int max=0, j;
  for(int i=board.a; i<board.b; i++){
    if(stalls[i+1]-stalls[i]>max){
      j=i;
      max=stalls[i+1]-stalls[i];
    }
  }
  return Board {max, j};
}

int blocked(int stalls[], Board boards[], int j){
  int i=0;
  for(int x=0; x<j; x++){
    i+=stalls[boards[x].b]-stalls[boards[x].a];
  }
  return i+j;
}

int main(){
  ifstream fin ("barn1.in");
  ofstream fout ("barn1.out");
  int m, s, c;
  fin>>m>>s>>c;
  Board boards[m];
  int stalls[c];
  for(int i=0; i<c; i++){
    fin>>stalls[i];
  }
  sort(stalls, stalls+c);
  boards[0] = Board {0,c-1};
  for(int i=1; i<m && i<c; i++){
    int boardNum, pos, max=0;
    for(int j=0; j<i; j++){
      Board temp = maxDif(stalls, boards[j]);
      if(temp.a>max){
        max=temp.a;
        pos=temp.b;
        boardNum=j;
      }
    }
    boards[i]=Board {pos+1, boards[boardNum].b};
    boards[boardNum].b=pos;
  }
  fout<<blocked(stalls, boards, min(m,c))<<endl;
}