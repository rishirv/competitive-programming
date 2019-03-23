#include <iostream>
#include <bitset>
using namespace std;

int arr[92][8], b[8], cur[8], idx = 0, c = 0;
bitset<20> rw, ld, rd;

void boards(int c){
  if(c == 8){
    for(int i=0; i<8; i++) arr[idx][i] = cur[i];
    ++idx;
  } else{
    for(int r=0; r<8; r++){
      if(!rw[r] && !ld[r-c+7] && !rd[r+c]){
        rw[r] = ld[r-c+7] = rd[r+c] = true;
        cur[c] = r;
        boards(c+1);
        rw[r] = ld[r-c+7] = rd[r+c] = false;
      }
    }
  }
}

int main() {
  boards(0);
  while(cin>>b[0]){
    for(int i=1; i<8; i++) cin>>b[i];
    for(int i=0; i<8; i++) b[i]--;
    int m = 8, k;
    for(int i=0; i<92; i++){
      k = 0;
      for(int j=0; j<8; j++){
        if(arr[i][j] != b[j]) k++;
      }
      if(k < m) m = k;
    }
    cout<<"Case "<<++c<<": "<<m<<'\n';
  }
}