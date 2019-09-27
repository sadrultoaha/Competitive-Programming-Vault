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

/** FOR GEOMETRY **/

/// 5.2 Structures --->

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator <(const point & p) const {
		return ((x < p.x) || (abs(x - p.x) < EPS &&
			(y < p.y)));
	}
	point operator-(point v) { return point(x - v.x, y - v.y); }
	point operator+(point v) { return point(x + v.x, y + v.y); }
};
struct line{ double a, b, c; };

struct vec {
       double x, y;
       vec( double _x, double _y) : x( _x), y( _y) {}
};

/// 5.3 Point --->

/// 1. Distance of 2 points
double dist(point p1, point p2) {
        return hypot(p1.x - p2.x, p1.y - p2.y); }
/// 2. Degree to radian
double DEGtoRAD(double theta){
        return (theta * ( PI / 180.0)); }
/// 3. Rotate p by theta degrees CCW w.r.t origin (0, 0)
point ROTATE(point p, double theta) {
        double rad = DEGtoRAD(theta);
        return point( p.x * cos(rad) - p.y * sin(rad),
              p.x * sin(rad) + p.y * cos(rad));
}
/// 4. Rotate a point angle radian about center, CCW
point rotatep(point a , point center , double angle ){
       point p;
       double x1 = a.x - center.x;
       double y1 = a.y - center.y;
       double x2 = x1 * cos( angle) - y1 * sin( angle);
       double y2 = x1 * sin( angle) + y1 * cos( angle);
       p.x = x2 + center.x;
       p.y = y2 + center.y;
       return p; }

/// 5.4 Vectors --->

/// 5
vec toVec(point a , point b ) { return vec( b.x - a.x, b.y - a.y); }
/// 6
vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }
/// 7
point translate(point p, vec v) { return point(p.x+v.x, p.y+v.y); }
/// 8
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
/// 8
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
/// 10
double len(point a ) { return sqrt(a.x*a.x + a.y*a.y); }
/// 11
double dot2(point a , point b ) { return a.x*b.x + a.y*b.y; }
/// 12
double cross(point a , point b ) { return a.x * b.y - a.y * b.x; }

/// 5.5 Point and Line  --->

/// 13. Is distance ab = ar + rb ?
bool onLine(point a , point b , point r ){
        if (fabs(dist( a, b) - (dist( a, r)
+ dist( b, r))) < EPS) return true;
        return false;
}
/// 14. Is point b on line x?
bool onLineL(line x , point b ){
if ( fabs(( x.a * b.x + x.b * b.y) + x.c) < EPS)
return true;
return false;
}
/// 15. Find a point p which is on line ab and ap = d
point pointAtDist(point a , point b , double d ){
point p;
     double _d = dist( a, b);
     p.x = ( a.x + ( b.x - a.x)*( d/_d) );
     p.x = ( a.y + ( b.y - a.y)*( d/_d) );
     return p;
}
/// 16. Distance of AB to C (When point on AB is not needed)
double linePointDist1
(point A, point B, point C, bool isSegment) {
	double dis = cross(B - A, C - A) / len(B - A);
	if (isSegment) {
		if (dot2(C - B, B - A) > EPS)
			return len(B - C);
		if (dot2(C - A, A - B) > EPS)
			return len(A - C);
	}
	return fabs(dis);
}
/// 17. Distance ab to p. Closest point saved in c
double linePointDist2(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}
/** 18. Distance of p to ab(Segment). Closest point saved in c
double linePointDist3(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = point(b.x, b.y);
		return dist(p, b); }
	return distToLine(p, a, b, c); /// Have Some Problem !! maybe it should be "return linePointDist2(p,a,b,c);" chkd by SunW
} **/

/// 19.
double linePointDist4(line l, point p) {
	return fabs(p.x * l.a + p.y * l.b - l.c) /
		sqrt(l.a* l.a + l.b* l.b);
}

/// 5.7 Lines  --->

/// 20.
line toLine(point p1 , point p2 ) {
       line x;
       x.a = p1.y - p2.y; x.b = p2.x - p1.x;
       x.c = -(x.a * p1.x + x.b* p1.y);
  return x;
}
/// 21. l1 parallel of l2?
bool parallel(line l1, line l2) {
	return (fabs(l1.a * l2.b - l2.a * l1.b) < EPS); }

/// 22. line l1 == l2?
bool sameLine(line l1, line l2) {
	return (fabs(l1.a * l2.b - l1.b * l2.a) < EPS &&
fabs(l1.b * l2.c - l1.c * l2.b)<EPS);  }
/// 23. Intersect of 2 lines(return false if there is no intersect)
bool lineIntersect1 (line l1 , line l2 , point &p ) {
        double a = l1.a * l2.b - l2.a * l1.b;
        if (fabs(a) < EPS) return false;
        double b = l1.b * l2.c - l2.b * l1.c;
        double c = l1.c * l2.a - l2.c * l1.a;
        p.x = b / a;  p.y = c / a;  return true;
}

/// 24. Intersect of 2 line segments (return false if there is no intersect)
bool lineIntersect2(point a, point b, point x, point y, point &m) {
line l1 = toLine(a, b), l2 = toLine(x, y);
	if (sameLine(l1, l2)){
//Check what’s said about same lines
		if (onLine(a, b, x) || onLine(a, b, y) ||
onLine(x, y, a) || onLine(x, y, b))
return true;
		return false;
	}
	if ( lineIntersect1 (l1, l2, m)){
		if (onLine(a, b, m) && onLine(x, y, m))
return true;
	}
	return false;
}
/// 25.
double cross3(point p1, point p2, point p){
return (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) *(p.x - p1.x);
}
/// 26. Checks if 2 line segment intersect, returns false if segments touch
bool lineIntersect3(point p1, point p2, point q1, point q2){
return cross3(p1, p2, q1) * cross3(p1, p2, q2) < 0 &&
cross3(q1, q2, p1) * cross3(q1, q2, p2) < 0;
}

/// 5.8 Triangle -->

///27.
double angle(point a, point o, point b) {
	double ang = (fabs(atan2(a.y - o.y, a.x - o.x) -
		atan2(b.y - o.y, b.x - o.x)) * 180) / PI;
	//if (ang > 180.0)return(360.0 - ang);
return ang; }

///28. Semi perimeter
double s_perm(double a, double b, double c){
	return (a + b + c) / 2; }
///29.
double tarea1(double h, double b){
	return h*b*0.5; }
///30. Given length of all sides
double tarea2(double ab, double bc, double ca){
	double s = (ab + bc + ca) / 2;;
	return sqrt(s*(s-ab)*(s-bc)*(s-ca));
}
///31.
double tarea3(point a , point b , point c ) {
      return fabs(.5 * ( a.x * ( b.y - c.y) + b.x * ( c.y - a.y) + c.x *
 		( a.y - b.y))); }


/// 5.9 Circle --->

///32. Radius of Incircle = Area / semi-perimeter
double rInCircle(double ab, double bc, double ca) {
	return tarea2(ab, bc, ca) / s_perm(ab, bc, ca);
}

///33.
double rInCircleP(point a, point b, point c) {
	return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

///34. Radius of circumscribed circle = R = a × b × c/(4 × A).
double rCircumCircle(double ab, double bc, double ca) {
	return ab * bc * ca / (4.0 * tarea2(ab, bc, ca));
}

///35.
double rCircumCircleP(point a, point b, point c) {
	return rCircumCircle(dist(a, b), dist(b, c),
dist(c, a));
}



/** -------------------END TEMPLATE------------------------------------ **/

int main()
{
point ax,bx;
ax.x=1;ax.y=1;
bx.x=1;bx.y=5;
    cout<<dist(ax,bx)<<endl;

}
