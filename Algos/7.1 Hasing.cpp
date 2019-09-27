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

typedef unsigned long long ull;
const int P = 31, SIZE = 100000;
// P = 53 if for both uppercase & lowercase
vector <ull> p_pow(SIZE);
vector <ull> h(SIZE);      //hash of prefixes

void init_pow() {
	p_pow[0] = 1;
	for (int i = 1; i < SIZE; i++)
		p_pow[i] = p_pow[i - 1] * P;
}
void hash_pre(string s) { //hash of prefixes
	for (int i = 0; i < s.length(); i++){
		h[i] = (s[i] - 'a' + 1) * p_pow[i];
		if (i) h[i] += h[i - 1];
	}
}
ull hash_s(string s) { //hash of a string
	ull h_s = 0;
	for (int i = 0; i < s.length(); i++)
		h_s += (s[i] - 'a' + 1) * p_pow[i];
	return h_s;
}
bool comp_substr(int l1, int l2, int r1, int r2) {
	//compares hashes of 2 substring in a string(0 based)

	ull h1 = h[r1];
	if (l1) h1 -= h[l1 - 1];
	ull h2 = h[r2];
	if (l2) h2 -= h[l2 - 1];

	// Get the two hashes multiplied by the same power of P
// and then compare them
	if (l1 <l2 && h1 * p_pow[l2 - l1] == h2 ||
		l1> l2 && h1 == h2 * p_pow[l1 - l2])
		return true;     // substrings are equal
	else
		return false;
}
int count_substr(int n) {
	// Count number of differetn substrings in a string
// n = length of string

	int result = 0;
	for (int l = 1; l <= n; l++) {
		// Need to find the number of distinct substrings of
// length l. Get the hashes for all substrs of length l

		vector <ull> hs(n - l + 1);
		for (int i = 0; i <n - l + 1; i++){
			ull cur_h = h[i + l - 1];
			if (i) cur_h -= h[i - 1];
			cur_h *= p_pow[n - i - 1];
			hs[i] = cur_h;
		}
		sort(hs.begin(), hs.end());
		hs.erase(unique(hs.begin(), hs.end()), hs.end());
		result += (int)hs.size();
	}
	return result;
}

vector<int> rabin_karp (string s, string t) {
	// s = pattern, t = text
	vector<int> res; //returns 0 based starting indexs of matches

init_pow();
	ull h_s = hash_s(s);
	hash_pre(t);

	for (int i = 0; i + s.length() - 1 < t.length(); i++){
		ull cur_h = h[i + s.length() - 1];
		if (i) cur_h -= h[i - 1];

		if (cur_h == h_s * p_pow[i])
			res.push_back(i);
	}
	return res;
}

int main()
{

}
