#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

ifstream cin ("exercise.in");
ofstream cout ("exercise.out");

typedef pair<int, int> ii;
vector<int> arr[400010];
vector<ii> v;
bool visited[400010];
int subtree[400010];
int n, m, x, y, a, b, c, d, sum;

void dfs(int i = 0, int c = -1){
  visited[i] = true;
  subtree[i] = c;
  for(int j : arr[i]){
    if(!visited[j]){
      dfs(j, (i == 0 ? subtree[j] : c));
    }
  }
}

void rec(int i, int j){
  a = v[i].first;
  b = v[i].second;
  c = v[j].first;
  d = v[j].second;
  if(a == c){
    if(subtree[b] != subtree[d]) sum++;
    return;
  }
  if(a == d){
    if(subtree[b] != subtree[c]) sum++;
    return;
  }
  if(b == c){
    if(subtree[a] != subtree[d]) sum++;
    return;
  }
  if(b == d){
    if(subtree[a] != subtree[c]) sum++;
    return;
  }
}

int main() {
  cin>>n>>m;
  for(int i=1; i<n; i++){
    cin>>x>>y;
    x--; y--;
    if(x == 0) subtree[y] = i;
    if(y == 0) subtree[x] = i;
    arr[x].push_back(y);
    arr[y].push_back(x);
  }
  dfs();
  for(int i=0; i<n; i++) arr[i].clear();
  for(int i=n; i<=m; i++){
    cin>>x>>y;
    x--; y--;
    x = subtree[x];
    y = subtree[y];
    if(x == -1){
      x = n;
      n++;
    } else if(y == -1){
      y = n;
      n++;
    }
    if(x != y){
      arr[x].push_back(y);
      arr[y].push_back(x);
    }
  }
  for(int i=0; i<n; i++){
    for(int j : arr[i]){
      for(int k : arr[j]){
        if(i != k) sum++;
      }
    }
  }
  cout<<sum/2<<'\n';
}