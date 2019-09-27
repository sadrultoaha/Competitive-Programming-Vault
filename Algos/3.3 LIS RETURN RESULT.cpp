/// OK but Don't know what it is about !!

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

vector<int> LISResult(vector<int> input) {

	vector<int>L(input.size());
	vector<int>L_id(input.size());
	vector<int>P(input.size());
	vector<int>output;
	int lis = 0, lis_end = 0, i;
	for (i = 0; i < input.size(); ++i) {
		int pos = lower_bound(L.begin(), L.begin() + lis,
        input[i]) - L.begin();
        //use upper_bound for non decreasing
		L[pos] = input[i];
		L_id[pos] = i;
		P[i] = pos ? L_id[pos - 1] : -1;
		if (pos + 1 > lis) {
			lis = pos + 1; lis_end = i;
		}
	}
	i = lis_end;
	for (; P[i] >= 0; i = P[i]) output.push_back(input[i]);
	output.push_back(input[i]);
	reverse(output.begin(), output.end());
	return output;
}
int main()
{
    vector<int> in;
    vector<int> out;
    in.push_back(50);
    in.push_back(3);
    in.push_back(10);
    in.push_back(7);
    in.push_back(40);
    in.push_back(80);

    out=LISResult(in);
    for(int j=0;j<out.size();j++)
    {
        printf("LISResult is %d\n",out.at(j));
    }

}
