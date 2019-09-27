///NO IDEA ??

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

/* Solves equations of the format x % mods[i] = r[i],
( 0<=i<n, where n is the number of equations ) */
long long CRT (vector< long long > &r,vector< long long > &mods) {
	long long M = 1, ret = 0;
	for (int i = 0; i<int(mods.size()); i++) M *= mods[i];
	vector< long long > m, s;
	for (int i = 0; i<int(mods.size()); i++) {
		m.push_back(M / mods[i]);
		long long temp = m[i] % mods[i], k = 0;
		/*if there is a possibility of k being very big, then
		prime factorize m[i], find modular inverse of 'temp'
		of each of the factors 'k' equals to the multiplication
          (modular mods[i]) of modular inverses */
		while (true) {
			if ((k*temp) % mods[i] == 1) break;
			k++;
		}
		s.push_back(k);
	}
	for (int i = 0; i<int(s.size()); i++) {
		ret += ((m[i] * s[i]) % M *r[i]) % M;
		if (ret >= M) ret -= M; }
	return ret;
}
int main()
{
    vector< long long > x;
    vector< long long > y;
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    y.push_back(2);
    y.push_back(3);
    y.push_back(1);
    cout<<CRT(x,y);
}
