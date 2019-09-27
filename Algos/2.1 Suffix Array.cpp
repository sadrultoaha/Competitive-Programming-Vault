//OK chkd by SunW
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


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPATE------------------------------------ **/

/**
sa:
The suffix array. Contains the n suffixes of s sorted in lexicographical order. Each suffix is represented as a single integer (the position in the string where it starts).

rank:
The inverse of the suffix array. rank[i] = the index of the suffix s[i..n) in the pos array. (In other words, sa[i] = k <==> rank[k] = i). With this array, you can compare two suffixes in O(1):
    Suffix s[i..n) is smaller than s[j..n) if and only if rank[i] < rank[j].

lcp:
The length of the longest common prefix between two consecutive suffixes:
    lcp[i] = lcp(s + sa[i], s + sa[i-1]). lcp[0] = 0.

lcp(i,j)= min(lcp[i],lcp[i+1],...,lcp[j-1]).
**/

int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
const int MAXN = 100005;
char s[MAXN];
int t, n, rnk[MAXN], sa[MAXN], lcp[MAXN];
// n = strlen(s) + 1
bool compare(int i, int j) {
	return rnk[i + t] < rnk[j + t];
}
void setLCP() {
	int size = 0, i, j;
	for (i = 0; i < n; i++) if (rnk[i] > 0) {
		j = sa[rnk[i] - 1];
		while (s[i + size] == s[j + size]) ++size;
		lcp[rnk[i]] = size;
		if (size > 0) --size;
	}
	lcp[0] = 0;
}

int distinctSubstringsCount() {
	int ans = n - 1 - sa[1], i;
	for (i = 2; i < n; i++) {
		int ln = n - 1 - sa[i];
		ans += (ln - lcp[i]);
	}
	return ans;
}

void distinctSubstrings() {
	vector<pair<int, int>> substrs;
	int i, j, ln;
	for (i = 1; i < n; i++) {
		ln = n - 1 - sa[i];
		for (j = sa[i] + lcp[i]; j < n - 1; j++)
			substrs.push_back(make_pair(sa[i], j-sa[i]+1));
	}
	for (i = 0; i < substrs.size(); i++) {
for (j = substrs[i].first; j < substrs[i].first
+ substrs[i].second; j++) printf("%c", s[j]);
		printf("\n");
	}
}



void build() {
	int bc[256];
	for (int i = 0; i < 256; ++i) bc[i] = 0;
	for (int i = 0; i < n; ++i) ++bc[s[i]];
	for (int i = 1; i < 256; ++i) bc[i] += bc[i - 1];
	for (int i = 0; i < n; ++i) sa[--bc[s[i]]] = i;
	for (int i = 0; i < n; ++i) rnk[i] = bc[s[i]];
	for (t = 1; t < n; t <<= 1) {
		for (int i = 0, j = 1; j < n; i = j++) {
			while (j < n && rnk[sa[j]] == rnk[sa[i]]) j++;
			if (j - i == 1) continue;
			int *start = sa + i, *end = sa + j;
			sort(start, end, compare);
			int first = rnk[*start + t], num = i, k;
			for (; start < end; rnk[*start++] = num) {
				k = rnk[*start + t];
				if (k != first and (i > first or k >= j))
					first = k, num = start - sa;
			}
		}
	}
	setLCP();
}
void search(char *pat){
	int m = strlen(pat);
	int l = 1, r = n - 1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		int res = strncmp(pat, s + sa[mid], m);
		if (res == 0){
			cout << s + sa[mid] << endl;
			return;
		}
		if (res < 0) r = mid - 1;
		else l = mid + 1;
	}
	cout << "Pattern not found\n";
}

void printSuffixStrings() {
//prints suffixes in lexicographical order
	for (int i = 1; i < n; ++i) {
		printf("%s\n", (s + sa[i]));
	}
}
int main() {
	scanf("%s", s);
	n = strlen(s) + 1;
	build();
	//printSuffixStrings();
	distinctSubstrings();
	//cout<<distinctSubstringsCount() ;

//	for (int i = 0; i<5; i++) {
//		char st[10];
//		scanf("%s", st);
//		search(st);
//	}
}
