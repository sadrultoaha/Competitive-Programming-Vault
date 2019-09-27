///OK chkd by SunW

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
#define MAX 30/// ADDED by SunW

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/

#define N 2000
int n, a[N], m, b[N], dp[N], pr[N], l;
void trace(int x, bool m) {
	if (!x) return;
	trace(pr[x], 1);
	printf("%d", b[x]);
	putchar(m ? ' ' : '\n');
}
void lcis() {
	int i, j;
	memset(dp, 0, sizeof(dp));
	memset(pr, 0, sizeof(pr));
	for (i = 1; i <= n; i++) {
		int c = 0, p = 0;
		for (j = 1; j <= m; j++) {
			if (a[i] == b[j] && dp[j] < c + 1) {
				dp[j] = c + 1;
				pr[j] = p;
			}
			if (a[i] > b[j] && c < dp[j]) {
				c = dp[j];
				p = j;
			}
		}
	}
l = -1; // l = lcis length
	for (i = 1; i <= m; i++) l = max(l, dp[i]);
}
int main() {
	scanf("%d", &n); /// let n = 4
	int i, j;
	for (i = 1; i <= n; i++) scanf("%d", &a[i]); /// let  a[] = {3, 4, 9, 1};
	scanf("%d", &m); /// let m = 7
	for (i = 1; i <= m; i++) scanf("%d", &b[i]);/// let b[] = {5, 3, 8, 9, 10, 2, 1};
	lcis();
	printf("Length of LCIS is %d\n\n", l); /// Length of LCIS is 2

	if (l) {
		for (i = 1; i <= m; i++)
			if (dp[i] == l) {
                cout<<"The LCIS is : ";
				trace(i, 0); /// The LCIS is :3 9 --> a[0]= 3, b[3] = 9
				break;
			}
	}
}

