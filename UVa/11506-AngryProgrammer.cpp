//Min Cut
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

int s, t, e, n, x, y, z;
int arr[105][105], maxflow, minedge;
vi p;
vii adj;

void augment(int i, int edge = 400000){
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
  while(cin>>n>>e && n!=0){
    s = 0;
    t = 2*n - 1;
    memset(arr, 0, sizeof arr);
    maxflow = 0;
    adj.assign(105, vi());
    for(int i=0; i<n-2; i++){
      cin>>x>>y;
      arr[2*x-2][2*x-1] = y;
      adj[2*x-2].push_back(2*x-1);
      adj[2*x-1].push_back(2*x-2);
    }
    arr[0][1] = arr[t-1][t] = 300000;
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[t-1].push_back(t);
    adj[t].push_back(t-1);
    for(int i=0; i<e; i++){
      cin>>x>>y>>z;
      arr[2*x-1][2*y-2] = arr[2*y-1][2*x-2] = z;
      adj[2*x-1].push_back(2*y-2);
      adj[2*y-1].push_back(2*x-2);
      adj[2*y-2].push_back(2*x-1);
      adj[2*x-2].push_back(2*y-1);
    }
    n = t+1;

    while(true){
      minedge = 0;
      bitset<105> v;
      queue<int> q;
      v.set(s);
      p.assign(105, -1);
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
    cout<<maxflow<<"\n";
  }
}