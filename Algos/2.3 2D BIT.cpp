/// OK chkd by SunW
/// solution of SPOJ MATSUM

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

#define LL long long

LL tree[1050][1050];
void update(int x, int y, LL val, int MAX) {
	while (x <= MAX) {
		int ty = y;
		while (ty <= MAX) {
			tree[x][ty] += val;
			ty += (ty & -ty);
		}
		x += (x & -x);
	}
}
LL read(int x, int y) {
	LL sum = 0;
	while (x) {
		int ty = y;
		while (ty) {
			sum += tree[x][ty];
			ty -= (ty & -ty);
		}
		x -= (x & -x);
	}
	return sum;
}
LL readRegtangle(int x0, int y0, int x1, int y1 ) {
	return read(x1, y1) + read(x0-1, y0-1)
- read(x0 -1, y1) - read(x1, y0 -1);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(tree, 0, sizeof tree);
		while (1) {
			char s[10];
			scanf("%s", s);
			if (s[1] == 'E') {
				int x, y, val;
				scanf(" %d%d%d", &x, &y, &val);
                LL p_val = readRegtangle(x+1, y+1, x+1, y+1);
                update(x + 1, y + 1, val - p_val, n + 9);

                }
			else if (s[1] == 'U') {
				LL sum = 0;
				int x1, y1, x, y;
				scanf(" %d%d%d%d", &x, &y, &x1, &y1);
				sum = readRegtangle(x+1, y+1, x1+1, y1+1);
				printf("%lld\n", sum);
			}
			else 	break;
		}
		printf("\n");
	}
}

