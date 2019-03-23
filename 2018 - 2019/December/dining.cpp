#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream cin ("dining.in");
ofstream cout ("dining.out");

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int inf = 1000000000;
vi distP, distS, p;
vii edges[50001];
bool possible[50001];
int n, m, k, hay[50001];

void dijkstraS(int s = n-1){
  distS = vi(50001, inf);
  distS[s] = 0;
  priority_queue<ii, vii, greater<ii>> pq;
  pq.push(make_pair(0, s));
  while(!pq.empty()){
    ii front = pq.top();
    pq.pop();
    int d = front.first, u = front.second;
    if(d > distS[u]) continue;
    for(ii &v : edges[u]){
      if(distS[u] + v.second < distS[v.first]){
        distS[v.first] = distS[u] + v.second;
        pq.push(make_pair(distS[v.first], v.first));
      }
    }
  }
}

void dijkstraP(int s){
  distP = vi(50001, inf);
  distP[s] = 0;
  priority_queue<ii, vii, greater<ii>> pq;
  pq.push(make_pair(0, s));
  while(!pq.empty()){
    ii front = pq.top();
    pq.pop();
    int d = front.first, u = front.second;
    if(d > distP[u]) continue;
    for(ii &v : edges[u]){
      if(distP[u] + v.second < distP[v.first]){
        distP[v.first] = distP[u] + v.second;
        pq.push(make_pair(distP[v.first], v.first));
      }
    }
  }
  for(int i=0; i<n-1; i++){
    if(distP[i] <= distS[i]){
      possible[i] = true;
    }
  }
}

int main(){
  int x, y, z;
  cin>>n>>m>>k;
  for(int i=0; i<m; i++){
    cin>>x>>y>>z;
    edges[x-1].push_back(make_pair(y-1, z));
    edges[y-1].push_back(make_pair(x-1, z));
  }
  for(int i=0; i<k; i++){
    cin>>x>>y;
    hay[x-1] = max(hay[x-1], y);
    p.push_back(x-1);
  }
  dijkstraS();
  for(int i : p){
    edges[n].push_back(make_pair(i, distS[i]-hay[i]));
  }
  dijkstraP(n);
  for(int i=0; i<n-1; i++){
    cout<<possible[i]<<'\n';
  }
}