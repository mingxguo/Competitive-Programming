#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <fstream>

using namespace std;


#define EPS 1e-9
/*template <class T>
struct Point {
typedef Point P;
T x, y;
explicit Point(T x=0, T y=0) : x(x), y(y) {}
bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
P operator+(P p) const { return P(x+p.x, y+p.y); }
P operator-(P p) const { return P(x-p.x, y-p.y); }
P operator*(T d) const { return P(x*d, y*d); }
P operator/(T d) const { return P(x/d, y/d); }
T dot(P p) const { return x*p.x + y*p.y; }
T cross(P p) const { return x*p.y - y*p.x; }
T cross(P a, P b) const { return (a-*this).cross(b-*this); }
T dist2() const { return x*x + y*y; }
double dist() const { return sqrt((double)dist2()); }
// angle to x-axis in interval [-pi, pi]
double angle() const { return atan2(y, x); }
P unit() const { return *this/dist(); } // makes dist()=1
P perp() const { return P(-y, x); } // rotates +90 degrees
P normal() const { return perp().unit(); }
// returns point rotated ¡¯a¡¯ radians ccw around the origin
P rotate(double a) const {
return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
}*/

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	// to sort points lexicographically
	bool operator < (point other) const {
		if (abs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}
	bool operator != (const point other) const {
		return x != other.x || y != other.y;
	}
	bool operator ==(const point other) const {
		return !(*this != other);
	}

	void rotate(double a) {
		*this = point(x*cos(a) - y * sin(a), x*sin(a) + y * cos(a));
	}
};

struct vec {
	double x, y;
	vec() = default;
	vec(double _x, double _y) : x(_x), y(_y) { }
};




double sq(point p) { return p.x*p.x + p.y*p.y; }
vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) { return vec(v.x*s, v.y*s); }
point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }
double dot(vec a, vec b) { return a.x*b.x + a.y*b.y; }
double norm_sq(vec v) { return v.x*v.x + v.y*v.y; }
double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }
double distSq(point p1, point p2) {
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
double cross(point a, point b) { return a.x * b.y - a.y * b.x; }
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// para aceptar puntos colineales cambia a >=
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}
bool collinear(point p, point q, point r) {
	return abs(cross(toVec(p, q), toVec(p, r))) < EPS;
}
int insideCircle(point p, point c, double r) {
	double eucSq = distSq(p, c);
	double rSq = r * r;
	if (abs(eucSq - rSq) > EPS && eucSq < rSq) return 0; // inside
	else if (abs(eucSq - rSq) < EPS) return 1; // border
	else return 2; // outside
}

struct line {
	double a, b, c; // ax + by + c = 0
	bool operator== (const line &l2) {
		return (a == l2.a && b == l2.b && c == l2.c);
	}
};

bool areParallel(line l1, line l2) {
	return l1.a == l2.a && l1.b == l2.b;
}

line pointsToLine(point p, point q) {
	line l;
	if (p.x == q.x) {
		l.a = 1; l.b = 0; l.c = -p.x;
	}
	else {
		l.a = (q.y - p.y) / (p.x - q.x);
		l.b = 1;
		l.c = -(l.a * p.x) - p.y;
	}
	return l;
}
struct segment {
	point p;
	vec r;
	segment() { }
	segment(point a, point b) {
		p = a;
		r = toVec(a, b);
	}
};
bool eq(double a, double b) { return abs(a - b) < EPS; }
bool lt(double a, double b) { return a - b < EPS; }
bool leq(double a, double b) { return eq(a, b) || lt(a, b); }

bool intersect(segment a, segment b, point &x, bool &collinear) {
	vec r = a.r, s = b.r;
	point p = a.p, q = b.p;
	vec pq = toVec(p, q);
	double pqxr = cross(pq, r), rxs = cross(r, s);
	bool parallel = eq(rxs, 0);
	collinear = parallel && eq(pqxr, 0);
	if (collinear) {
		double t0 = dot(pq, r) / dot(r, r);
		double t1 = t0 + dot(s, r) / dot(r, r);
		if (lt(dot(s, r), 0)) swap(t0, t1);
		return leq(max(t0, 0.0), min(t1, 1.0));
	}
	else if (parallel) return false;
	else {
		double t = cross(pq, s) / cross(r, s), u = cross(pq, r) / cross(r, s);
		x = translate(p, scale(r, t));
		return leq(0, t) && leq(t, 1) && leq(0, u) && leq(u, 1);
	}
}


int n, r;

// devuelve un pol¨ªgono con la envolvente convexa de la nube de puntos P
vector<point> convexHull(vector<point> & P) {
	int n = int(P.size()), k = 0;
	vector<point> H(2 * n);
	sort(P.begin(), P.end());
	// build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	}
	// build upper hull
	for (int i = n - 2, t = k + 1; i >= 0; --i) {
		while (k >= t && !ccw(H[k - 2], H[k - 1], P[i])) --k;
		H[k++] = P[i];
	}
	H.resize(k);
	return H;
}

double distToLine(point a, point b, point p) {
	vec v = toVec(a, b);
	double c = cross(v, toVec(point(0, 0), a));
	double side = cross(v, toVec(point(0, 0), p)) - c;
	return abs(side) / sqrt(norm_sq(v));
}

double resolve(vector<point> const& v) {
	if (v.size() <= 2) return 0;
	double res = 1e+80;
	int i = 0, j = 0;
	while(i < v.size()-1){
		vec base = toVec(v[i], v[i + 1]);
		while ((cross(base, toVec(v[i], v[j + 1])) >= cross(base, toVec(v[i], v[j])))) {
			j = (j + 1) % (v.size() - 1);
		}
		double dist = distToLine(v[i], v[i + 1], v[j]);
		res = min(res, dist);
		++i;
	}
	return res;
}

int main() {

	//ifstream in("datos.txt"); auto cinbuf = std::cin.rdbuf(in.rdbuf());
	//ofstream out("out.txt"); auto coutbuf = std::cout.rdbuf(out.rdbuf());
	while (cin >> n >> r) {
		vector<point> p(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			p[i] = point(x, y);
		}
		vector<point> v = convexHull(p);
		double sol = resolve(v);
		cout << fixed << setprecision(6) << sol << '\n';
	}
	return 0;
}