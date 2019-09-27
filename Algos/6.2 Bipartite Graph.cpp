/// CODE is OK but no idea how it's work !!  chkd by SunW


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

int colour[MAX]; bool visited[MAX]; vector <int> G[MAX];

bool bipartite(int &no, int u) {
	queue<int> q;
	q.push(u); colour[u] = 0;
	int x, i, tot = 0, zr = 1;
	bool isBip = true;
	visited[u] = true;
	while (!q.empty() /* && isBip */) {
		tot++;
		x = q.front(); q.pop();
		for (i = 0; i<G[x].size(); i++) {
			int y = G[x][i];
			if (!visited[y]) {
				colour[y] = 1 - colour[x]; q.push(y);
            visited[y] = true;
				if (colour[y] == 0)zr++;
			}
			else if (colour[y] == colour[x]) { isBip = false; }
		}
	}
if (!isBip) { no = 0; return false; }
	if (tot <= 2) { no = 1; return true; }
	else { no = min(zr, tot - zr); }  return true;
// min or max
}
int main()
{
    int x=1;
    G[0].push_back(0);
    G[0].push_back(1);
    G[0].push_back(0);
    G[0].push_back(1);
        G[1].push_back(1);
    G[1].push_back(0);
    G[1].push_back(1);
    G[1].push_back(0);
        G[2].push_back(0);
    G[2].push_back(1);
    G[2].push_back(0);
    G[2].push_back(1);
        G[3].push_back(1);
    G[3].push_back(0);
    G[3].push_back(1);
    G[3].push_back(0);

    bipartite(x,0);




}
