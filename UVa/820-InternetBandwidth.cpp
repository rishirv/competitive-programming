//Karp's Algorithm
//Network Flow
//Graph
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int s, t, e, n, x, y, z, c;
int arr[100][100], maxflow, minedge;
vi p;
vii adj;

void augment(int i, int edge = 2000){
  if(i == s){
    minedge = edge;
    return;
  } else if(p[i] != -1){
    augment(p[i], min(edge, arr[p[i]][i]));
    arr[p[i]][i] -= minedge;
    arr[i][p[i]] += minedge;
  }
}

int main(){
  while(cin>>n && n!=0){
    cin>>s>>t>>e;
    --s;
    --t;
    memset(arr, 0, sizeof arr);
    maxflow = 0;
    adj.assign(n, vi());
    for(int i=0; i<e; i++){
      cin>>x>>y>>z;
      --x; --y;
      arr[x][y] += z;
      arr[y][x] += z;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    while(true){
      minedge = 0;
      bitset<100> v;
      queue<int> q;
      v.set(s);
      p.assign(n, -1);
      q.push(s);
      while(!q.empty()){
        x = q.front();
        q.pop();
        if(x == t) break;
        for(int i : adj[x]){
          if(arr[x][i]>0 && !v[i]){
            v.set(i);
            q.push(i);
            p[i] = x;
          }
        }
      }
      augment(t);
      if(minedge == 0) break;
      maxflow += minedge;
    }
    cout<<"Network "<<(++c)<<'\n';
    cout<<"The bandwidth is "<<maxflow<<".\n\n";
  }
}