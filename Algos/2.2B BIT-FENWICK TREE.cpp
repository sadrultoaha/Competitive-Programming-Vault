/// OK chkd by SunW
/// range update, solution of spoj horrible
#include<bits/stdc++.h>
using namespace std;

template<class T > T _abs(T n) { return (n < 0 ? -n : n); }
template<class T > T _max(T a, T b) { return (!(a < b) ? a : b);}
template<class T > T _min(T a, T b) { return (a < b ? a : b); }
template<class T > T sq(T x) { return x * x; }


#define ll long long
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


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/

#define MAX 1000010

ll bit1[MAX], bit2[MAX]; int N;

ll get(ll *bit, int p) {
	ll res = 0;
	for (; p >= 0; p = (p & (p + 1)) - 1)
		res += bit[p];
	return res;
}
void update(ll *bit, int p, ll val) {
	for (; p < N + 1; p = (p | (p + 1)))
		bit[p] += val;
}

// adds val to each elements in [low, high]
void rangeUpdate(int low, int high, ll val) {
	update(bit1, low, val);
	update(bit1, high + 1, -val);
	update(bit2, low, val * (low - 1));
	update(bit2, high + 1, -val * high);
}
ll get_p(int pos) {
	return get(bit1, pos) * pos - get(bit2, pos);
}
// returns sum in range [low, high]
ll rangeSum(int low, int high) {
	return get_p(high) - (low == 0 ? 0 : get_p(low - 1));
}

int main() {
	cpp_io();
	//read();
	int t, c, m, p, q; ll v;
	cin >> t;
	while (t--) {
		cin >> N >> c; // importent set N!
		memset(bit1, 0, sizeof(bit1));
		memset(bit2, 0, sizeof(bit2));
		while (c--) {
			cin >> m;
			if (m == 0) {
				cin >> p >> q >> v;
				rangeUpdate(p, q, v);
			}
			else {
				cin >> p >> q;
				cout << rangeSum(p, q) << "\n";
			}
		}
	}
}

