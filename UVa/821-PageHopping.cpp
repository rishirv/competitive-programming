//APSP
//Floyd-Warshall
//Graph
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;

int t, arr[100][100], a, b, n, s;
double avg;

int main(){
  while(cin>>a>>b && a!=0){
    memset(arr, 0x3f3f3f3f, sizeof arr);
    s = n = 0;
    arr[a-1][b-1] = 1;
    while(cin>>a>>b && a!=0) arr[a-1][b-1]=1;
    for(int k=0; k<100; k++){
      for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
          arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
        }
      }
    }
    for(int i=0; i<100; i++){
      for(int j=0; j<100; j++){
        if(arr[i][j] != 0x3f3f3f3f and i != j){
          s += arr[i][j];
          n++;
        }
      }
    }
    cout<<"Case "<<(++t)<<": average length between pages = "<<fixed<<setprecision(3)<<((double) s)/n<<" clicks\n";
  }
}