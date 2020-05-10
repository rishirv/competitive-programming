//Kosaraju's Algorithm to find strongly connected components (SCC)
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

ifstream fin ("SCC.txt");
vector<vector<int> > g(2000001), grev(2000001);
int t = 0, s = 0, n = 9;
int order[2000001], leader[2000001], neighborsV[2000001];
bool visited[2000001];
stack<int> st;

void dfs(int v, vector<vector<int> > &graph, bool first){
  st.push(v);

  while(!st.empty()){
    v = st.top();
    visited[v] = true;
    leader[v] = s;
    bool any = false;
    for(; neighborsV[v] < graph[v].size(); neighborsV[v]++){
      if(!visited[graph[v][neighborsV[v]]]){
        st.push(graph[v][neighborsV[v]]);
        any = true;
        break;
      }
    }
    if(!any){
      if(first){
        t++;
        order[t] = st.top();
      }
      st.pop();
    }
  }
}

int main() {
  int u, v;

  while(fin >> u >> v){
    g[u].push_back(v);
    grev[v].push_back(u);
  }

  cout<<"read"<<endl;

  for(int i=n; i>=1; i--)
    if(!visited[i])
      dfs(i, grev, true);

  cout<<"firstdfs"<<endl;

  memset(visited, false, sizeof(visited));
  memset(neighborsV, 0, sizeof(neighborsV));

  for(int i=n; i>=1; i--){
    if(!visited[order[i]]){
      s = order[i];
      dfs(order[i], g, false);
    }
  }

  cout<<"seconddfs"<<endl;

  for(int i=1; i<=n; i++) cout<<i<<" "<<leader[i]<<endl;
}