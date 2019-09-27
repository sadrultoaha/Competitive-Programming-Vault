///OK chkd by SunW

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


const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = 3.141592653589793;
const double E = 2.718281828459045;

/** -------------------END TEMPLATE------------------------------------ **/

vector <int> v;
int primes[]={2,3,5,7,11,13,17,19}; /// ADDED by SunW
void primeFactors(int n) { //Ex. When n = 12, v[] = {2,2,3}
	for (int i = 0; primes[i]*primes[i] <= n; i++){
    int x = primes[i];
		while (n%x == 0) { v.push_back(x); n = n/x; }
	}
	if (n>=2)v.push_back(n);
}
int noOfDivisors(int n){ //When n = 12, returns 6
	int c = 0, ans = 1;
	for (int i = 0; primes[i] <= sqrt(n); i++){
c = 0; int x = primes[i];
		while (n%x == 0) { c++; n = n / x; }
if (c>0) ans *= (c + 1);
	}
	if (n>=2) ans *= 2;
	return ans;
}

vector <int> divisors;
void allDivisors(int n) { //all divisors for small n
	divisors.clear();
	int i;
	for (i = 1; i < sqrt(n); i++) {
		if (n%i == 0) {
			divisors.push_back(i);
			divisors.push_back(n/i);
		}
	}
	if (i*i == n) divisors.push_back(i);
}

vector <pii> factors;
// When n = 12, factors[] = {(2,2), (3,1)}
void primeFactorsPair(int n) {
	int c = 0;
	for (int i = 0; primes[i] <= sqrt(n); i++) {
		c = 0;
		int x = primes[i];
		while (n%x == 0) { c++; n = n / x; }

		if (c>0) factors.push_back(make_pair(x, c));
	}
	if (n >= 2) factors.push_back(make_pair(n, 1));
}
//call primeFactorsPair with n(12)
//call allDivisors with (1, 0), divisors[] = {2,6,4,12,3}
//also needs sieve()
void allDivisors(int n, int i) {
int j, x, k;
	for (j = i; j<factors.size(); j++) {
		x = factors[j].first * n;
		for (k = 0; k<factors[j].second; k++) {
			divisors.push_back(x);
			allDivisors(x, j + 1);
			x *= factors[j].first;
}
}
}
///Divisors of numbers from 1 to N
/* When MAX  = 500007 it takes about 600ms/51MB in codeforces
MAX = 10^6 takes 1.4s in uva*/
#define MAX 500007
vector<int> divisorz[MAX + 1];
void divisors_1_to_n(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i)
			divisorz[j].push_back(i);
			// divisors[j]+=i for Sum of divisors
			// divisors[j]++ for Number of divisors
	}
}
int main()
{
   cout<<"no Of Divisors: "<<noOfDivisors(12)<<endl;
    primeFactors(12);
    cout<<"Prime primeFactors: ";
    int i=0;
   while(v.size()>i)
  {
    cout<<v.at(i)<<",";
    i++;
  }
/    allDivisors(12);
/    cout<<" allDivisors: ";
/
/   int j=0;
/   while(divisors.size()>j)
/  {
/    cout<<divisors.at(j)<<",";
/    j++;
/  }

}
