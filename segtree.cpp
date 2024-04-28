#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(x) x.begin(),x.end()
#define LEN(X) ((int)(X).size())

void printVec(int x) {cout << x;}
void printVec(double x) {cout << x;}
void printVec(bool x) {cout << (x ? "true" : "false");}
void printVec(char x) {cout << '\'' << x << '\'';}
void printVec(string x) {cout << '\"' << x << '\"';}
template <typename T, typename V>
void printVec(const pair<T, V> &x) {
	cout << "{"; printVec(x.first); cout << ","; printVec(x.second); cout << "}";
}
template <typename A>
void printVec(const vector<A> &p) {
	cout << '[';
    for (size_t i=0;i<p.size();++i) {printVec(p[i]); if (i<p.size()-1) cout << ", ";}
	cout << ']';
}
template<typename T>
void _print(T t) {printVec(t); cout <<'\n';}


// Segment tree
// update op and initial sum
class SegTree {
	public:
	int N; // size of array - nearest power of 2 
   	// size of segment tree is 2N (1 indexed). 1,...,N-1 are parent nodes
	vector<int> seg;  
	int op(int l, int r) {return l+r;}

	SegTree(int n, int val = 0) {
		N = 1;
		// find nearest power of 2 above arr and initialise tree
		while (N < n) N = N << 1;
		seg = vector<int>(2*N,val);

	}
	SegTree(vector<int> arr) {
		int n = arr.size(); N = 1;
		// find nearest power of 2 above arr and initialise tree
		while (N < n) N = N << 1;
		seg = vector<int>(2*N,0);
		// insert elements as leaves
		for (int i=0; i<n; ++i) seg[i+N] = arr[i];
		buildTree();
	}

	void buildTree() {
		// update segment property
		for (int i = N-1; i >= 1; --i) {
			seg[i] = op(seg[2*i], seg[2*i+1]);
		}
	}
	int getNode(int k) {
		k += N;
		return seg[k];
	}
	void setNode(int k, int d) {
		k += N;
		seg[k] = d;
		for (k /= 2; k >= 1; k /= 2) {
			seg[k] = op(seg[2*k], seg[2*k+1]);
		} 
	} 
	int getSum(int a, int b) {
		a += N; b += N;
		int s = 0;
		while (a <= b) {
			// a is a right node - add and move right
			if (a%2==1) s = op(s,seg[a++]);
			// b is a left node - add and move left
			if (b%2==0) s = op(s,seg[b--]);
			a /= 2; b /= 2;
		}
		return s;
	}
};


signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
	vector<int> arr = {13,4,12,0,2,-3,1};
	SegTree segtree = SegTree(arr);
	_print(segtree.seg);
	segtree.updateNode(4,6);
	_print(segtree.seg);
	cout << segtree.getSum(1,4) << '\n';

}
