#include <bits/stdc++.h>
#include <chrono>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

// much faster version
long long mulmod(long long a, long long b, long long mod) {
	return ((__int128) a * b) % mod;
}

long long power(int base, long long exp, long long mod=1e12) {
	long long res = 1LL, c = base;
	while (exp > 0) { // keep squaring c and halving exp 
		if (1 & exp) {
			res = mulmod(res, c, mod);
		}
		c = mulmod(c, c, mod);
		exp >>= 1;
	}
	return res;
}

vector<ll> allFactors(long long n) {
	vector<ll> factors;
	for (int i = 1; i * i <= n; ++i) {
		if (n%i == 0) factors.push_back(i);
		ll j = n / i;
		if (n%j == 0 && j!= i) factors.push_back(j);
	}
	return factors;
}

bool isprime(long long n) {
    if (n == 2 || n==3 || n==5) return true;
    if (n == 1 || n%2==0 || n%3==0 || n%5==0) return false;
    for (long long i = 7; i*i <= n; i+=30) { // 7,11,13,17,19,23,29,31
        if (n%i==0 || n%(i+4)==0 || n%(i+6)==0 || n%(i+10)==0 || n%(i+12)==0 
            || n%(i+16)==0 || n%(i+22)==0 || n%(i+24)==0) return false;
    } 
    return true;
}

bool millerisPrime(long long n) {
	// Miller-Rabin test // faster from n>=1e8 
	// deterministic up to 4.7e9 for a = 2,3,5,7
	if (n == 2 || n==7 || n==61) return true;
	if (n%2 == 0 || n<=1) return false;
	int s = 0;
	long long d = n-1;	
	while (d % 2 == 0) {s++; d >>= 1;}
	vector<int> as = {2,7,61};
	for (int a : as) {
		long long x = power(a,d,n);
		// cout << "power "<< a << " " << d << " " << n << " " << x << '\n';
		long long y;
		for (int i=0; i<s; ++i) {
		    y = mulmod(x,x,n);
			// cout << "y " << y << '\n';
			if (y == 1 && x != 1 && x != n-1) 
				return false;
			x = y;
		}
		if (y!= 1) return false;
	}
	return true;
}

vector<bool> sieve(int n) {
	n = max(10,n);
	vector<bool> isPrime (n+1,true);
	isPrime[0] = false; isPrime[1] = false;
	for (int i = 4; i<=n; i+=2) isPrime[i] = false;
	for (int i=3; i<=n/3; i+=2) {
		for (int j=3*i; j<=n; j+=2*i) {
		    isPrime[j] = false;
		}
	}
	return isPrime;
}


int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
	long long N = 5e8+1;
	//cout << millerisPrime(4e9+7) << '\n';
	//cout << isprime(4e9+7) << '\n';
	
	auto t1 = high_resolution_clock::now();
	for (long long i = N; i<N+100000; ++i) {
		if (millerisPrime(i)) continue;
	}
	auto t2 = high_resolution_clock::now();
	duration<double, milli> ms = t2-t1;
	cout << ms.count() << '\n';

	t1 = high_resolution_clock::now();

	for (long long i = N; i<N+100000; ++i) {
		//if (isprime(i) != millerisPrime(i)) cout << i << '\n';
		if (isprime(i)) continue;
	}
	t2 = high_resolution_clock::now();
	ms = t2-t1;
	cout << ms.count() << '\n';
	
	return 0;
}
