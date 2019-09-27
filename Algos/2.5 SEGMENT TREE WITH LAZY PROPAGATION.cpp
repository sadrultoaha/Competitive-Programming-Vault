/// OK chkd by SunW
/// solution of SPOJ MULTQ3

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

const ll MAX = 500000;
struct NODE {
	int zero, one, two;
	NODE() {
		zero = one = two = 0;
	}
}tree[MAX];

int lazy[MAX];
void setNode(int node) {
	int ch1 = node << 1, ch2 = ch1 ^ 1;
	tree[node].zero = tree[ch1].zero + tree[ch2].zero;
	tree[node].one = tree[ch1].one + tree[ch2].one;
	tree[node].two = tree[ch1].two + tree[ch2].two;
}
void lazyUpdate(int node, int lazyVal, bool push) {
	int v[3];
	v[0] = tree[node].zero, v[1] = tree[node].one,
  		v[2] = tree[node].two;
	tree[node].zero = v[lazyVal];
	tree[node].one = v[(lazyVal + 1) % 3];
	tree[node].two = v[(lazyVal + 2) % 3];

	if (push) {
		lazy[node << 1] += lazyVal;
		lazy[(node << 1) | 1] += lazyVal;
	}
	lazy[node] = 0;
}

void build(int node, int first, int last) {
	if (first == last) tree[node].zero++;
	else {
		int mid = (first + last) >> 1;
		build(node << 1, first, mid);
		build((node << 1) | 1, mid + 1, last);

		setNode(node);
	}
}
void update(int node, int first, int last, int l, int r, int val) {
	if (lazy[node] != 0) {
		lazyUpdate(node, lazy[node] % 3, first != last);
	}
	if (first > last || first > r || last < l) return;

	if (first >= l && last <= r) { //update
		lazyUpdate(node, val % 3, first != last);
		return;
	}
	int mid = (first + last) >> 1;
	update(node << 1, first, mid, l, r, val);
	update((node << 1) | 1, mid + 1, last, l, r, val);

	setNode(node);
}
int query(int node, int first, int last, int l, int r) {
	if (first > last || first > r || last < l) return 0;
	if (lazy[node] != 0) {
		lazyUpdate(node, lazy[node] % 3, first != last);
	}
	if (first >= l && last <= r) return tree[node].zero;

	int mid = (first + last) >> 1;
	int p1 = query(node << 1, first, mid, l, r);
	int p2 = query((node << 1) | 1, mid + 1, last, l, r);

	return (p1 + p2);
}

int main() {
	//read();
	cpp_io();
	int n, m, x, y, z;
	cin >> n >> m;
	build(1, 1, n);
	FOR(i, m) {
		cin >> x >> y >> z;
		if (x == 1) {
			cout << query(1, 1, n, y + 1, z + 1) << "\n";
		}
		else {
			update(1, 1, n, y + 1, z + 1, 1);
		}
	}
}

