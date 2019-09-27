/// OK chkd by SunW


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
#define MAX 100000000 /// ADDED by SunW
#define MOD 1000003 /// ADDED by SunW
#define dbg(x) cout << #x << " = " << x << endl


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/

const long long LIM = 100000000000000000;
const int small_primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51, 53, 59, 61, 67, 71 };

long long mul(long long a, long long b, long long m) {
	long long x, res;
	if (a < b) swap(a, b);
	if (!b) return 0;
	if (a < (LIM / b)) return ((a * b) % m);
res = 0, x = (a % m);
	while (b) {
		if (b & 1) {
			res = res + x;
			if (res >= m) res -= m;
		}
		b >>= 1; x <<= 1;
		if (x >= m) x -= m;
	}
	return res;
}
long long expo(long long x, long long n, long long m) {
	long long res = 1;

	while (n) {
		if (n & 1) res = mul(res, x, m);
		x = mul(x, x, m);
		n >>= 1;
	}

	return (res % m);
}
bool miller_rabin(long long p, int lim) {
	if (p < 2) return false;
	if (p == 2) return true;
	if (!(p & 1)) return false;
	int i, val;
	long long a, s, m, x, y;
	for (i = 0; i < 20; i++) {
		val = small_primes[i];
		if (p == val) return true;
		if ((p % val) == 0) {
			return false;
		}
	}
	srand(time(0));
	s = p - 1, y = p - 1;
	while (!(s & 1)) s >>= 1;

	while (lim--) {
		x = s;
		a = (rand() % y) + 1;
		m = expo(a, x, p);

		while ((x != y) && (m != 1) && (m != y)) {
			m = mul(m, m, p);	x <<= 1;
		}
		if ((m != y) && !(x & 1)) return false;
	}
	return true;
}
int main()
{
    cout<<mul(5,6,7)<<endl;
    cout<<miller_rabin(5,7)<<endl;
    cout<<expo(5,6,7)<<endl;

}
