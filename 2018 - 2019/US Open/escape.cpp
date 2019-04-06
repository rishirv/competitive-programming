#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii; 
typedef long long ll;
const ll p = 1000000007;

ll powMod(ll a, ll x){
  ll res = 1;
  while(x > 0) {
    if(x % 2 == 1){
      res = res*a % p;
      x--;
    }
    if(x != 0){
      a = a*a % p;
      x /= 2;
    }
  }
  return res;
}

ll invMod(ll a){ //By Fermat
  return powMod(a, p-2);
}

ll binomMod(ll n, ll k){
  if(k == 0) return 1;
  if(k == 1) return n;
  if(k > n/2) return binomMod(n, n-k);
  ll res = 1, d = 1;
  for(int i=0; i<k; i++) res = res*(n-i) % p;
  for(int i=1; i<=k; i++) d = d*i % p;
  return res*invMod(d) % p;
}

int parent[180000], size[180000];

int find(int i){
  if(i == parent[i]) return i;
  parent[i] = find(parent[i]);
  return parent[i];
}

bool Union(int x, int y){
  int a = find(x), b = find(y);
  if(a == b) return false;

  if(size[a] == size[b]){
    size[b]++;
    parent[a] = b;
  } else if(size[a] < size[b]){
    parent[a] = b;
  } else{
    parent[b] = a;
  }

  return true;
}

void init(int n){
  for(int i=0; i<n; i++) parent[i] = i;
}

int main() {
  int n, m, c, x, y;
  ll ans = 1;
  vector<iii> v;

  ifstream cin ("escape.in");
  ofstream cout ("escape.out");

  cin>>n>>m;
  init(m*n);
  for(int i=0; i<n; i++){
    for(int j=0; j<m-1; j++){
      cin>>c;
      v.push_back(make_pair(c, make_pair(m*i+j, m*i+j+1)));
    }
  }
  for(int i=0; i<m; i++){
    for(int j=0; j<n-1; j++){
      cin>>c;
      v.push_back(make_pair(c, make_pair(m*j+i, m*(j+1)+i)));
    }
  }
  sort(v.begin(), v.end());
  c = x = y = 0;
  for(auto i : v){
    if(i.first != c){
      ans = ans*binomMod(x, y) % p;
      c = i.first;
      x = y = 0;
    }
    x++;
    if(Union(i.second.first, i.second.second)) y++;
  }
  ans = ans*binomMod(x, y) % p;
  cout<<ans<<'\n';
}