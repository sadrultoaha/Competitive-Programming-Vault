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

struct edl {
	int a, b; long long w;
	bool operator < (const edl &a) const {
		return w<a.w; }
}edlist[MAX*MAX], edlist2[MAX*MAX];
int P[MAX]; int R[MAX], NE, NV; // R[]=Rank

void makeset(int n) {
	for (int i = 1; i <= n; i++) { P[i] = i; }
}

int findP(int n) {
	if (P[n] == n)return n;
	P[n] = findP(P[n]); return P[n];
}

void Union(int a, int b) {
	int x = findP(a);
int y = findP(b);
if (x == y) return;
	else { P[x] = y; }
}
long long kruskal ( bool flg ) {
//Should kruskal add MST edges to mark[]?
	makeset(NE);
	sort(edlist, edlist + NE);
	int i, j, k = 0;
	long long cost = 0; edl top;
	for (i = 0; i<NE; i++) {
		top = edlist[i];
		if (findP(top.a) != findP(top.b)) {
			cost += top.w; k++;
			Union(top.a, top.b);
// if (flg)mark.push_back(i);
//Add MST edges to vector mark
			if (k == NV - 1)return cost;
		}
}
// return -1;
}
vector<int> mark;
int main() {
	int n, i, j, k;
	cin >> n;
	while (cin >> NV >> NE) {
		edl a; k = 0;
		for (i = 0; i<NE; i++) {
			cin >> a.a >> a.b >> a.w;
			edlist[k++] = a;
		}
		cout << kruskal(true) << " ";
		int mi = 9999999;
		for (i = 0; i<NE; i++)edlist2[i] = edlist[i];
		for (i = 0; i<mark.size(); i++) {
			edlist[mark[i]].w = 100000;
			j = kruskal(false);
			if (j<mi)mi = j;
			for (j = 0; j<NE; j++)edlist[j] = edlist2[j];
		}
		cout << mi << "\n"; //Cost of 2nd best MST
		mark.clear();
	}
}
