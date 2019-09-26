using ptype = double;

struct p3d {
    ptype x, y, z;
    p3d() {};
    p3d(ptype x, ptype y, ptype z) : x(x), y(y), z(z) {}
    p3d operator += (const p3d &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    p3d operator -= (const p3d &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;        
    }
    p3d operator *= (ptype var) {
        x *= var;
        y *= var;
        z *= var;
        return *this;
    }
};

ptype dot(p3d a, p2d b) {
    return a.x*b.x + a.y*b.y + c.z*c.z;
}

ptype norm(p3d a) {
    return dot(a, a);
}

ptype abs(p3d a) {
    return sqrt(norm(a));
}

ptype proj(p3d a, p3d b) {
    return dot(a, b) / abs(b);
}

ptype ang(p3d a, p3d b) {
    return dot(a, b) / abs(a) / abs(b);
}

p3d cross(p3d a, p3d b) {
    return p3d(a.y*b.z - a.z*b.y,
               a.z*b.x - a.x*b.z,
               a.x*b.y - a.y*b.x);
}

ptype triple(p3d a, p3d b, p3d c) {
    return dot(a, cross(b, c));
}
