///code is working but have no idea about it.

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

#define MAX 100
int m[MAX][MAX], s[MAX][MAX];
int MatrixChainOrder(int p[], int n){
	n = n - 1;  //length of p -1
	int L, i, j, k, q;
	for (int i = 1; i <= n; i++) m[i][i] = 0;
	for ( L = 2; L <= n; L++) {
		for (i = 1; i <= n - L + 1; i++) {
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j]
                + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return  m[1][n];
}
void print(int p[], int i , int j) {
	if (i == j) cout << p[i]<< " ";
	else {
		cout << "(";
		print(p, i, s[i][j]);
		print(p, s[i][j]+1, j);
		cout << ")";
	}
}
int main() {
	int p[] = { 4,10,3,12,20,7 };
	cout<<MatrixChainOrder(p,6);
	print(p, 1, 5);
}
