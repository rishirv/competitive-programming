//Recursive backtracking
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

int t, n, k, x, y;
vii adj;
bitset<200> b;

void recurse(bitset<200> st, int i = 1){
  if(i == n+1){
    if(st.count() > b.count()) b = st;
    return;
  }
  recurse(st, i+1);
  st.set(i);
  for(int j : adj[i]) if(st.test(j)) return;
  recurse(st, i+1);
}

int main() {
  cin>>t;
  while(t--){
    adj = vii(200);
    bitset<200> st = b = bitset<200>();
    cin>>n>>k;
    for(int i=0; i<k; i++){
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    recurse(st);
    cout<<b.count()<<'\n';
    for(x=1; x<=n; x++) if(b.test(x)) break;
    cout<<x++;
    for(; x<=n; x++) if(b.test(x)) cout<<' '<<x;
    cout<<'\n';
  }
}