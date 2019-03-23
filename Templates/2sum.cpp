#include <iostream>
#include <fstream>
#include <unordered_set>
using namespace std;

unordered_set<long long> nums;
ifstream fin ("2sum.txt");

int main() {
  long long n;
  int x = 0;
  while(fin >> n){
    nums.insert(n);
  }

  cout <<"read"<<endl;

  for(int t = -10000; t<=10000; t++){
    for(unordered_set<long long>::iterator itr = nums.begin(); itr != nums.end(); itr++){
      // cout<<(*itr)<<endl;
      unordered_set<long long>::iterator fitr = nums.find(t - (*itr));
      if(fitr != nums.end() && fitr != itr){
        x++;
        break;
      }
    }
    if(t%1000 == 0) cout<<t<<endl;
  }
  cout<<x<<endl;
}