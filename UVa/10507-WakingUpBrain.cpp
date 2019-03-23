#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int val[30], arr[30][30], sum[30], ind, n, m, y;
bool a[30];
char r, s;

int i(char r){
  if(val[r-'A'] == 0) val[r-'A'] = ++ind;
  return val[r-'A']-1;
}

int main() {
  while(cin>>n>>m){
    memset(val, 0, sizeof val);
    memset(sum, 0, sizeof sum);
    memset(arr, 0, sizeof arr);
    memset(a, 0, sizeof a);
    ind = y = 0;


    for(int x=0; x<3; x++){
      cin>>r;
      a[i(r)] = 1;
    }

    for(int x=0; x<m; x++){
      cin>>r>>s;
      arr[i(r)][i(s)] = arr[i(s)][i(r)] = 1;
    }

    for(int x=0; x<n; x++)
      for(int y=0; y<n; y++)
        if(arr[x][y]) sum[x] += a[y];

    while(true){
      vector<int> v;
      for(int x=0; x<n; x++)
        if(!a[x] && sum[x]>=3) v.push_back(x);
      if(v.size()){
        ++y;
        for(int x : v){
          a[x] = 1;
          for(int z=0; z<n; z++)
            if(arr[x][z]) sum[z] += 1;
        }
      } else{
        bool f = 0;
        for(int x=0; x<n; x++){
          if(a[x] == 0){
            f = 1; 
            break;
          }
        }
        if(f) cout<<"THIS BRAIN NEVER WAKES UP\n";
        else cout<<"WAKE UP IN, "<<y<<", YEARS"<<endl;
        break;
      }
    }
  }
}