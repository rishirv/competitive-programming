#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int r, c, t;
char ch;
vector<char> v;
bool heir[204][204], arr[200][200];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
char letters[] = {' ', 'W', 'A', 'K', 'J', 'S', 'D'};

void floodfill(int i, int j){
  if(i<0 || i>=r || j<0 || j>=c || arr[i][j]==0) return;
  heir[i+1][j+1] = 1;
  arr[i][j] = 0;
  for(int k=0; k<4; k++){
    floodfill(i+dr[k], j+dc[k]);
  }
}

void floodfillheir(int i, int j){
  if(i<0 || i>r+1 || j<0 || j>c+1 || heir[i][j]==1) return;
  heir[i][j] = 1;
  for(int k=0; k<4; k++){
    floodfillheir(i+dr[k], j+dc[k]);
  }
}

int test(){
  int x = 0;
  for(int i=1; i<=r; i++){
    for(int j=1; j<=c; j++){
      if(heir[i][j] == 0){
        floodfillheir(i, j);
        x++;
      }
    }
  }
  return x;
}

int main() {
  while(cin>>r>>c && r!=0){
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        cin>>ch;
        if(ch >= 'a') ch-='a'-10;
        else ch -= '0';
        for(int k=0; k<4; k++){
          arr[i][4*j+k] = ch & (1<<(3-k));
        }
      }
    }
    c*=4;
    v.clear();
    
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        if(arr[i][j]){
          memset(heir, 0, sizeof heir);
          floodfill(i, j);
          v.push_back(letters[test()]);
        }
      }
    }
    sort(v.begin(), v.end());
    cout<<"Case "<<++t<<": ";
    for(char ch : v) cout<<ch;
    cout<<'\n';
  }  
}