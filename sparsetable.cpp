#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(x) x.begin(),x.end()
#define LEN(X) ((int)(X).size())

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    return os << "(" << p.first << "," << p.second << ")";
}
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& x) {
    os << '[';
    if(x.empty()) return os << ']';
    for (size_t i=0; i<x.size(); ++i) os << x[i] << " ";
	return os << "\b]\n";
}

template <class T> class sparseTable {
public:
	T op(T a, T b) {
		return min(a,b);
	}
	int n;
	vector<vector<T>> st; // st[d][i] describes [i,i+2^d)
	
	sparseTable() {}
	sparseTable(vector<T> arr) {
		n = arr.size();
		st = vector<vector<T>> (__lg(n)+1, vector<T>(n));
		st[0] = arr;
		for (size_t d=1; d<st.size(); d++) {
			for (int i=0; (i+(1<<d)-1)<n; ++i) {
			    st[d][i] = op(st[d-1][i], st[d-1][i+(1<<(d-1))]);
			}
		}
	}

	T query(int l, int r) {
		int d = __lg(r-l+1);
		return op(st[d][l], st[d][r-(1<<d)+1]);
	}
};

signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
	vector<int> arr = {13,4,12,0,2,-3,1};
	sparseTable<int> segtree = sparseTable(arr);
	cout << segtree.st;
	cout << segtree.query(0,0) << '\n';
	cout << segtree.query(0,1) << '\n';
	cout << segtree.query(0,2) << '\n';
	cout << segtree.query(0,3) << '\n';
	cout << segtree.query(0,4) << '\n';
	cout << segtree.query(0,5) << '\n';
	cout << segtree.query(1,3) << '\n';
	cout << segtree.query(1,4) << '\n';
	cout << segtree.query(1,5) << '\n';
	cout << segtree.query(2,5) << '\n';

}
