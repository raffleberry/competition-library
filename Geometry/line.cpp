
struct line {
  int a, b, c;
  line() {}
  line(int x1, int y1, int x2, int y2) {
    a = y1 - y2;
    b = x2 - x1;
    c = -(a * x1 + b * y1);
  }
  void norm() {
    if (a < 0 || b < 0) {
      a *= -1;
      b *= -1;
      c *= -1;
    }
    int g = __gcd(__gcd(abs(a), abs(b)), abs(c));
    a /= g;
    b /= g;
    c /= g;
  }
}
