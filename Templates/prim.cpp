#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class comp{
public:
  bool operator() (const tuple<int, int, int>& a, const tuple<int, int, int>& b){
    return get<2>(a) > get<2>(b);
  }
};

ifstream fin ("prim.txt");
int n, m, sum, visited;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comp> g;
bool tree[501];

void add_edge(){
	tuple<int, int, int> temp = g.top();
	g.pop();

	if(tree[get<0>(temp)] && tree[get<1>(temp)]){
		add_edge();
	} else if(!tree[get<0>(temp)] && !tree[get<1>(temp)]){
		add_edge();
		g.push(temp);
	} else{
		tree[get<0>(temp)] = true;
		tree[get<1>(temp)] = true;
		sum += get<2>(temp);
		visited++;
	}
}

int main(){
	int i, j, k;

	fin>>n>>m;

	for(int c=0; c<m; c++){
    fin>>i>>j>>k;
    g.push(make_tuple(i, j, k));
	}

	tuple<int, int, int> temp = g.top();
	tree[get<0>(temp)] = true;
	tree[get<1>(temp)] = true;
	sum = get<2>(temp);
	visited = 2;
	g.pop();

	while(visited < n){
		add_edge();
	}

	cout<<sum<<endl;
}