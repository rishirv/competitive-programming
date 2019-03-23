#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

struct msr{
  int d, c, ch;
  bool operator < (const msr&rhs) const{
    return this->d < rhs.d;
  }
};

ifstream cin ("measurement.in");
ofstream cout ("measurement.out");

int n, _, num, maxmilk, c, v;
msr msrs[100001];
map<int, int> g;
map<int, int, greater<int> > counts; 

int main(){
  cin>>n>>_;
  
  for(int i=0; i<n; i++)
    cin >> msrs[i].d >> msrs[i].c >> msrs[i].ch;
  sort(msrs, msrs+n);
  
  counts[0] = n;

  for(int i=0; i<n; i++){
    c = msrs[i].c;
    v = g[c] + msrs[i].ch;
    bool wasmax = (g[c] == counts.begin()->first);
    int oldmaxcnt = counts.begin()->second;
    counts[g[c]]--;

    g[c] = v;

    counts[g[c]]++;
    bool ismax = (g[c] == counts.begin()->first);
    int newmaxcnt = counts.begin()->second;

    if(wasmax){
      if(!ismax || oldmaxcnt != newmaxcnt){
        num++;
      }
    } else if(ismax){
      num++;
    }
  }

  cout<<num<<endl;
  return 0;
}