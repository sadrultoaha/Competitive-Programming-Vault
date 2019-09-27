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

struct node {
	int n, e;
	node() { n = 0; e = 0; }
	node(int _a, int _b) : n(_a), e(_b) {}
};
int dist[MAX], NV;
vector<node> G[MAX];
void init(int n) {
	memset(dist, 127, sizeof(dist));
	for (int i = 0; i <= n; i++)G[i].clear();
}
bool bellman_ford(int s) {
	dist[s] = 0;
	for (int k = 0; k < NV; k++) {
		for (int i = 0; i < NV; i++) {
			for (int j = 0; j < G[i].size(); j++) {
				int n = G[i][j].n; int e = G[i][j].e;
				if (dist[i] + e < dist[n]) {
					dist[n] = dist[i] + e;
					if (k == NV - 1)return false;
				}
			}
		}
	}
	return true;
}
int main()
{
    int n,e;
    for (int i = 0; i<5; i++) {
		cin >> n >> e;
		G[i].push_back(node(n, e));
    }
    cout<<bellman_ford(0);
}
