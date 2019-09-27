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
#define MAX 100000000 /// ADDED by SunW

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/

long long phi[MAX + 2], mark[MAX + 2];
//Phi from 1 to n
void ETF(int n)
{
	int i, j;
	for (i = 0; i <= n; i++)phi[i] = i;
	mark[1] = 1;
	for (i = 2; i <= n; i++) {
		if (!mark[i]) {
			for (j = i; j <= n; j += i) {
				mark[j] = 1;
				phi[j] = phi[j] / i * (i - 1);
                }
            }
        }
}
int phif(int n) { //phi for n
	int ret = n;
//iterate through primes[] for faster result
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			while (n%i == 0) n /= i;
			ret -= ret / i;
		}
	}
	if (n > 1)ret -= ret / n;
	return ret;
}

int main()
{
        int X = 12;
        ETF(X);
        for (int i=1; i<=X; i++)
        cout << "Totient of " << i << " is "
           << phi[i] << endl;


        for (int n = 1; n <= 10; n++)
        printf("phi(%d) = %d\n", n, phif(n));

}

