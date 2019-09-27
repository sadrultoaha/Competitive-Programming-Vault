/// OK chkd by SunW
/// LIGHTOJ Curious Robin Hood
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


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;
/** -------------------END TEMPLATE------------------------------------ **/

#define MAX 200010
#define ll long long /// ADDED by SunW

// SET N ** IMPORTANT
ll bit[MAX]; int N;

//returns sum from 1 to p
ll get(int p) {
	ll res = 0;
	for (; p >= 0; p = (p & (p + 1)) - 1) res += bit[p];
	return res;
}

void update(int p, ll val) {
	for (; p < N + 1; p = (p | (p + 1)))
		bit[p] += val;
}

ll rangeSum(int low, int high) {
	return get(high) - (low == 0 ? 0 : get(low - 1));
}

int main() {
	//read();
	int T, m, x, y, z;
	scanf("%d", &T);
	FORR(cs, 1, T + 1) {
		MEM(bit, 0);
		scanf("%d%d", &N, &m);
		FOR(i, N) {
			scanf("%d", &x);
			update(i + 1, x);
		}
		printf("Case %d:\n", cs);
		FOR(LLL, m) {
			scanf("%d", &x);
			if (x == 1) {
				scanf("%d", &y);
				int v = rangeSum(y + 1, y + 1);
				printf("%d\n", v);
				update(y + 1, -v);
			}
			else if (x == 2) {
				scanf("%d %d", &y, &z);
				update(y + 1, z);
			}
			else {
				scanf("%d %d", &y, &z);
				printf("%lld\n", rangeSum(y + 1, z + 1));
			}
		}
	}
}
