/// NOT OK chkd by SunW

#include<bits/stdc++.h>
using namespace std;

template<class T > T _abs(T n) { return (n < 0 ? -n : n); }
template<class T > T _max(T a, T b) { return (!(a < b) ? a : b);}
template<class T > T _min(T a, T b) { return (a < b ? a : b); }
template<class T > T sq(T x) { return x * x; }


#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

#define cpp_io() {ios_base::sync_with_stdio(false);cin.tie(0);} /// ADDED by SunW
#define FOR(i,N) FORR(i,0,N) /// ADDED by SunW
#define FORR(i,a,b) FOTR(i,a,b,1) /// ADDED by SunW
#define FOTR(i,a,b,c) for(int i=(a);i<(b);i+=(c)) /// ADDED by SunW
#define ll long long /// ADDED by SunW

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/


#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
int primes[100],segment[100]; /// ADDED by SunW
#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 100032
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))


void segmented_sieve(int a, int b) {
	unsigned i, j, k, cnt = (a <= 2 && 2 <= b) ? 1 : 0;
	if (b<2) return;
	if (a<3) a = 3;
	if (a % 2 == 0) a++;

	mset(segment, 0);
	for (i = 1; sq(primes[i]) <= b; i++) {
		j = primes[i] * ((a + primes[i] - 1) / primes[i]);
		if (j % 2 == 0) j += primes[i];
		for (k = primes[i] << 1; j <= b; j += k)
			if (j != primes[i]) setC(segment, (j - a));
	}
}
bool isPrimeSeg(int n, int a) {
	if (n == 2)return true;
	else if (!(n & 1) || n<2) return false;
	if (!chkC(segment, n - a))return true;
	return false;
}
int main()
{
    segmented_sieve(1,100);

}
