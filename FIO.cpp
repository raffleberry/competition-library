int read() {
    bool neg = false;
    int x = 0; char ch = getchar_unlocked();
    while(ch < '0' || ch > '9') { if(ch == '-') neg = true; ch = getchar_unlocked(); }
    while(ch >= '0' && ch <= '9') { x = x*10+ch-48; ch = getchar_unlocked(); }
    if(neg) return -x;
    return x;
}

void write(int x) {
    if(x < 0) { x = -x; putchar_unlocked('-'); }
    if(x > 9) write(x/10);
    putchar_unlocked(x%10+48);
}

template<typename T = int>
inline T read() {
    T val = 0, sign = 1; char ch;
    for (ch = getchar_unlocked(); ch < '0' || ch > '9'; ch = getchar_unlocked())
        if (ch == '-') sign = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar_unlocked())
        val = val * 10 + ch - '0';
    return sign * val;
}

template<typename T = int>
inline write(T x) {
    if(x < 0) { x = -x; putchar_unlocked('-'); }
    if(x > 9) write(x / 10);
    putchar_unlocked(x%10 + 48);
}

