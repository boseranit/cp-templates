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
    return power(a, mod-2, mod);
}

void calcFactorials(vector<int>& factorial, int mod) {
	factorial[0] = 1;
	for (int k = 1; k < (int)factorial.size(); ++k) {
		factorial[k] = (factorial[k-1]*k) % mod;
	}
}
void calcInvFactorials(vector<int>& factorial,vector<int>& invfactorial, int mod) {
	for (int i=0; i<(int) invfactorial.size(); ++i) {
		invfactorial[i] = inv(factorial[i], mod);
	}
}
int binom(int n, int k, vector<int>& facts, vector<int>& invfacts) {
	if (n==0 && k==0) return 1;
	if (k > n) return 0;
	if (k < 0) return 0;
	return mult(facts[n], invfacts[n-k], invfacts[k]);
}

// better to precalc factorials and inverse facts
int binom2(int n, int k)  {  
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
    vector<int> factorial (2e5+1);
	vector<int> invfactorial (2e5+1);
	calcFactorials(factorial, mod);
	calcInvFactorials(factorial,invfactorial, mod);

    //fout.close();
}
