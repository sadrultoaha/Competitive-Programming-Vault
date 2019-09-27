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

#define MEM(p, v) memset(p, v, sizeof(p))
struct Node {
	int node, cost, par;
	Node() { node = 0; cost = 0; par = 0; }
	Node(int _a, int _b, int _c) : node(_a), cost(_b), par(_c) {}

	bool operator< (const Node &A) const {
		return cost > A.cost;
	}
};

int dist[MAX], visited[MAX], inf;
vector<Node> G[MAX];
vector<int> P[MAX];
vector<pair<int, int> > spedges;   //shortest path edges

void btrack(int n) {
	if (P[n].size() == 0 || visited[n]) return;
	visited[n] = 1;
	for (int i = 0; i<P[n].size(); i++) {
		int pr = P[n][i];
		spedges.push_back(make_pair(n, pr));
		btrack(pr);
	}
}
void dijkstra(int s, int d) {
	MEM(visited, 0);
	MEM(dist, 127);
	dist[s] = 0;
	Node nd(s, 0, -1);
	priority_queue<Node> Q;
	Q.push(nd);
	while (!Q.empty()) {
		int cn = Q.top().node;
		int dst = dist[cn];
		Node tp = Q.top();  Q.pop();
		if (dst == tp.cost && cn != s) {
			P[cn].push_back(tp.par);
		}
		if (visited[cn])continue;
		for (int i = 0; i < G[cn].size(); i++) {
			int n = G[cn][i].node;
			int c = G[cn][i].cost;
			if (dst + c <= dist[n]) {
				dist[n] = dst + c;
				Q.push(Node(n, dist[n], cn));
			}
		}
		visited[cn] = 1;
	}
}
int main() {
	cpp_io();
	///freopen("input.txt", "r", stdin);
	int n, e, a, b, c, s, d;
	cin >> n >> e;
	for (int i = 0; i<e; i++) {
		cin >> a >> b >> c;
		G[a].push_back(Node(b, c, -1));
		G[b].push_back(Node(a, c, -1));
	}
	cin >> s >> d;
	dijkstra(s, d);
	memset(visited, 0, sizeof(visited));
	btrack(d);
	for (int i = 0; i<spedges.size(); i++)
		cout << spedges[i].first << " " << spedges[i].second <<endl;
}

