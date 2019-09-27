/// OK chkd by SunW
/// solution of SPOJ GSS3

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
const ll MIN = -50000000000000000LL;

struct NODE {
	ll rmax, lmax, tmax, sum;
}tree[MAX];

int inp[MAX];

int max3(ll a, ll b, ll c) {
	ll mx = a;
	if (b>mx)mx = b;
	if (c>mx)mx = c;
	return mx;
}




void setNode(int node) {
	int ch1 = node << 1, ch2 = ch1 | 1;
	tree[node].sum = tree[ch1].sum + tree[ch2].sum;
	tree[node].lmax =
max(tree[ch1].lmax, tree[ch1].sum + tree[ch2].lmax);
	tree[node].rmax =
max(tree[ch2].rmax, tree[ch1].rmax + tree[ch2].sum);
	tree[node].tmax = max3(tree[ch1].tmax, tree[ch2].tmax,
		tree[ch1].rmax + tree[ch2].lmax);
}

NODE join(NODE n1, NODE n2) {
	NODE n;
	n.sum = n1.sum + n2.sum;
	n.lmax = max(n1.lmax, n1.sum + n2.lmax);
	n.rmax = max(n2.rmax, n1.rmax + n2.sum);
	n.tmax = max3(n1.tmax, n2.tmax, n1.rmax + n2.lmax);
	return n;
}

void build(int node, int first, int last) {
	if (first == last) {
		tree[node].rmax = tree[node].tmax = tree[node].sum
			= tree[node].lmax = inp[first];
	}
	else {
		int mid = (first + last) >> 1, ch1 = node << 1, ch2 = ch1 | 1;
		build(ch1, first, mid);
		build(ch2, mid + 1, last);
		setNode(node);
	}
}

void update(int node, int first, int last, int p, int val) {

	if (first == last) {
		tree[node].rmax = tree[node].tmax = tree[node].sum =
			tree[node].lmax = val;
		return;
	}
	int mid = (first + last) >> 1;
	if (p <= mid)update(node << 1, first, mid, p, val);
	else update((node << 1) | 1, mid + 1, last, p, val);

	setNode(node);
}

NODE query(int node, int first, int last, int l, int r) {

	if (first > last || first > r || last < l) return{MIN,MIN,MIN,MIN };
	if (first >= l && last <= r) return tree[node];

	int mid = (first + last) >> 1;
	NODE n1 = query(node << 1, first, mid, l, r);
	NODE n2 = query((node << 1) | 1, mid + 1, last, l, r);

	if (n1.tmax == MIN)return n2;
	else if (n2.tmax == MIN) return n1;

	return join(n1, n2);
}
int main() {
	//read();
	cpp_io();
	int n, m, x, y, z;
	cin >> n;
	FORR(i, 1, n + 1)cin >> inp[i];

	build(1, 1, n);
	cin >> m;
	FOR(i, m) {
		cin >> x >> y >> z;
		if (x == 1) {
			NODE nd = query(1, 1, n, y, z);
			cout << nd.tmax << "\n";
		}
		else {
			update(1, 1, n, y, z);
		}
	}
}

