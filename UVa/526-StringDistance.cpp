//String Dynamic Programming
//String Alignment
//Edit Distance
//String
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

string a, b;
int arr[100][100], n, x, y, z, k;
ii p[100][100], r;
stack<ii> s;

int main(){
  while(getline(cin, a) && getline(cin, b)){
    if(arr[1][0] == -1) cout<<'\n';
    a = " " + a;
    b = " " + b;
    arr[0][0] = 0;
    for(int i=1; i<a.length(); i++) arr[i][0] = -i;
    for(int i=1; i<b.length(); i++) arr[0][i] = -i;
    for(int i=1; i<a.length(); i++){
      for(int j=1; j<b.length(); j++){
        arr[i][j] = -10000;
        if(arr[i-1][j-1] + (a[i]==b[j] ? 0 : -1) > arr[i][j]){
          arr[i][j] = arr[i-1][j-1] + (a[i]==b[j] ? 0 : -1);
          p[i][j] = ii(i-1, j-1);
        }
        if(arr[i-1][j]-1 > arr[i][j]){
          arr[i][j] = arr[i-1][j]-1;
          p[i][j] = ii(i-1, j);
        }
        if(arr[i][j-1]-1 > arr[i][j]){
          arr[i][j] = arr[i][j-1]-1;
          p[i][j] = ii(i, j-1);
        }
      }
    }
    x = a.size()-1;
    y = b.size()-1;
    n = -arr[x][y];
    while(true){
      s.push(ii(x, y));
      if(x == 0 || y == 0) break;
      r = p[x][y];
      x = r.first;
      y = r.second;
    }
    cout<<n<<'\n';
    if(x == 0 && y != 0){
      for(int i=1; i<=y; i++){
        n--;
        cout<<i<<" Insert "<<i<<','<<b[i]<<'\n';
      }
      z = y;
      k = y;
    } else if(x !=0 && y == 0){
      for(int i=1; i<=x; i++) cout<<i<<" Delete "<<1<<'\n';
      z = x;
      k = -x;
    } else{
      z = 0;
      k = 0;
    }
    s.pop();
    while(!s.empty()){
      if(s.top().first - x == 1){
        if(s.top().second - y == 1 && a[x+1] != b[y+1]){
          cout<<(++z)<<" Replace "<<y+1<<','<<b[y+1]<<'\n';
        } else if(s.top().second == y){
          cout<<(++z)<<" Delete "<<k+x+1<<'\n';
          --k;
        }
      } else{
        cout<<(++z)<<" Insert "<<y+1<<','<<b[y+1]<<'\n';
        ++k;
      }
      x = s.top().first;
      y = s.top().second;
      s.pop();
    }
  }
}