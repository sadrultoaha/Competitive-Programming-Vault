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
#define MAX 30/// ADDED by SunW

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/

char str1[]="ababab", str2[]="ababab"; /// ADDED by SunW
int lcs(int n1, int n2) {
	int lcs[n1+1][n2+1];
	for (int i = 0; i <= n1; i++)
		for (int j = 0; j <= n2; j++) {
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
				if (str1[i - 1] == str2[j - 1])
					lcs[i][j] = max(lcs[i][j],
lcs[i - 1][j - 1]+ 1);
			}
		}
	return lcs[n1][n2];
}

int main() /// ADDED by SunW
{
     int m = strlen(str1);
     int n = strlen(str2);
     printf("Length of LCS is %d", lcs(m, n));
     return 0;
}
