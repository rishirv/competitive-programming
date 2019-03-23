#include <iostream>
#include <iomanip>
using namespace std;

int r, s, t;
char ch;
bool map[200][200];

void B(int r1 = 0, int r2 = r-1, int s1 = 0, int s2 = s-1){  
  if(r2 < r1 || s2 < s1) return;
  for(int i=r1; i<=r2; i++){
    for(int j=s1; j<=s2; j++){
      if(map[i][j] != map[r1][s1]){
        cout<<'D';
        if(++t % 50 == 0) cout<<'\n';
        B(r1, (r1+r2)/2, s1, (s1+s2)/2);
        B(r1, (r1+r2)/2, (s1+s2)/2 + 1, s2);
        B((r1+r2)/2 + 1, r2, s1, (s1+s2)/2);
        B((r1+r2)/2 + 1, r2, (s1+s2)/2 + 1, s2);
        return;
      }
    }
  }
  cout<<map[r1][s1];
  if(++t % 50 == 0) cout<<'\n';
}

void D(int r1 = 0, int r2 = r-1, int s1 = 0, int s2 = s-1){
  if(r2 < r1 || s2 < s1) return;
  cin>>ch;
  if(ch == 'D'){
    D(r1, (r1+r2)/2, s1, (s1+s2)/2);
    D(r1, (r1+r2)/2, (s1+s2)/2 + 1, s2);
    D((r1+r2)/2 + 1, r2, s1, (s1+s2)/2);
    D((r1+r2)/2 + 1, r2, (s1+s2)/2 + 1, s2);
  } else{
    for(int i=r1; i<=r2; i++){
      for(int j=s1; j<=s2; j++){
        map[i][j] = ch - '0';
      }
    }
  } 
}

int main(){
  while(cin>>ch && ch != '#'){
    cin>>r>>s;
    if(ch == 'B'){
      cout<<'D'<<setw(4)<<r<<setw(4)<<s<<'\n';
      for(int i=0; i<r; i++){
        for(int j=0; j<s; j++){
          cin>>ch;
          map[i][j] = ch - '0';
        }
      }
      t = 0;
      B();
      if(t % 50 != 0) cout<<'\n';
    } else{
      cout<<'B'<<setw(4)<<r<<setw(4)<<s<<'\n';
      D();
      for(int i=0; i<r; i++){
        for(int j=0; j<s; j++){
          cout<<map[i][j];
          if((i*s + j) % 50 == 49) cout<<'\n';
        }
      }
      if(r*s % 50) cout<<'\n';
    }
  }
}