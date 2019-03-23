//String
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

string arr[4], s;
int t, n, v, val[] = {0, 0, 0, 1, 1, 2, 3, 5, 11, 11, 11, 11, 11, 11, 11, 11, 11};
bool visited[4][4];

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, 1, -1, -1, 0, 1};

bool recurse(int r, int c, int j=0){
  if(j == s.size()-1) return true;
  visited[r][c] = true;
  for(int x=0; x<8; x++){
    if(r+dr[x]>=0 && c+dc[x]>=0 && r+dr[x]<4 && c+dc[x]<4 && !visited[r+dr[x]][c+dc[x]] && arr[r+dr[x]][c+dc[x]]==s[j+1] && recurse(r+dr[x], c+dc[x], j+1)){
      visited[r][c] = false;
      return true;
    }
  }
  visited[r][c] = false;
  return false;
}

int main(){
  cin>>t;
  for(int c=1; c<=t; c++){
    for(int i=0; i<4; i++) cin>>arr[i];
    v = 0;
    cin>>n;
    while(n--){
      cin>>s;
      for(int i=0; i<16; i++){
        if(arr[i%4][i/4] == s[0] && recurse(i%4, i/4)){
          v += val[s.size()];
          break;
        }
      }
    }
    cout<<"Score for Boggle game #"<<c<<": "<<v<<'\n';
  }
}