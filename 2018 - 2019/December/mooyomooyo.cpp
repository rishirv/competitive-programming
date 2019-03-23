#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

char arr[100][10];
bool visited[100][10];
int n, k;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

ifstream cin("mooyomooyo.in");
ofstream cout("mooyomooyo.out");

int floodfill(int r, int c, char ch){
  if(r<0 || r>=n || c<0 || c>=10) return 0;
  if(arr[r][c] != ch || visited[r][c]) return 0;
  int ans = 1;
  visited[r][c] = true;
  for(int i=0; i<4; i++){
    ans += floodfill(r + dr[i], c + dc[i], ch);
  }
  return ans;
}

int main(){
  cin>>n>>k;
  for(int i=0; i<n; i++){
    for(int j=0; j<10; j++){
      cin>>arr[i][j];
    }
  }

  bool changed = true;
  while(changed){
    changed = false;
    for(int i=0; i<n; i++){
      for(int j=0; j<10; j++){
        memset(visited, 0, sizeof visited);
        if(arr[i][j] != '0' && floodfill(i, j, arr[i][j]) >= k){
          changed = true;
          for(int i=0; i<n; i++){
            for(int j=0; j<=10; j++){
              if(visited[i][j]) arr[i][j] = '0';
            }
          }
        }
      }
    }
    for(int j=0; j<10; j++){
      int count = n-1;
      for(int i = n-1; i >=0; i--){
        if (arr[i][j] != '0'){
          arr[count--][j] = arr[i][j];
        }
      }
      while (count >= 0){
        arr[count--][j] = '0';
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<10; j++){
      cout<<arr[i][j];
    }
    cout<<'\n';
  }
}