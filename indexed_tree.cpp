#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SORT(x) sort(x.begin(),x.end())
#define LEN(X) ((int)(X).size())
#define CASET int _T; cin >> _T; forr(caset,0,_T)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// less_equal<int> allows multiple occurences vs less<int>
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,
		tree_order_statistics_node_update> indexed_set;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    indexed_set s;
	s.insert(4);
	s.insert(5);
	s.insert(8);
	s.insert(2);
	s.insert(3);
	cout << *(s.find_by_order(1)) << endl;
    return 0;
}
