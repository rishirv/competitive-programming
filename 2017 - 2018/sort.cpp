#include <fstream>
#include <algorithm>
using namespace std;

struct pos{
  int x, pos;
};

bool compare(pos a, pos b){
  if(a.x != b.x) return a.x < b.x;
  return a.pos < b.pos;
}

int main() {
  ifstream cin ("sort.in");
  ofstream cout ("sort.out");
  int n, m = 0;
  cin>>n;
  pos a[n];
  for(int i=0; i<n; i++){
    cin>>a[i].x;
    a[i].pos = i;
  }
  
  sort(a, a+n, compare);

  for(int i=0; i<n; i++){
    if(a[i].pos-i > m) m = a[i].pos-i;
  }

  cout<<m+1<<endl;
}