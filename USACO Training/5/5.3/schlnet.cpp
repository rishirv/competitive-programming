/*
ID: verma.r1
PROG: schlnet
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

ifstream fin ("schlnet.in");
ofstream fout ("schlnet.out");

int t = 0, s = 0, n;
int order[101];
vector<int> leaders;
bool leader[101][101];
bool visited[101];
bool first = true;

void dfs(int v, vector<int> graph[]){
  visited[v] = true;
  leader[s][v] = true;

  for(int u : graph[v]){
    if(!visited[u]){
      dfs(u, graph);
    }
  }

  if(first){
    t++;
    order[t] = v;
  }
}

int noOuts(vector<int> graph[101]){
  int x = 0;
  bool flag;

  for(int i : leaders){
    flag = true;
    for(int j=1; j<=n; j++){
      if(leader[i][j]){
        for(int k : graph[j]){
          if(!leader[i][k]){
            flag = false;
            break;
          }
        }
      }
    }
    if(flag) x++;
  }

  return x;
}

int main() {
  vector<int> g[101], grev[101];
  int v;

  fin >> n;

  for(int u=1; u<=n; u++){
    fin >> v;
    while(v != 0){
      g[u].push_back(v);
      grev[v].push_back(u);
      fin >> v;
    }
  }

  for(int i=n; i>=1; i--){
    if(!visited[i]){
      dfs(i, grev);
    }
  }

  first = false;
  for(int i=n; i>=1; i--){
    visited[i] = false;
  }

  for(int i=n; i>=1; i--){
    if(!visited[order[i]]){
      s = order[i];
      leaders.push_back(s);
      dfs(order[i], g);
    }
  }

  if(leaders.size()==1){
    fout<<1<<endl<<0<<endl;
  } else{
    int source = noOuts(grev);
    int sink = noOuts(g);
    fout<<source<<endl<<max(source, sink)<<endl;
  }
}