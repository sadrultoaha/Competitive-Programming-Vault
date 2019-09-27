#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

/****** Type Define *********/

    typedef long long ll;
    typedef unsigned long long ull;

/****** STL Commands *********/

    #define pb              push_back
    #define pob             pop_back
    #define mkpr            make_pair
    #define mem(a,b)          memset(a,b,sizeof(a))
    #define all(x)          x.begin(), x.end()
    #define rall(x)         x.end(), x.begin()

/****** Constants *********/

    #define gold ((1+sqrt(5))/2)
    #define pi              acos(-1.0)
    #define eps             1e-9
    #define inf             2e18
    #define mod 1000000007
    #define mx 1000000

/****** Operations *********/
    #define read freopen("IN.txt","r",stdin)
    #define write freopen("OT.txt","w",stdout)

    #define on(n,pos) (n  (1LL<<(pos)))
    #define off(n,pos)  n & ~(1LL<<pos)
    #define ison(n,pos) (bool)(n & (1LL<<(pos)))

    #define scni(x)         scanf("%d",&x)
    #define scnll(x)        scanf("%lld",&x)
    #define scnd(x)         scanf("%lf",&x)
    #define scn64(x)        scanf("%I64"&x)

    #define prni(x)         printf("%d",x);
    #define prnll(x)        printf("%lld",x);
    #define prnd(x)         printf("%lf",x);
    #define prn64(x)        printf("%I64",x);
    #define fastread() {ios_base::sync_with_stdio(false);cin.tie(0);}
    /// scanf ("%[^\n]%*c", str); /// get string with space
    // getline (cin, str); // gets string with space but has some issue with many test case

    /** convert string into number -->
         stringstream geek(token);
         int tm = -1;
         geek >> tm;
    **/
    /** takes string input except delimiter

    string delimiter1 = "{";
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter1))!= string::npos)
        {
         token = str.substr(0, pos);
         str.erase(0,pos + 1);
         stringstream geek(token);
         int tm = -1;
         geek >> tm;
        if(tm!=-1){cout<<tm<<" ";}
        }
    **/




/**   NOTES

    A.MEMSET:
        1. If We Memset an Array with -1/0 the Array will be assigned with -1/0 from idx (0-n), but if we Memset it with " >0 / <-1 " it will be assigned with INF value from idx (0-n)
        BUT negative idx will be always 0 [ Caution negative idx always gives Run Time Error.]
        2.If we Memset Array with " >0 / <-1 then for doing array[i] comparison we must initialize the array[0]=0;

**/

/******************************************* END ******************************************/

#define dbg(args...) {cerr<<"-->";debugger::call(#args,args);cerr<<"\n";}
struct debugger {
    static void call(const char* it) {}
    template<typename T, typename ... aT>
    static void call(const char* it, T a, aT... rest) {
        string b;
        for (; *it&&*it != ','; ++it) if (*it != ' ')b += *it;
        cerr << b << "=" << a << " ";
        call(++it, rest...);
    }
};


int main()
{
#ifndef ONLINE_JUDGE
    /// 1. Formulate Question
    /// 2. Gather Information
    /// 3. Apply The Information
    /// 4. Consider The Implication
    /// 5. Explore other points of view
        //IN;
        //OUT;
        double start_time = clock();
        /// A.Always Think Easiest Way.
        /// B.Try To Guess Setter's View
        /// C.If got stuck or twisted skip and restart Later
        /// D.Use all known things and Find Out at least 2 or 3 way.

#endif



#ifndef ONLINE_JUDGE
    double end_time = clock();
    //cout<<"Time : "<<(end_time - start_time)/ CLOCKS_PER_SEC;
#endif

return 0;
}



    /// scanf ("%[^\n]%*c", str); /// get string with space
    // getline (cin, str); // gets string with space but has some issue with many test case

    /** convert string into number -->
         1.
         stringstream geek(token);
         int tm = -1;
         geek >> tm;

    **/
    /** convert int to string -->
         1.
         str= to_string(num);
    **/
    /** takes string input except delimiter

    string delimiter1 = "{";
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter1))!= string::npos)
        {
         token = str.substr(0, pos);
         str.erase(0,pos + 1);
         stringstream geek(token);
         int tm = -1;
         geek >> tm;
        if(tm!=-1){cout<<tm<<" ";}
        }
    **/




/**   NOTES

    A.MEMSET:
        1. If We Memset an Array with -1/0 the Array will be assigned with -1/0 from idx (0-n), but if we Memset it with " >0 / <-1 " it will be assigned with INF value from idx (0-n)
        BUT negative idx will be always 0 [ Caution negative idx always gives Run Time Error.]
        2.If we Memset Array with " >0 / <-1 then for doing array[i] comparison we must initialize the array[0]=0;

        3.DIGITAL ROOT = is the single digit value obtained by an iterative process of summing digits, on each iteration using the result from the previous iteration to compute a digit sum. The process continues until a single-digit number is reached.
          i.e - S(38)=S(3+8=11)=S(1+1=2)=2; so digital root of 38 is 2;
          and 38 is 5th value for root 2;

          * Rule = every Kth value of any number x is = ans=x; while(i<k)ans+=9;
**/

/** Large Factorial Calculator
#define MAX 500

int multiply(int x, int res[], int res_size);

void factorial(int n)
{
    int res[MAX];

    res[0] = 1;
    int res_size = 1;

    for (int x=2; x<=n; x++)
    {
        res_size = multiply(x, res, res_size);
    }

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;

    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod/10;
    }

    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

**/

/******************************************* END ******************************************/



/****** Template Functions *********/

    LL power(LL a, LL n) {LL p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
    LL power(LL a, LL n, LL mod) {LL p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
    /****** Template of some basic operations *****/
    inline int two(int n) { return 1 << n; }
    inline int test(int n, int b) { return (n>>b)&1; }
    inline void set_bit(int & n, int b) { n |= two(b); }
    inline void unset_bit(int & n, int b) { n &= ~two(b); }
    inline int last_bit(int n) { return n & (-n); }
    inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
    template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
    template<class T> void chmin(T & a, const T & b) { a = min(a, b); }

    template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
    template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }


    string toBin(int n){ string s; repv(i,10)s+=(ison(n,i)+'0');return s;}

    bool eq(long double a,long double b){return fabs(a-b)<eps;}

    double log(double N,double B){  return (log10l(N))/(log10l(B)); }

    vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
        oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
        b.end(), *q ) ) q++;}return oot;
    }
    template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
    template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}


    int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}



    double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
    template<typename T> void inpos(T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=0;\
    if(c=='-')neg=1;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}
    template<typename T> void outpos(T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do{snum[i++]=n%10+'0';n/=10;}\
    while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}
    inline void instr(char *str){register char c=0;register int i=0;while(c<33)c=inchar();while(c!='\n'&&c!=' '&&c!=EOF){\
    str[i]=c;c=inchar();++i;}str[i]='\0';}
    template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
    template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
    int add(int a, int b, int c){int res=a+b;return(res>=c?res-c:res);}
    int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
    int mul(int a, int b, int c){LL res=(LL)a*b;return(res>=c?res%c:res);}
    LL mulmod(LL a,LL b, LL m){LL q = (LL)(((LD)a*(LD)b)/(LD)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
    template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
    template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
    template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
    t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
    template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}




    /****** Template of Fast I/O Methods *********/
    template <typename T> inline void write(T x)
    {
        int i = 20;
        char buf[21];
        buf[20] = '\n';

        do
        {
            buf[--i] = x % 10 + '0';
            x/= 10;
        }while(x);
        do
        {
            putchar(buf[i]);
        } while (buf[i++] != '\n');
    }

    template <typename T> inline T readInt()
    {
        T n=0,s=1;
        char p=getchar();
        if(p=='-')
            s=-1;
        while((p<'0'||p>'9')&&p!=EOF&&p!='-')
            p=getchar();
        if(p=='-')
            s=-1,p=getchar();
        while(p>='0'&&p<='9') {
            n = (n<< 3) + (n<< 1) + (p - '0');
            p=getchar();
        }

        return n*s;
    }


    /******* Debugging Class Template *******/
    #define DEBUG

    #ifdef DEBUG

    #define debug(args...)     (Debugger()) , args

        class Debugger
        {
            public:
            Debugger(const std::string& _separator = " - ") :
            first(true), separator(_separator){}

            template<typename ObjectType> Debugger& operator , (const ObjectType& v)
            {
                if(!first)
                    std:cerr << separator;
                std::cerr << v;
                first = false;
                return *this;
            }
            ~Debugger() {  std:cerr << endl;}

            private:
            bool first;
            std::string separator;
        };

    #else
        #define debug(args...)                  // Just strip off all debug tokens
    #endif


/******** User-defined Function *******/



        /*********************************Debug DEFINE  ********************************/
        #define TESTING
        //#define FILE_INPUT
        //#define FILE_OUTPUT
        /*********************************END of Debug DEFINE  ********************************/

        #ifdef TESTING
          #define VALUE(x) cout << ">>>> The value of " << #x << " is " << x << "<<<<" << endl
          #define NEWLINE cout << "---------------------------------------------" << endl
          #define DUMP_STR cout << ">>>>FANGO IS THE MOST HANDSOME MANKIND IN THE ENTIRE WORLD<<<<" << endl;
          #define DUMP_CHAR cout << " YO ";
        #endif //TESTING_ON_CONSOLE

        #ifdef FILE_INPUT
            freopen("input.in", "r", stdin);
        #endif // TESTING_WITH_FILE_ONLY

        #ifdef FILE_OUTPUT
            freopen("output.out", "w", stdout);
        #endif // FILE_INPUT_AND_OUTPUT



        template <class T>
            T sqr(T val) {
                return val * val;
            }


        void input() {
        }

        void solve() {
        }

    void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
    void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
    ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;
      if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}
    #define SIZE 1000001
    void preprocess()
    {
    }//end prepreprocess
    void refresh()
    {
    }//end refresh
    void compute()
    {
    }//end compute














template <typename T> inline T ItoS(T n){SS a; a<<n;return a.str();}
template <typename T> inline T TrailingZeros(T  n){ll cnt = 0;for(ll i=5; n/i>=1; i*=5) cnt += n/i;return cnt;}
template <typename T> inline T StoI(T s){ll sum=0;for(ll i=0; i<Sz(s); i++){s[i]-='0';sum=sum*10+s[i];}return sum;}
template <typename T> inline T binary_decimal(T n){ll decimal=0, i=0, rem;while (n!=0){rem = n%10;n/=10;decimal += rem*pow(2,i);++i;}return decimal;}
template <typename T> inline T LCM(T a,T b){return (a*b)/GCD(a,b);}
template <typename T> inline T maxi(T x, T y) { if(x>y) return x; else return y;}
template <typename T> inline T maxi(T x, T y,T z) { return maxi(maxi(x,y),z);}
template <typename T> inline T mini(T x, T y) { if(x<y) return x; else return y;}
template <typename T> inline T mini(T x, T y,T z) { return mini(mini(x,y),z);}
template <typename T> inline T GCD(T a,T b)   {ll t;while(a){t = a;a = b%a;b = t;}return b;}
template <typename T> inline T Pow(T base,T exp){ll result = 1;while (exp){if(exp&1)result*=base;exp>>=1;base*=base;}return result;}
template <typename T> inline T Mulmod(T a, T b, T c){ull x = 0,y = a%c;while(b>0){if(b&1) x = (x+y)%c;y = (y<<1)%c;b >>= 1;}return x;}
template <typename T> inline T Pow(T base,T exp,T mod){ull x = 1, y = base;while(exp>0){if(exp&1) x = Mulmod(x,y,mod);y = Mulmod(y,y,mod);exp >>= 1;}return x;}
template <typename T> inline T modulo(T a,T b,T c){ull x = 1 , y = a%c ;while( b>0 ){if(b%2) x = Mulmod(x,y,c) ;y=Mulmod(y,y,c);b/=2;}return x%c ;}
template <typename T> inline T BigMod(T a, T b, T m){if(!b)return 1;ll x=BigMod(a, b/2, m);x=(x*x)%m;if(b%2)x=(x*a)%m;return x;}
template <typename T> inline T EGCD(T a,T b,T &x,T &y){if(a == 0) {x = 0;y = 1;return b;}T x1, y1;T d = EGCD(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}

/****************** Prime Generator **********************/

const int N=1e7+10; int prime[20000010]; bool isprime[N]; int nprime;
template <typename T> void Sieve(T a) {nprime = 0;memset(isprime,true,sizeof(isprime));isprime[1]=false;for(int i=2;i<N;i++){if(isprime[i]){prime[nprime++]=i;for(int j=2;i*j<N;j++)isprime[i*j]=false;}}}
template <typename T> bool miller_rabin(T p, T itt) {if(p<2) return 0 ;if(p==2) return 1;if(p%2==0) return 0 ;ull s = p-1 ;while(s%2==0) s/=2;for(ll i=1;i<=itt;i++) {ull a = rand() % (p-1)+1 , temp = s ;ull mod = modulo(a,temp,(ull)p);while(mod!=1 and mod!=p-1 and temp!=p-1){mod = Mulmod(mod,mod,(ull)p);temp*=2;}if(temp%2==0 and mod!=p-1) return false ;}return true;}
template <typename T> inline T PrimeFactors(T n){ll cnt=0,sum=1;for(int i=0; prime[i]*prime[i]<=n and i<nprime;i++){cnt=0;while(n%prime[i]==0){cnt++;n/=prime[i];}sum*=(cnt+1);}if(n>1)sum*=2;return sum;}

/********************** Faster I/O *********************/

template <typename T> inline T scan(T &n) { n=0; bool negative=0; char c=gc(); while(c<'0'||c>'9') {if(c=='-') negative=1; c=gc();} while(c>='0'&&c<='9'){n=n*10+c-48;c=gc();} if(negative) n=~(n-1);}
template <typename T> inline T scan(T a,T b){scan(a);scan(b);}
template <typename T> inline T scan(T a,T b,T c){scan(a);scan(b);scan(c);}
template <typename T> inline T scan(T a,T b,T c,T d){scan(a);scan(b);scan(c);scan(d);}
template <typename T> void print(T n){if(n<0){pc('-');n=-n;}if(!n){pc('0');pc('\n');return;}char buff[12];int len=0;while(n) buff[len++]=n%10+48,n/=10;for(int i=len-1;i>=0;i--) pc(buff[i]);pc('\n');}
template <typename T> void print(T a, T b){print(a);print(b);}
template <typename T> void print(T a, T b, T c){print(a);print(b);print(c);}
template <typename T> void Print(T n){if(n<0){pc('-');n=-n;}if(!n){pc('0');return;}char buff[12];int len=0;while(n) buff[len++]=n%10+48,n/=10;for(int i=len-1;i>=0;i--) pc(buff[i]);}

/****************** Geometry *****************/

template <typename T> inline T PointDistanceHorVer(T x1,T y1,T x2, T y2) {return abs(x1-x2)+abs(y1-y2);}
template <typename T> inline T PointDistanceDiagonally(T x1,T y1,T x2, T y2) {return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));}
template <typename T> inline T PointDistanceMinimum(T x1,T y1,T x2, T y2) { T tmp1=abs(x1-x2); T tmp2=abs(y1-y2); T tmp3=abs(tmp1-tmp2); T tmp4=min(tmp1, tmp2); return tmp3+tmp4; }
template <typename T> inline T PointDistance3D(T x1,T y1,T z1,T x2,T y2,T z2) {return sqrt(square(x2-x1)+square(y2-y1)+square(z2-z1));}

template <typename T> inline T Cube(T a){return a*a*a;}
template <typename T> inline T RectengularPrism(T a,T b,T c){return a*b*c;}
template <typename T> inline T Pyramid(T base, T height){return (1/3)*base*height;}
template <typename T> inline T Ellipsoid(T r1,T r2,T r3) {return (4/3)*PI*r1*r2*r3;}
template <typename T> inline T IrregualarPrism(T base, T height){return base*height;}
template <typename T> inline T Sphere(T radius){ return (4/3)*PI*radius*radius*radius;}
template <typename T> inline T CylinderB(T base, T height){return base*height;} // base and height
template <typename T> inline T CylinderR(T radius, T height){return PI*radius*radius*height;} // radius and height
template <typename T> inline T Cone (T radius,T base, T height){return (1/3)*PI*radius*radius*height;}

///**>>>>>>>>>>>>>>>>>>> END <<<<<<<<<<<<<<<<<<**/
