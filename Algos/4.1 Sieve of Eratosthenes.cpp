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

#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 100032
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
unsigned base[MAX / 64], segment[RNG / 64], primes[LEN];
void sieve() {
	unsigned i, j, k;
	for (i = 3; i<LMT; i += 2)
		if (!chkC(base, i))
			for (j = i*i, k = i << 1; j<MAX; j += k)
				setC(base, j);
	primes[0] = 2; j = 1;
	for (i = 3; i<MAX; i += 2)
		if (!chkC(base, i))
			primes[j++] = i;
}
bool isPrime(int n) {
	if (n == 2 || (n > 2 && n & 1 && !chkC(base, n)))return true;
	return false;
}

int main()
{
    sieve();
    int x;
    for(int i=0;i<=100;i++){
    if(isPrime(i))cout<<i<<"-"<<"yes"<<endl;
    else cout<<"no"<<endl;
    }
}
