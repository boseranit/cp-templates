#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>
#define pii pair<int, int>
#define forr(i,a,n) for (int i = (a); i < (n); ++i)
#define rforr(i,a,n) for (int i = (a); i > (n); --i)
#define ALL(x) x.begin(),x.end()
#define LEN(X) ((int)(X).size())
#define CASET int _T; cin >> _T; forr(caset,0,_T)
#define sq(x) (x)*(x)
//#define int ll

// DEBUGGING
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


// vector containing digits of int
vi intToVec(ll n) {
    string s = to_string(n);
    vi a;
    for (char i : s) 
        a.push_back(i - '0');
    return a;
}


// MULTIPLICATION
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

const int mod = 1e9+7;
ll power(int base, ll exp, ll mod=1e12) {
	long long res = 1LL, c = base;
	while (exp > 0) { // keep squaring c and halving exp 
		if (1 & exp) res = ((__int128) res * c) % mod;
		c = ((__int128) c * c)%mod;
		exp >>= 1;
	}
	return res;
}

int mult(int a, int b) {
    return (1LL*a*b)%mod;
}
int mult(int a, int b, int c) {
    return mult(mult(a,b), c);
}
int mult(int a, int b, int c, int d) {
    return mult(mult(a,b,c),d);
}
int inv(int a) {
    return power(a, mod-2);
}

// better to precalc factorials and inverse facts
int binom(int n, int k)  {  
    int res = 1;  
    if ( k > n - k ) k = n - k;  
    for (int i = 0; i < k; ++i) {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
    return res;  
}



// binary search
// greatest x such that f(x) <= n for monotone f and n
int lbinary_search( int (*f)(int), int n, int lo, int hi) {
    int mid = (lo+hi)/2;
    while (lo < hi) {
        mid = (lo+hi)/2+1;
        if ((*f)(mid) == n) {
            return mid;
        } else if ((*f)(mid) > n) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    return lo;
}

// binary search
// lowest x such that f(x) >= n for monotone f and n
int ubinary_search( int (*f)(int), int n, int lo, int hi) {
    int mid = (lo+hi)/2;
    while (lo < hi) {
        mid = (lo+hi)/2;
        if ((*f)(mid) == n) {
            return mid;
        } else if ((*f)(mid) > n) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    return lo;
}

signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("input.txt","r",stdin);
    //ofstream fout ("output.txt");
	cout << power(2, 1500000009, 3e9+19) << '\n'; // 3e9+18
    
    //fout.close();
}
