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
	bool operator<(const node &B)const {
		return e>B.e;
	}
};

vector<node>G[MAX];
bool visited[MAX];
int parent[MAX], C[MAX], root;

long long mst() {
	C[root] = 0;
	priority_queue<node> Q;
	Q.push(node(root, 0));
	long long cost = 0;
	while (!Q.empty()) {
		node u = Q.top();
		Q.pop();
		if (!visited[u.n]) {
			cost += u.e;
			visited[u.n] = true;
			for (int i = 0; i<G[u.n].size(); i++) {
				node v = G[u.n][i];
				if (!visited[v.n] && C[v.n]>v.e) {
					Q.push(v);
					C[v.n] = v.e;
					parent[v.n] = u.n;
				}
			}
		}
	}
	return cost;
}
int main()
{


}
