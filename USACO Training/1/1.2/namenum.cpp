/*
ID: verma.r1
PROG: namenum
LANG: C++11
*/
#include <fstream>
#include <string>
#include <set>
using namespace std;

ifstream fin ("namenum.in");
ifstream dict ("dict.txt");
ofstream fout ("namenum.out");
set<string> names;
bool flag=true;

void name(char words[][3], string str, int i, int n){
  if(i==n-1){
	if(names.find(str)!=names.end()){
	    fout<<str<<endl;
		flag=false;
	}
  } else{
    i++;
    for(int j=0; j<3; j++){
      name(words, str+words[i][j], i, n);
    }
  }
}

int main(){
	string s;
	for(int i=0; i<4618; i++){
	  dict>>s;
	  names.insert(s);
	}
	fin>>s;
	int n = s.length();
	char words[n][3];
	char letters[11][3] {{},{}, {'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'X','Y','Z'}};
	for(int i=0; i< n; i++){
		int x = s[i]-'0';
		words[i][0]=letters[x][0];
		words[i][1]=letters[x][1];
		words[i][2]=letters[x][2];
	}
	for(int j=0; j<3; j++){
		name(words, string(1, words[0][j]), 0, n);
	}
	if(flag)
		fout<<"NONE"<<endl;
}