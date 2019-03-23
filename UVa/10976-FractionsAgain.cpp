#include <iostream>
using namespace std;

int main() {
  int n, p;
  while(cin>>n){
    p = 0;
    for(int i=n+1; i<=2*n; i++)
      if(i*n % (i-n) == 0) p++;
    cout<<p<<endl;
    for(int i=n+1; i<=2*n; i++)
      if(i*n % (i-n) == 0)
        cout<<"1/"<<n<<" = 1/"<<(i*n/(i-n))<<" + 1/"<<i<<endl;
  }
}