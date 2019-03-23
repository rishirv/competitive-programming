//Greedy
#include <iostream>
// #include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int n, arr[1000], t, c;

// ifstream cin ("in.txt");
// ofstream cout ("out.txt");

int main(){
  cin>>c;
  while(c--){
    cin>>n;
    t = 0;
    stringstream s;
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);
    while(n >= 4){
      if(arr[0] + 2*arr[1] + arr[n-1] < 2*arr[0] + arr[n-2] + arr[n-1]){
        t += arr[0] + 2*arr[1] + arr[n-1];
        s << arr[0] << ' ' << arr[1] << '\n';
        s << arr[0] << '\n';
        s << arr[n-2] << ' ' << arr[n-1] << '\n';
        s << arr[1] << '\n';
      } else{
        t += 2*arr[0] + arr[n-2] + arr[n-1];
        s << arr[0] << ' ' << arr[n-2] << '\n';
        s << arr[0] << '\n';
        s << arr[0] << ' ' << arr[n-1] << '\n';
        s << arr[0] << '\n';
      }
      n-=2;
    }
    if(n == 3){
      t += arr[0] + arr[1] + arr[2];
      s << arr[0] << ' ' << arr[1] << '\n';
      s << arr[0] << '\n';
      s << arr[0] << ' ' << arr[2] << '\n';
    }
    if(n == 2){
      t += arr[1];
      s << arr[0] << ' ' << arr[1] << '\n'; 
    }
    if(n == 1){
      t += arr[0];
      s << arr[0] << '\n';
    }
    cout<<t<<'\n'<<s.str();
    if(c) cout<<'\n';
  }
}