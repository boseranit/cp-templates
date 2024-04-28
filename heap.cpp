#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define forr(i,a,n) for (int i = (a); i < (n); ++i)
#define rforr(i,a,n) for (int i = (a); i > (n); --i)
#define SORT(x) sort(x.begin(),x.end())
#define LEN(X) ((int)(X).size())
#define CASET int _T; cin >> _T; forr(caset,0,_T)

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


class MinHeap {
	vector<int> arr; // pointer to array of elements in MinHeap
	int sign;
	int n; // current number of elments in heap
	
	public:
	
	MinHeap(bool isMin=true) : n(0) {
		sign = isMin ? 1 : -1; // maxHeap if isMin==false		
	}

	bool empty() {
		return n==0;
	}

	void heapify(int node) {
		// assume that left and right children are already heaps
		// but node might be larger than either child 
		// Keep swapping values with smallest child until done
		int l = 2*node;
		int r = 2*node+1;
		// identify the smallest among the node and its children
		int smallest = node;
		if (l < n && arr[l] < arr[node]) smallest = l;
		if (r < n && arr[r] < arr[smallest]) smallest = r;
		if (smallest != node) {
			// swap child and node
			swap(arr[node], arr[smallest]);
			heapify(smallest);
		}
	}

	void build_heap() {
		// turns an arbitary list into a heap from bottom up 
		// leaves of the tree are from arr[n/2] to arr[n-1]
		// so call heapify on parents of the leaves
		for (int i=n/2-1; i>=0; --i) {
		    heapify(i);
		}
	}

	void insert(int k) {
		// insert at the end of the list and swap values with parent 
		// until heap property is satisfied
		arr.push_back(sign*k);
		n++;
		int node = n-1;
		while (arr[node] < arr[node/2]) {
			swap(arr[node/2], arr[node]);
			node = node/2;
		}
	}

	int pop() {
		// remove the top element and return the value
		// the hole is filled by putting the last value in the array
		// on the top and floating it down
		int val = arr[0];
		arr[0] = arr[n-1];
		arr.pop_back();
		n--;
		heapify(0);
		return sign*val;
	}

};

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
	vector<int> arr = {13,4,12,0,2,-3,1,2,5};
	MinHeap heap = MinHeap(false);
	for (int k : arr) heap.insert(k);
	while (!heap.empty()) {
		cout << heap.pop() << '\n';
	}
    return 0;
}
