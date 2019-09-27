///NOT OK chkd by SunW

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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/
long long F[MAX];
void initF() {
	F[1] = 1; F[0] = 1;
	for (int i = 2; i < MAX; i++)
		F[i] = (F[i - 1] * i) % MOD;
}
long long POW(int a, int b){ // a^b)%MOD
	long long x = 1, y = a;
	while (b > 0){
		if (b & 1) x = (x*y) % MOD;
		y = (y*y) % MOD;
		b >>= 1; }
	return x;
}
long long inversePow(int n){
	return POW(n, MOD - 2);
}
long long C(int n, int r){
	return (F[n] * ((inversePow(F[r]) *
		inversePow(F[n - r])) % MOD)) % MOD;
}
long long P(int n, int r) {
	return (F[n] * inversePow(F[n-r])) % MOD;
}


int main()
{
    int n=5,r=3;
    cout<<C(5,3);
    cout<<P(5,3);
}


