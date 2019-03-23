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

unsigned int n;

int main(){
  while(cin>>n && n!=0)
    cout<<((unsigned int) pow((unsigned int) sqrt(n), 2) == n ? "yes\n" : "no\n");
}