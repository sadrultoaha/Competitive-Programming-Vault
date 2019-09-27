
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
#define MAX 30/// ADDED by SunW

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/

vector <int> G[MAX], output[MAX];
int stck[MAX],num[MAX],component[MAX],low[MAX],onstack[MAX],top;
int idx, components, N;
void tarjan(int u) {
	num[u] = low[u] = idx++;
    stack[top++] = u;
onstack[u] = 1;
	for (int i = 0; i <G[u].size(); i++) {
		int v = G[u][i];
		if (num[v] == -1) {
			tarjan(v);
low[u] = min(low[u], low[v]);
		}
		else if (onstack[v])
			low[u] = min(low[u], num[v]);
	}
	int v;
	if (low[u] == num[u]) {
		do {
			v = stack[--top];
			onstack[v] = 0;
			component[v] = components;
			output[components].push_back(v);
// Storing SCCs in array of vector
		} while (u != v);
		components++;
	}
}
int main()
{
    int x=0;
    G[1].push_back(0);
     G[0].push_back(2);
      G[2].push_back(1);
       G[0].push_back(3);
        G[3].push_back(4);
          tarjan(x);


}
