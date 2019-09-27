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
#define MAX 100000000 /// ADDED by SunW
#define MOD 1000003 /// ADDED by SunW
#define dbg(x) cout << #x << " = " << x << endl

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/


/// Topological Sort with cycle check: (inside main)
// if ans.size()!= n   TOPOSORT FAILS

//Memory efficient
int col[MAX], fl;
vector<int> G[MAX], ans;
void toposort(int u) {
	col[u] = 1; int i, y;
	//col, 0 = non visited, 1 = not finished, 2 = finished
	for (i = 0; i<G[u].size(); i++){
		y = G[u][i];
		if (col[y] == 0) toposort(y);
		else if (col[y] == 1){    //cycle
			fl = 1; return;
}
}
	if (fl == 1) return;
	col[u] = 2; ans.push_back(u);
// ans contains elements in reversed topo order
}

/// All possible Topo sort:
int vals[MAX], ANS[MAX], N; 				 //vals = input
bool taken[MAX]; vector <int> GE[MAX];
void toposort(int u, int in[]){
	if (u == N) {}
// Possible sort found print, return

int i, j, x;
	vector <int> v; int _in[MAX];
	for (i = 0; i < MAX ; i++)_in[i] = in[i];
	for (i = 0; i<N; i++){
		x = vals[i];
		if (in[x] == 0 && !taken[x])v.push_back(x);
	}
	for (i = 0; i<v.size(); i++) {
		x = v[i];
taken[x] = true;
		ANS[u] = x;
		for (j = 0; j<GE[x].size(); j++){
			if (_in[GE[x][j]] > 0)_in[GE[x][j]]--;
		}
		toposort(u + 1, _in);
		taken[v[i]] = false;
		for (j = 0; j<= N; j++)_in[j] = in[j];
}
}

int main()
{
int n=5,x,y;
priority_queue<int, vector<int>, greater<int> > q;
int *indeg = new int[n + 2]{};
for (int i = 1; i <= n; i++) if (indeg[i] == 0) q.push(i);
if (q.empty()) {}                // TopoSort Fail
else {
	while (!q.empty()) {
		x = q.top();
		q.pop();
		ans.push_back(x);
		for (int i = 0; i< G[x].size(); i++) {
			y = G[x][i];
			if (indeg[y] == 0) break;
			//cycle found … break with flag
			else if (indeg[y] == 1) {
				indeg[y]--; q.push(y);
			}
			else  indeg[y]--;
		}
	}
}


}
