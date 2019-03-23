//Math
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

int n, s, c, arr[3];
char ch;

int main(){
  cin>>c;
  cin.ignore();
  for(int i=1; i<=c; i++){
    memset(arr, 0, sizeof arr);
    while(cin.get(ch) && ch != '\n') arr[(ch-'0')%3]++;
    s = (arr[1] + 2*arr[2])%3;
    cout<<"Case "<<i<<": ";
    if(s == 0) arr[0]--;
    if((s == 0 ? arr[s]+1 : arr[s]) && !(arr[0] & 1)) cout<<"S\n";
    else cout<<"T\n";
  }
}