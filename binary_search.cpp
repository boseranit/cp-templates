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

int upper_binary_search(vector<int> a, int target) {
	// highest index <= target
	int l = 0;
	int r = a.size()-1;
	int mid;
	while (r != l) {
		mid = (l+r)/2+1;
		if (a[mid] <= target) l = mid;
		else r = mid - 1;
	}
	return l;
}

int lower_binary_search(vector<int> a, int target) {
	// lowest index >= target
	int l = 0;
	int r = a.size()-1;
	int mid;
	while (r != l) {
		mid = (l+r)/2;
		if (a[mid] < target) l = mid+1;
		else r = mid;
	}
	return r;
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crypt1.in","r",stdin);
    ofstream fout ("crypt1.out");
    
    fout.close(); 
    return 0;
}
