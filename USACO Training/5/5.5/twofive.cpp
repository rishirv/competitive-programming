/*
ID: verma.r1
PROG: twofive
LANG: C++11
*/
#include <fstream>
#include <cstring>
using namespace std;

char des[6][6];
int dp[6][6][6][6][6], x[25], y[25], lines[6], n;
bool used[25];
ifstream cin ("twofive.in");
ofstream cout ("twofive.out");

int calcState(int c){
  if(dp[lines[1]][lines[2]][lines[3]][lines[4]][lines[5]] != 0) return dp[lines[1]][lines[2]][lines[3]][lines[4]][lines[5]];

  int v = 0;
  if(used[c]){
    if(lines[x[c]]+1 == y[c] && lines[x[c]]<lines[x[c]-1]){
      lines[x[c]]++;
      v+=calcState(c+1);
      lines[x[c]]--;
    }
  } else{
    for(int i=1; i<=5; i++){
      if(lines[i]<lines[i-1]){
        lines[i]++;
        v+=calcState(c+1);
        lines[i]--;
      }
    }
  }

  dp[lines[1]][lines[2]][lines[3]][lines[4]][lines[5]] = v;
  return v;
}

int main(){
  char c;
  cin>>c;

  int v = 1;

  if(c == 'W'){
    for(int i=1; i<=5; i++){
      for(int j=1; j<=5; j++){
        cin>>c;
        des[i][j] = c-'A';
      }
    }

    for(int i=1; i<=5; i++){
      for(int j=1; j<=5; j++){
        for(int c=0; c<25; c++){
          if(used[c]) continue;
          used[c] = true;
          x[c] = i;
          y[c] = j;
          if(c == des[i][j]) break;

          memset(dp, 0, sizeof(dp));
          memset(lines, 0, sizeof(lines));
          dp[5][5][5][5][5] = 1;
          lines[0] = 5;
          v += calcState(0);
          used[c] = false;
        }
      }
    }
    cout<<v<<endl;    
  } else{
    cin>>n;
    for(int i=1; i<=5; i++){
      for(int j=1; j<=5; j++){
        for(int c=0; c<25; c++){
          if(used[c]) continue;
          used[c] = true;
          x[c] = i;
          y[c] = j;
          des[i][j] = c;
          memset(dp, 0, sizeof(dp));
          memset(lines, 0, sizeof(lines));
          dp[5][5][5][5][5] = 1;
          lines[0] = 5;
          int x = calcState(0);
          if(v+x>n) break;
          v+=x;
          used[c] = false;
        }
      }
    }
    for(int i=1; i<=5; i++){
      for(int j=1; j<=5; j++){
        cout<<char(des[i][j]+'A');
      }
    }
    cout<<endl;
  }
}