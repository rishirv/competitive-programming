#include <iostream>
#include <string>
#include <list>
using namespace std;

list<char> l;
list<char>::iterator it;
string s;
char ch;

int main() {
  it = l.begin();
  while(getline(cin, s)){
    for(char ch : s){
      if(ch == '['){
        it = l.begin();
      } else if(ch == ']'){
        it = l.end();
      } else{
        l.insert(it, ch);
      }
    }
    for(char ch : l) cout<<ch;
    cout<<'\n';
    l.clear();
    it = l.begin();
  }
}