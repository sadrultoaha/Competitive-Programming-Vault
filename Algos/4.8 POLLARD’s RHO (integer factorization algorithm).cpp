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
const long long LIM = LLONG_MAX;
uint64_t gcd(uint64_t a, uint64_t b) { return b? gcd(b, a%b) : a;}
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
const int small_primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 51, 53, 59, 61, 67, 71 };

bool miller_rabin(long long p, int lim) {
	long long a, s, m, x, y;
	s = p - 1, y = p - 1;
	while (!(s & 1)) s >>= 1;

	while (lim--) {
		x = s;
		a = (rand() % y) + 1;
		m = expo(a, x, p);

		while ((x != y) && (m != 1) && (m != y)) {
			m = mul(m, m, p); x <<= 1;
		}
		if ((m != y) && !(x & 1)) return false;
	}
	return true;
}
void brent_pollard_rho(uint64_t n, vector <uint64_t> &v) {
	if (miller_rabin(n, 10)) {
		v.push_back(n);
		return;
	}
	uint64_t a, g, x, y;
	y = 1;
	a = rand() % n;
	x = rand() % n;

	for (int i = 0; ((i * i) >> 1) < n; i++) {
		x = mul(x, x, n);
		x += a;
		if (x < a) x += (ULLONG_MAX - n) + 1;
		x %= n;
		g = gcd(n, y - x);
		if ((g != 1) && (g != n)) {
			n /= g;
			brent_pollard_rho(g, v);
			if (n != g) brent_pollard_rho(n, v);
			else if (miller_rabin(n, 10)) v.push_back(n);
			return;
		}
		if (!(i & (i - 1))) y = x;
	}
	brent_pollard_rho(n, v);
}
void factorize(uint64_t n, vector <uint64_t> &v) {
	srand(time(0));
	int i, j, x;
	for (i = 0; i < 21; i++) {
		x = small_primes[i];
		while ((n % x) == 0) {
			n /= x; v.push_back(x); }
	}
	if (n > 1) brent_pollard_rho(n, v);
	sort(v.begin(), v.end());
}
vector < pair <uint64_t, int> > fc;
vector <uint64_t> dv;
void divs(int n, int i) {
	uint64_t j, x, k;
	for (j = i; j<fc.size(); j++) {
		x = fc[j].first * n;
		for (k = 0; k<fc[j].second; k++) {
			dv.push_back(x);
			divs(x, j + 1);
			x *= fc[j].first;
		}
	}
}
void divisors(vector<uint64_t> &v) {
	dv.clear(); fc.clear();
	int c = 0;
	for (int i = 0; (i + 1) < v.size(); i++) {
		if (v[i] == v[i + 1]) c++;
		else {
			if (c) fc.push_back(make_pair(v[i], c + 1));
			else fc.push_back(make_pair(v[i], 1));
			c = 0;
		}
	}
	divs(1, 0);
	sort(dv.begin(), dv.end());
}
int main() {
uint64_t n, i, t, x;
 cin >> t;
	while (t--) {
		cin >> n;
		vector <uint64_t> v;
		factorize(n, v);
		sort(v.begin(), v.end());
		v.push_back(-1); /***IMPORTANT***/
		int len = v.size(), c = 0, counter = 0;
		printf("%llu = ", n);
		for (i = 0; (i + 1) < len; i++) {
			if (v[i] == v[i + 1]) counter++;
			else {
				if (c) printf(" * ");
				if (counter)
					printf("%llu^%d", v[i], ++counter);
				else printf("%llu", v[i]);
				c++, counter = 0;
			}
		}
		puts(""); divisors(v);
		for (auto i : dv)cout << i << " ";
		cout << endl;
	}
}
