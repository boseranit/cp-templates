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


template <typename A>
void printVec(vector<A> p) {
    cout << "[";
    for (auto it = p.begin(); it < p.end()-1; it++)
        cout << *it << ", ";
    cout << p.back() << "]\n";
}

int power(int base, ll exp, int mod=INT_MAX) {
    if (exp == 0) return 1;
    if (exp == 1) return base%mod;
    ll res = (long long) power(base,exp/2,mod); res = res*res%mod;
    return (exp%2==0) ? res : (base*res)%mod;
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crypt1.in","r",stdin);
    ofstream fout ("crypt1.out");
    
    fout.close(); 
    return 0;
}