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
int n;
int v[] = {50, 3, 10, 7, 40, 80};/// ans 4
/// int v[]={3, 10, 2, 1, 20}; ///ans 3
///int v[]={ 10, 22, 9, 33, 21, 50, 41, 60 };///ans 5

int LISLength() {
	multiset<int> s; //use set if input doesn�t have duplicates
	multiset<int>::iterator it;
	for (int i = 0; i<n; i++) {
		s.insert(v[i]);
		it = upper_bound(s.begin(), s.end(), v[i]);
          /* for strictly increasing:
          it = lower_bound(s.begin(), s.end(), x); it++; */
		if (it != s.end()) s.erase(it);
	}
	return s.size();
}
int main() /// ADDED by SunW
{
    n = sizeof(v)/sizeof(v[0]);
    printf("Length of lis is %d",LISLength());
    return 0;
}

