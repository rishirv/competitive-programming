#include <fstream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
  ifstream cin ("lemonade.in");
  ofstream cout ("lemonade.out");
  deque<int> waiting;
  int n, x, l=0;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>x;
    waiting.push_back(x);
  }
  sort(waiting.begin(), waiting.end());
  while(!waiting.empty()){
    if(waiting.front()<l){
      waiting.pop_front();
    } else{
      waiting.pop_back();
      l++;
    }
  }
  cout<<l<<endl;
}