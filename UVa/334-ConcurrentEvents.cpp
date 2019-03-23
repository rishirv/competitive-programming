//APSP
//Floyd-Warshall
//Graph
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
string a, b;
vector<string> v;
int t, n, c, e;
bool arr[500][500];

int main(){
  while(cin>>c && c!=0){
    n=0;
    m.clear();
    v.clear();
    memset(arr, 0, sizeof arr);
    while(c--){
      cin>>e;
      if(e){
        cin>>a;
        m[a] = n++;
        v.push_back(a);
      }
      for(int i=1; i<e; i++){
        cin>>b;
        v.push_back(b);
        arr[n-1][n] = 1;
        m[b] = n++;
      }
    }
    cin>>c;
    while(c--){
      cin>>a>>b;
      arr[m[a]][m[b]] = 1;
    }
    for(int k=0; k<n; k++){
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          arr[i][j] |= (arr[i][k] & arr[k][j]);
        }
      }
    }
    c = 0;
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        if(!arr[i][j] && !arr[j][i]){
          ++c;
        }
      }
    }
    cout<<"Case "<<(++t)<<", ";
    if(c == 0){
      cout<<"no concurrent events.\n";
    } else{
      cout<<c<<" concurrent events:\n";
      c = 0;
      for(int i=0; i<n && c<2; i++){
        for(int j=i+1; j<n && c<2; j++){
          if(!arr[i][j] && !arr[j][i]){
            cout<<'('<<v[i]<<','<<v[j]<<") ";
            ++c;
          }
        }
      }
      cout<<'\n';
    }
  }
}