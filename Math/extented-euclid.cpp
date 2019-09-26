/*
 * 
 */

int egcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, x2;
    int d = egcd(b % a, a, x1, x2);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}

int modinv(int a, int m) {
    int x, y;
    int g = egcd(a, m, x, y);
    if (g != 1) {
        cerr << "No solution!";
        return -1;
    }
    return (x % m + m) % m;
}
