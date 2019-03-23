/*
ID: verma.r1
PROG: spin
LANG: C++11
*/
#include <fstream>
#include <vector>
using namespace std;

int speed[5], size[5];
vector<int> start[5], last[5];

bool works(){
  int i, j, k;
  for(i=0; i<360; i++){
    bool flag1=true; //All work
    for(j=0; j<5; j++){
      bool flag2=true; //None work
      for(k=0; k<size[j]; k++){
        if(start[j][k]<=last[j][k]){
          if(i>=start[j][k] && i<=last[j][k]){
            flag2=false; //At least one works
            break;
          }
        } else{
          if(i>=start[j][k] || i<=last[j][k]){
            flag2=false;
            break;
          }
        }
      }
      if(flag2){ //Not all work
        flag1=false;
        break;
      }
    }
    if(flag1){
      return true;
    }
  }
  return false;
}

int main(){
  ifstream cin ("spin.in");
  ofstream cout ("spin.out");
  int x, y;
  bool flag=true;
  for(int i=0; i<5; i++){
    cin>>speed[i]>>size[i];
    for(int j=0; j<size[i]; j++){
      cin>>x>>y;
      start[i].push_back(x);
      last[i].push_back((x+y)%360);
    }
  }
  for(int sec=0; sec<360; sec++){
    if(works()){
      cout<<sec<<endl;
      flag=false;
      break;
    }
    for(int i=0; i<5; i++){
      for(int j=0; j<size[i]; j++){
        start[i][j]+=speed[i];
        last[i][j]+=speed[i];
        start[i][j]%=360;
        last[i][j]%=360;
      }
    }
  }
  if(flag){
    cout<<"none"<<endl;
  }
}