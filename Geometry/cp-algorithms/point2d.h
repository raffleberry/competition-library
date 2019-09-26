using ptype = double;

struct p2d {
    ptype x, y;
    p2d() {};
    p2d(ptype x, ptype y) : x(x), y(y) {}
    p2d operator += (const p2d &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    p2d operator -= (const p2d &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;        
    }
    p2d operator *= (ptype var) {
        x *= var;
        y *= var;
        return *this;
    }
};

ptype dot(p2d a, p2d b) {
    return a.x * b.x + a.y * b.y;
}
ptype norm(p2d a) {
    return dot(a, a);
}
double abs(p2d a) {
    return sqrt(norm(a));
}
double proj(p2d a, p2d b) {
    return dot(a, b) / abs(b);
}
double angle(p2d a, p2d b) {
    return acos(dot(a, b) / abs(a)/ abs(b));
}
ptype cross(p2d a, p2d b) {
    return a.x*b.y - a.y*b.x;
}
