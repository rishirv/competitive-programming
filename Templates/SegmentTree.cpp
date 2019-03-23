#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree{
	private:
		vi st, A;
		int n;
		int left(int p){ return p << 1; } //Stored like a binary tree
		int right(int p){ return (p << 1) + 1; }

		int build(int p, int L, int R){
			if(L == R){
				st[p] = L;
			} else{
				int p1 = build(left(p), L, (L+R)/2); //Recursively compute tree
				int p2 = build(right(p), (L+R)/2+1, R);
				st[p] = A[p1] <= A[p2] ? p1 : p2;
			}
			return st[p];
		}

		int rmq(int p, int L, int R, int i, int j){
			if(i > R || j < L) return -1; //Outside query range
			if(L >= i && R <= j) return st[p]; //Inside query range

			int p1 = rmq(left(p), L, (L+R)/2, i, j); //Min position in left interval
			int p2 = rmq(right(p), (L+R)/2 + 1, R, i, j); //Min position in right interval

			if(p1 == -1) return p2;
			if(p2 == -1) return p1;
			return A[p1] <= A[p2] ? p1 : p2; //Same as build
		}
	public:
		SegmentTree(const vi &_A){
			A = _A; //Copy array
			n = (int) A.size();
			st.assign(4*n, 0); //Allocate space
			build(1, 0, n-1);
		}

		int rmq(int i, int j){
			return rmq(1, 0, n-1, i, j);
		}
};