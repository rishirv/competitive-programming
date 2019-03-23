#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[1000][1000];
vector<int> tx, ty;
int n, m;

int main(){
  while(cin>>n){
    memset(arr, 0, sizeof arr);
    tx.clear();
    ty.clear();
    m = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin>>arr[i][j];
        if(arr[i][j]=='3'){
          tx.push_back(i);
          ty.push_back(j);
        }
      }
    }

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        if(arr[i][j] == '1'){
          int s = 1000000;
          for(int k=0; k<tx.size(); k++){
            s = min(s, abs(i-tx[k]) + abs(j-ty[k]));
          }
          m = max(m, s);
        }
    cout<<m<<endl;
  }
}