#include <fstream>
using namespace std;

int main(){
  ifstream fin ("sort3.in");
  ofstream fout ("sort3.out");
  int n, ones=0, twos=0, threes=0, count=0;
  fin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    fin>>arr[i];
    switch(arr[i]){
      case 1: ones++;
      case 2: twos++;
      case 3: threes++;
    }
  }
  for(int i=0; i<ones; i++){
    if(arr[i]!=1){
      for(int j=ones; j<n; j++){
        if(arr[j]==1){
          arr[j]=arr[i];
          arr[i]=1;
          break;
        }
      }
      count++;
    }
  }
  for(int i=ones+twos; i<n; i++){
    if(arr[i]!=3){
      // for(int j=ones; j<ones+twos; j++){
      //   if(arr[j]==3){
      //     arr[j]=arr[i];
      //     arr[i]=3;
      //     break;
      //   }
      // }
      count++;
    }
  }
  // for(int i : arr){
  //   fout<<i<<" ";
  // }
  fout<<endl<<count<<endl;
}