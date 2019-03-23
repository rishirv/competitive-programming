/*
ID: verma.r1
PROG: lgame
LANG: C++11
*/

#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int values[26] {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};

int counts[26] {0}, score=0;
vector<string> words, bestWords;

ifstream fin ("lgame.in");
ifstream dict ("lgame.dict");
ofstream fout ("lgame.out");

int main(){
	string s;
	fin>>s;

	for(int i=0; i<s.length(); i++){
		++counts[s[i]-'a'];
	}

	dict>>s;
	while(s!="."){
		bool flag=true;
		int wordCounts[26] {0}, tempScore=0;
		
		for(int i=0; i<s.length(); i++){
			tempScore+=values[s[i]-'a'];

			if(++wordCounts[s[i]-'a'] > counts[s[i]-'a']){
				flag=false;
			}
		}

		if(flag && tempScore>score){
			bestWords.clear();
			bestWords.push_back(s);
			score=tempScore;
		} else if(flag && tempScore == score){
			bestWords.push_back(s);
		}

		if(flag){
			words.push_back(s);
		}

		dict>>s;
	}

	int n = words.size();

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			bool flag=true;
			int wordCounts[26] {0}, tempScore=0;

			s=words[i];

			for(int i=0; i<s.length(); i++){
				tempScore+=values[s[i]-'a'];

				if(++wordCounts[s[i]-'a'] > counts[s[i]-'a']){
					flag=false;
				}
			}
			
			s=words[j];
			
			for(int i=0; i<s.length(); i++){
				tempScore+=values[s[i]-'a'];

				if(++wordCounts[s[i]-'a'] > counts[s[i]-'a']){
					flag=false;
				}
			}
	
			if(flag && tempScore>score){
				bestWords.clear();
				bestWords.push_back(words[i] + ' ' + words[j]);
				score=tempScore;
			} else if(flag && tempScore == score){
				bestWords.push_back(words[i] + ' ' + words[j]);
			}
		}
	}

	sort(bestWords.begin(), bestWords.end());
	
	fout<<score<<endl;
	for(string s : bestWords){
		fout<<s<<endl;
	}
}