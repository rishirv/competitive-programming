#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

ifstream fin ("2SAT.txt");
vector<vector<int> > g(2000001), grev(2000001);
int t = 0, s = 0, n;
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
  fin>>n;
  int u, v;

  while(fin >> u >> v){
    g[-u+n].push_back(v+n);
    g[-v+n].push_back(u+n);
    grev[u+n].push_back(-v+n);
    grev[v+n].push_back(-u+n);
  }

  cout<<"read"<<endl;

  for(int i=2*n; i>=0; i--)
    if(!visited[i])
      dfs(i, grev, true);

  cout<<"firstdfs"<<endl;

  memset(visited, false, sizeof(visited));
  memset(neighborsV, 0, sizeof(neighborsV));

  for(int i=2*n; i>=0; i--){
    if(!visited[order[i]]){
      s = order[i];
      dfs(order[i], g, false);
    }
  }

  cout<<"seconddfs"<<endl;

  bool valid = true;
  for(int i=1; i<=n; i++)
    if(leader[-i+n] == leader[i+n])
      valid = false;
  if(valid)
    cout<<"SATisfiable"<<endl;
  else
    cout<<"unSATisfiable"<<endl;
}