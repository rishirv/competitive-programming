/*
ID: verma.r1
PROG: wormhole
LANG: C++11
*/
#include <fstream>
using namespace std;

int n, x[13], y[13], pairs[13], right_of[13];

bool loop(){
  for (int i=1; i<=n; i++) {
    int pos = i;
    for (int j=0; j<n; j++){
      pos = right_of[pairs[pos]];
    }
    if (pos != 0){ 
      return true;
    }
  }
  return false;
}

int pairing() {
  int i, total=0;
  for (i=1; i<=n; i++){
    if (pairs[i] == 0){ 
      break;
    }
  }

  if(i > n){
    if(loop()){
      return 1;
    } else{
      return 0;
    }
  }
  for (int j=i+1; j<=n; j++){
    if (pairs[j] == 0) {
      pairs[i] = j;
      pairs[j] = i;
      total += pairing();
      pairs[i] = 0;
      pairs[j] = 0;
    }
  }
  return total;
}

int main(){
  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");

  fin>>n;
  int a,b;
  
  for (int i=1; i<=n; i++){ 
    fin>>a>>b;
    x[i]=a;
    y[i]=b; 
  }

  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
      if (x[j] > x[i] && y[j] == y[i] && (right_of[i]==0 || x[j]<right_of[i])){
        right_of[i] = j;
      }
    }
  }
  fout<<pairing()<<endl;
  return 0;
}