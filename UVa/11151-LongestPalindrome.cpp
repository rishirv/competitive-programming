//String
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

string a;
int dp[1010][1010], n;

int recurse(int i, int j){
  if(j < i) return 0;
  if(i == j) return 1;
  if(i+1 == j) return a[i] == a[j] ? 2 : 1;
  if(dp[i][j]) return dp[i][j];
  if(a[i] == a[j]) return dp[i][j] = recurse(i+1, j-1)+2;
  return dp[i][j] = max(recurse(i+1, j), recurse(i, j-1));
}

int main(){
  cin>>n;
  cin.ignore();
  while(n--){
    getline(cin, a);
    memset(dp, 0, sizeof dp);
    cout<<recurse(0, a.size()-1)<<'\n';
  }
}