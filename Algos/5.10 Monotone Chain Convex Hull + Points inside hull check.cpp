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

#define ll64 long long
struct point {
	ll64 x, y;
	bool operator <(const point &p) const {
		return (x < p.x || (x == p.x && y < p.y));
	}
};

vector <point> CH, P;

ll64 cross(point p1, point p2, point p) {
	return (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) *
(p.x - p1.x);
}

void convexHull() {
	sort(P.begin(), P.end());
	int n = P.size(), k = 0;
	vector <point> H(2 * n);
	for (int i = 0; i<n; i++) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)k--;
		H[k++] = P[i];
	}
	H.resize(k);
	CH = H;
}

ll64 ar(point a, point b, point c) {
	return abs(a.x*(b.y - c.y) + b.x*(c.y - a.y) +
c.x*(a.y - b.y));
}


bool insideCH(point p) {

	point pi = CH[0];

	int low = 1, up = CH.size() - 2, mid;
	while (up - low>1) {
		mid = (low + up) >> 1;
		ll64 t = cross(pi, CH[mid], p);
		if (t<0) up = mid;
		else low = mid;
	}
	if ( ar(pi, CH[low], CH[up]) == (ar(pi, p, CH[low]) +
ar(pi, p, CH[up]) + ar(CH[low], p, CH[up]))) return true;
	return false;
}

int main() {
	//rd();
	int x, y, l, s;
	while (scanf("%d", &l) == 1) {

		P.clear(); CH.clear();

		point pp;
		for (int i = 0; i<l; i++) {
			scanf("%d %d", &x, &y);
			pp.x = x; pp.y = y;
			P.push_back(pp);
		}
		convexHull();

		int ans = 0;
		scanf("%d", &s);
		for (int i = 0; i<s; i++) {
			scanf("%d %d", &x, &y);
			pp.x = x; pp.y = y;
			if (insideCH(pp)) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}

