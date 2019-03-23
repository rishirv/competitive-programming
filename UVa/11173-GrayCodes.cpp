#include <iostream>
using namespace std;

int main() {
  int i, n;
  cin>>i;
  while((--i)>=0){
    cin>>n>>n;
    cout<< (int) (n ^ (n>>1)) << '\n';
  }
}