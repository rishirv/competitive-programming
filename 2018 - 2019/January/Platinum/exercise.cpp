#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream cin ("exercise.in");
ofstream cout ("exercise.out");

typedef pair<int, int> ii;
vector<ii> arr[200010];
int path[200010];
bool visited[200010];
int n, m, x, y;

int recurse(int i = 0, int c = 0){
  if(c > 2) return 0;
  int sum = 0;
  if(path[i] > 0 && ((c == 1 && path[i] >= n) || (c == 2 && path[i] < n))) sum = 1;
  visited[i] = true;
  for(ii j : arr[i]){
    if(!visited[j.first]){
      sum += recurse(j.first, c + (j.second < n ? 0 : 1));
    }
  }
  visited[i] = false;
  return sum;
}

int main() {
  cin>>n>>m;
  for(int i=1; i<=m; i++){
    cin>>x>>y;
    x--; y--;
    if(x == 0) path[y] = i;
    if(y == 0) path[x] = i;
    arr[x].push_back(ii(y, i));
    arr[y].push_back(ii(x, i));
  }
  cout<<recurse()/2<<'\n';
}