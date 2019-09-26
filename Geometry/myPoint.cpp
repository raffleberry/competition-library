typedef double T;

//required
bool equal(T a, T b) {
    if (abs(a-b)<=1e9) return 1;
    return 0;
}

struct pt {
    T x, y;
    pt operator+(pt p) { return {x+p.x, y+p.y}; }
    pt operator-(pt p) { return {x-p.x, y-p.y}; }
    pt operator*(T d) { return {x*d, y*d}; }
    pt operator/(T d) { return {x/d, y/d}; }
};

T sq(pt p) { return p.x*p.x + p.y*p.y; };
double abs(pt p) { return sqrt(sq(p)); }

bool operator==(pt a, pt b) { return equal(a.x, b.x) && equal(a.y, b.y); }
bool operator!=(pt a, pt b) { return !(a == b); }

ostream& operator<<(ostream& os, pt p) { return os << "("<< p.x << "," << p.y << ")"; }

//transformations
pt translate(pt v, pt p) { return p+v; }
pt scale(pt c, double factor, pt p) { return c + (p-c)*factor; }
pt scale(pt p, double r) { return {p.x*cos(r) - p.y*sin(r), p.x*sin(r) + p.y*cos(r)}; }
pt perp(pt p) { return {-p.y, p.x}; }

//products
T dot(pt a, pt b) { return a.x*b.x + a.y*b.y; }
bool isPerp(pt a, pt b) { return equal(dot(a, b), 0.0); }
double angle(pt a, pt b) {
    double cosTheta = dot(a, b)/abs(a)/abs(b);
    return acos(max(min(cosTheta, 1.0), -1.0);//[0, pi]
}

