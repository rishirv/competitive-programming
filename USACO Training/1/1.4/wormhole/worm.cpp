/*
ID: verma.r1
PROG: wormhole
LANG: C++11
*/
#include <fstream>
using namespace std;

int n, x[13], y[13], pairs[13], right_of[13];

bool is_loop(){
  for (int i=1; i<=n; i++) {
    int pos = i;
    for (int count=0; count<n; count++){
      pos = right_of[pairs[pos]];
    }
    if (pos != 0){ 
      return true;
    }
  }
  return false;
}

int pairings(){
  int i, total=0;
  for (i=1; i<=n; i++){ 
    if (pairs[i] == 0){
      break;
    }
  }
  
  if(i > n){
    if(is_loop()){
      return 1;
    } else{ 
      return 0;
    }
  }

  for (int j=i+1; j<=n; j++){
    if (pairs[j] == 0) {
      pairs[i] = j;
      pairs[j] = i;
      total += pairings();
      pairs[i] = 0;
      pairs[j] = 0;
    }
  }
  return total;
}

int main(){
  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");

  fin >> n;
  for (int i=1; i<=n; i++){ 
    fin >> x[i] >> y[i];
  }

  for (int i=1; i<=n; i++){
    for (int mp=1; mp<=n; mp++){
      if (x[mp] > x[i] && y[mp] == y[i] && (right_of[i] == 0 || x[mp] < x[right_of[i]])){
          right_of[i] = mp;
      }
    }
  }

  fout<<pairings()<<endl;
  return 0;
}